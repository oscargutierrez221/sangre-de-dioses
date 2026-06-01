#include "obstaculo.h"
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>

obstaculo::obstaculo()
{
    dureza = 1;
    tamanio = 60;
    velocidad_movimiento = 3.5;

    subiendo = false;
    subiendo_inicial = false;
    y_min = 130.0;
    y_max = 520.0;
    pos_y_actual = 0;
    pos_y_inicial = 0;

    explotando = false;
    explosion_terminada = false;
    timer_explosion = new QTimer();
}

void obstaculo::mover()
{
    // si esta explotando no se mueve
    if(explotando){
        return;
    }

    if (subiendo){
        pos_y_actual -= velocidad_movimiento;
    }
    else {
        pos_y_actual += velocidad_movimiento;
    }

    if (pos_y_actual <= y_min) {
        pos_y_actual = y_min;
        subiendo = false;
    }
    if (pos_y_actual >= y_max) {
        pos_y_actual = y_max;
        subiendo = true;
    }

    setPos(x(), pos_y_actual);

}

void obstaculo::colocar(float x, float y)
{
    pos_x_inicial = x;
    setPos(x, y);
    pos_y_inicial = y;
    pos_y_actual = y;
}

void obstaculo::configurar_movimiento(bool hacia_arriba, float velocidad)
{
    subiendo_inicial = hacia_arriba;
    subiendo = hacia_arriba;
    velocidad_movimiento = velocidad;
}

void obstaculo::reiniciar()
{
    timer_explosion->stop();
    explotando = false;
    explosion_terminada = false;
    subiendo = subiendo_inicial;

    set_inicios_frames({0});
    cargar_sprite(":/new/obstaculos/Material/escudo_sprite.png", 260, 280, 1);
    setScale(0.55);
    colocar(pos_x_inicial, pos_y_inicial);
}

void obstaculo::explotar()
{
    explotando = true;
    explosion_terminada = false;

    cargar_sprite(":/new/obstaculos/Material/explosion_sprite.png", 100, 100, 4);
    set_inicios_frames({0, 100, 200, 300});

    QObject::disconnect(timer_explosion, nullptr, nullptr, nullptr);
    QObject::connect(timer_explosion, &QTimer::timeout, [this]() {
        if (actualizar_sprite(4)) {
            timer_explosion->stop();
            explosion_terminada = true;
        }
    });
    timer_explosion->start(80);
}

bool obstaculo::termino_explosion()
{
    return explosion_terminada;
}

void obstaculo::destruirse()
{
    if (scene()) {
        scene()->removeItem(this);
    }
}

void obstaculo::cargar_en_escena(QGraphicsScene *escena, std::vector<obstaculo*> &lista)
{
    // Limpiamos todo lo que habia para evitar errores
    for (obstaculo* en_pantalla : lista) {
        en_pantalla->destruirse();
        delete en_pantalla;
    }
    lista.clear();

    float posiciones_x[] = {300, 450, 600, 750, 900};
    float velocidades[] = {3.0, 3.8, 4.2, 3.4, 4.0};
    const float y_min = 130.0;
    const float y_max = 520.0;

    for (int i = 0; i < 5; i++){
        obstaculo *en_pantalla = new obstaculo();
        en_pantalla->set_inicios_frames({0});
        en_pantalla->cargar_sprite(":/new/obstaculos/Material/escudo_sprite.png", 260, 280, 1);
        en_pantalla->setScale(0.55);

        float y_inicio = y_min + (y_max - y_min) * i / 4.0f;
        en_pantalla->colocar(posiciones_x[i], y_inicio);
        en_pantalla->configurar_movimiento(i % 2 == 1, velocidades[i]);

        escena->addItem(en_pantalla);
        lista.push_back(en_pantalla);
    }
}
#include "widget.h"
#include "ui_widget.h"
#include "entidad.h"
#include <QMessageBox>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    personaje_elegido = -1;

    zeuz = nullptr;
    poseidon = nullptr;
    hades = nullptr;
    ares = nullptr;

    lanza_zeuz = nullptr;
    lanza_poseidon = nullptr;
    lanza_hades = nullptr;
    lanza_ares = nullptr;

    timerJuego = new QTimer(this);

    explosion_borde = nullptr;

    // Configuracion escenas
    setWindowTitle("Sangre de Dioses");
    nivel1 = new QGraphicsScene(ui->graphicsView->rect(), this);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(nivel1);

    ui->stackedWidget_2->setCurrentIndex(0);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::iniciar_nivel(int personaje)
{
    personaje_elegido = personaje;

    ui->stackedWidget_2->setCurrentIndex(1);
    setWindowTitle("Nivel 1 - Juego de Baldur");

    QPixmap mapa(":/new/Fondos/Material/fondoCombate.png");
    nivel1 = new QGraphicsScene(mapa.rect(), this);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(nivel1);

    fondo1 = new QGraphicsPixmapItem(mapa);
    fondo1->setPos(0, 0);
    nivel1->addItem(fondo1);

    // Configuramos el personaje segun cual eligio el jugador
    switch (personaje_elegido) {
    case 0:
        QMessageBox::information(this, "Zeuz", "Haz elejido al Dios del rayo");
        zeuz = new entidad();
        zeuz->setPos(150, 210);
        nivel1->addItem(zeuz);
        zeuz->set_inicios_frames({57, 301, 516, 720, 936});
        zeuz->cargar_sprite(":/new/sprite_personajes/Material/SEUZ_sprite.png", 161, 228, 5);
        break;

    case 1:
        QMessageBox::information(this, "Poseidon", "Haz elejido al Dios de los mares");
        poseidon = new entidad();
        poseidon->setPos(150, 210);
        nivel1->addItem(poseidon);
        poseidon->set_inicios_frames({0, 269});
        poseidon->set_anchos_frames({269, 344});
        poseidon->cargar_sprite(":/new/sprite_personajes/Material/poseidon_sprite.png", 344, 407, 2);
        poseidon->setScale(228.0 / 407.0);
        break;

    case 2:
        QMessageBox::information(this, "Hades", "Haz elejido al Dios del inframundo");
        hades = new entidad();
        hades->setPos(150, 210);
        nivel1->addItem(hades);
        hades->set_inicios_frames({0, 290});
        hades->set_anchos_frames({290, 323});
        hades->cargar_sprite(":/new/sprite_personajes/Material/hades_sprite.png", 323, 407, 2);
        hades->setScale(228.0 / 407.0);
        break;

    case 3:
        QMessageBox::information(this, "Ares", "Haz elejido al Dios de la guerra");
        ares = new entidad();
        ares->setPos(150, 210);
        nivel1->addItem(ares);
        ares->set_inicios_frames({0, 229});
        ares->set_anchos_frames({229, 384});
        ares->cargar_sprite(":/new/sprite_personajes/Material/ares_sprite.png", 384, 407, 2);
        ares->setScale(228.0 / 407.0);
        break;
    }

    // Cargamos los obstaculos usando el metodo de la clase obstaculo
    obstaculo::cargar_en_escena(nivel1, obstaculos);

    disconnect(timerJuego, nullptr, this, nullptr);
    connect(timerJuego, &QTimer::timeout, this, &Widget::actualizar_juego);
    timerJuego->start(30);
}

void Widget::on_pushButton_clicked()
{
    iniciar_nivel(0);
}
void Widget::on_pushButton_2_clicked()
{
    iniciar_nivel(1);
}
void Widget::on_pushButton_3_clicked()
{
    iniciar_nivel(2);
}
void Widget::on_pushButton_4_clicked()
{
    iniciar_nivel(3);
}


void Widget::actualizar_juego(){

    proyectil *lanza = nullptr;

    switch (personaje_elegido) {
        case 0:
            lanza = lanza_zeuz;
            break;

        case 1:
            lanza = lanza_poseidon;
            break;

        case 2:
            lanza = lanza_hades;
            break;

        case 3:
            lanza = lanza_ares;
            break;
    }

        if (lanza != nullptr && lanza->esta_en_vuelo()) {
        lanza->mover();
    }

    for (obstaculo* en_pantalla : obstaculos) {
        if (en_pantalla->explotando && en_pantalla->termino_explosion()) {
            en_pantalla->reiniciar();
        } else if (!en_pantalla->explotando) {
            en_pantalla->mover();
        }
    }

    revisar_colisiones(lanza);
}

void Widget::on_pushButton_lanzar_clicked()
{
    if (timerJuego == nullptr) return;

    entidad *personaje = nullptr;
    proyectil *lanza = nullptr;
    int frames_ataque = 0;
    QString ruta_sprite;
    int ancho = 96;
    int alto = 113;
    int offset_x = 60;
    int offset_y = 0;

    switch (personaje_elegido) {
    case 0:
        personaje = zeuz;
        lanza = lanza_zeuz;
        frames_ataque = 5;
        ruta_sprite = ":/new/lanzas/Material/lanza_zeuz.png";
        break;
    case 1:
        personaje = poseidon;
        lanza = lanza_poseidon;
        frames_ataque = 2;
        ruta_sprite = ":/new/lanzas/Material/lanza_poseidon.png";
        ancho = 110;
        alto = 130;
        offset_x = 90;
        offset_y = 30;
        break;
    case 2:
        personaje = hades;
        lanza = lanza_hades;
        frames_ataque = 2;
        ruta_sprite = ":/new/lanzas/Material/lanza_hades.png";
        ancho = 110;
        alto = 130;
        offset_x = 90;
        offset_y = 30;
        break;
    case 3:
        personaje = ares;
        lanza = lanza_ares;
        frames_ataque = 2;
        ruta_sprite = ":/new/lanzas/Material/lanza_ares.png";
        ancho = 110;
        alto = 130;
        offset_x = 90;
        offset_y = 30;
        break;
    default: return;
    }

    if (personaje == nullptr){
        return;
    }

    int angulo = ui->spinBox_angulo->value();
    int fuerza = ui->spinBox2_fuerza->value();

    // Animacion de ataque
    disconnect(timerJuego, nullptr, this, nullptr);
    connect(timerJuego, &QTimer::timeout, this, [this, personaje, frames_ataque]() {
        if (personaje->actualizar_sprite(frames_ataque)) {
            disconnect(timerJuego, nullptr, this, nullptr);
            connect(timerJuego, &QTimer::timeout, this, &Widget::actualizar_juego);
            timerJuego->start(30);
        }
    });
    timerJuego->start(170);

    // Preparamos la lanza
    if (lanza == nullptr) {
        lanza = new proyectil();
        switch (personaje_elegido) {
        case 0: lanza_zeuz = lanza; break;
        case 1: lanza_poseidon = lanza; break;
        case 2: lanza_hades = lanza; break;
        case 3: lanza_ares = lanza; break;
        }
    }

    lanza->preparar(nivel1, personaje->x(), personaje->y(), ruta_sprite, ancho, alto, offset_x, offset_y);
    lanza->lanzar(angulo, fuerza);
}

void Widget::destruir_lanza(proyectil *&lanza, float pos_x, float pos_y)
{
    if (lanza != nullptr) { // Si la lanza existe, la destruimos y eliminamos de la escena
        nivel1->removeItem(lanza);
        delete lanza;
        lanza = nullptr;
    }

    if (explosion_borde != nullptr) { // De la misma forma, si existe la explosion del borde, la eliminamos
        nivel1->removeItem(explosion_borde);
        delete explosion_borde;
    }

    // Creamos una una explosion cuando la lanza golpee algo
    explosion_borde = new entidad();
    explosion_borde->setPos(pos_x, pos_y);
    nivel1->addItem(explosion_borde);

    explosion_borde->set_inicios_frames({0, 100, 200, 300});
    explosion_borde->cargar_sprite(":/new/obstaculos/Material/explosion_sprite.png", 100 , 100 , 4);

    QTimer *tiempo_explosion = new QTimer(this);
    connect(tiempo_explosion, &QTimer::timeout, this, [this, tiempo_explosion]() {
        if (explosion_borde != nullptr) {
            bool termino = explosion_borde->actualizar_sprite(4);
            if (termino) {
                nivel1->removeItem(explosion_borde);
                delete explosion_borde;
                explosion_borde = nullptr;
                tiempo_explosion->stop();
                tiempo_explosion->deleteLater();
            }
        }
    });
    tiempo_explosion->start(80);

}

void Widget::revisar_colisiones(proyectil *lanza)
{
    if (lanza == nullptr || !lanza->esta_en_vuelo()) {
        return;
    }

    // Si la lanza choca conun borde
    if (lanza->x() > 1376 || lanza->x() < 0 || lanza->y() > 2000 || lanza->y() < 0) {
        float px = lanza->x();
        float py = lanza->y();

        switch (personaje_elegido) {
        case 0:
            destruir_lanza(lanza_zeuz, px, py);
            break;
        case 1:
            destruir_lanza(lanza_poseidon, px, py);
            break;
        case 2:
            destruir_lanza(lanza_hades, px, py);
            break;
        case 3:
            destruir_lanza(lanza_ares, px, py);
            break;
        default:
            break;
        }
        return;
    }

    // Si la lanza choca con un obstaculo
    for (obstaculo* en_pantalla :  obstaculos) {
        if (en_pantalla->explotando) continue;

        if (lanza->collidesWithItem(en_pantalla)) {
            float px = lanza->x();
            float py = lanza->y();

            en_pantalla->explotar();

            switch (personaje_elegido) {
            case 0:
                destruir_lanza(lanza_zeuz, px, py);
                break;
            case 1:
                destruir_lanza(lanza_poseidon, px, py);
                break;
            case 2:
                destruir_lanza(lanza_hades, px, py);
                break;
            case 3:
                destruir_lanza(lanza_ares, px, py);
                break;
            default:
                break;
            }
            return;
            }
        }
}

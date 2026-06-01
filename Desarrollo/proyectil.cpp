#include "proyectil.h"

proyectil::proyectil()
{
    angulo = 0;
    fuerza_inicial = 0;
    fuerza_final = 0;
    en_vuelo = false;
    vel_x = 0;
    vel_y = 0;

    pos_x = 0;
    pos_y = 0;
}

void proyectil::lanzar(float angulo_lanzamiento, float fuerza_lanzamiento)
{
    angulo = angulo_lanzamiento;
    fuerza_inicial = fuerza_lanzamiento;
    fuerza_final = 0;
    en_vuelo = true;

    pos_x = x();
    pos_y = y();

    motor.calcular_velocidad_inicial(angulo, fuerza_lanzamiento, vel_x, vel_y);
}

void proyectil::mover()
{
    if(en_vuelo){
        // Primero aplicamos la gravedad
        motor.aplicar_gravedad(vel_y);
        motor.aplicar_resistencia(vel_x);

        pos_x += vel_x;
        pos_y += vel_y;

        setPos(pos_x, pos_y);

        fuerza_final = motor.fuerza_final(vel_x, vel_y);

        // Si la lanza se sale de la pantalla, la detenemos
        if (x() > 1376 || x() < 0 || y() > 2000 || y() < 0)
        {
            en_vuelo = false;
        }
    }
}

bool proyectil::esta_en_vuelo()
{
    return en_vuelo;
}

void proyectil::preparar(QGraphicsScene *scena, float x_personaje, float y_personaje, QString ruta_sprite, int ancho, int alto, int offset_x, int offset_y)
{
    // Si ya estaba en la escena la quitamos primero
    if (scene())
    {
        scena->removeItem(this);
    }

    // 1. Cargamos el sprite de la lanza
    QPixmap sprite(ruta_sprite);
    setPixmap(sprite.scaled(ancho, alto, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // 2. La posicionamos en el personaje
    setPos(x_personaje + offset_x, y_personaje + offset_y);

    // 3. La agregamos a la escena
    scena->addItem(this);

    en_vuelo = false;
}

float proyectil::get_fuerza_final()
{
    if (fuerza_final > 0)
    {
        return fuerza_final;
    }
    return fuerza_inicial;
}
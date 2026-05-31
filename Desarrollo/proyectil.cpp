#include "proyectil.h"
#include "motor_fisico.cpp"

proyectil::proyectil()
{
    angulo = 0;
    fuerza_inicial = 0;
    fuerza_final = 0;
    en_vuelo = false;
    vel_x = 0;
    vel_y = 0;
}

void proyectil::lanzar(float angulo_lanzamiento, float fuerza_lanzamiento)
{
    angulo = angulo_lanzamiento;
    fuerza_inicial = fuerza_lanzamiento;
    en_vuelo = true;

    motor.calcular_velocidad_inicial(angulo, fuerza_lanzamiento, vel_x, vel_y);
}

void proyectil::mover()
{
    if(en_vuelo){
        // Primero aplicamos la gravedad
        motor.aplicar_gravedad(vel_y);

        // Movemos la lanza segun las velocidades iniciales
        set_velocidad((int) vel_x, (int) vel_y);
        actualizar_posicion();

        // Si la lanza se sale de la pantalla, la detenemos
        if (x() > 1376 || x() < 0 || y() > 768 || y() < 0) {
            en_vuelo = false;
        }
    }
}

bool proyectil::esta_en_vuelo()
{
    return en_vuelo;
}

void proyectil::calcular_trayectoria()
{
    // Aquí se podría implementar la lógica para calcular la trayectoria del proyectil en función de la gravedad y el tiempo
}

void proyectil::calcular_impacto()
{
    // Por implementar
}
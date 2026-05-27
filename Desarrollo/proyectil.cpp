#include "proyectil.h"
#include "motor_fisico.cpp"

proyectil::proyectil()
{
    angulo = 0;
    fuerza_inicial = 0;
    fuerza_final = 0;
    en_vuelo = false;
}

void proyectil::lanzar(float angulo_lanzamiento, float fuerza_lanzamiento)
{
    angulo = angulo_lanzamiento;
    fuerza_inicial = fuerza_lanzamiento;
    en_vuelo = true;

    // Convertir el angulo de grados a radianes para poder usar coseno y seno
    double angulo_en_radianes = angulo * 3.14159265 / 180.0;

    // Calcular cuanto se mueve en X y Y
    float velocidad = fuerza_lanzamiento * 1.0; // Para que no sea demasiado rapido

    set_velocidad (velocidad * cos(angulo_en_radianes), velocidad * sin(angulo_en_radianes)); // El -  es porque n qt la Y crece hacia abajo

}

void proyectil::mover()
{
    // Solo se tiene que mover si esta en vuelo
    if(en_vuelo){
        actualizar_posicion();

        // Si la lanza se sale de la pantalla, la detenemos
        if (x() > 1080 || x() < 0 || y() > 600 || y() < 0) {
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
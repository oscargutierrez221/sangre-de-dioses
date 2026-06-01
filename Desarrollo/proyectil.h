#ifndef PROYECTIL_H
#define PROYECTIL_H
#include "entidad.h"
#include "motor_fisico.h"
#include <QGraphicsScene>

class proyectil : public entidad
{
    private:
        float angulo;
        float fuerza_inicial;
        float fuerza_final;

        // Para saber si la lanza fue lanzada ya
        bool en_vuelo;

        // Para la gravedad
        float vel_x;
        float vel_y;

        float pos_x;
        float pos_y;

        // Un objeto para el motor fisico
        motor_fisico motor;

    public:
        proyectil();

        // Lanza
        void lanzar(float angulo_lanzamiento, float fuerza_lanzamiento);
        void mover();
        bool esta_en_vuelo();

        void preparar(QGraphicsScene *scena, float x_personaje, float y_personaje, QString ruta_sprite, int ancho, int alto, int offset_x, int offset_y);

        void destruir_de_escena();
};

#endif // PROYECTIL_H

#ifndef OBSTACULO_H
#define OBSTACULO_H
#include "entidad.h"
#include <QTimer>

class obstaculo : public entidad
{
    private:
        int dureza;
        int tamanio;
        float velocidad_movimiento;

        // Para el movimiento arriba y abajo
        bool subiendo;
        float pos_y_actual;
        float pos_x_inicial;
        float pos_y_inicial;
        float y_min;
        float y_max;

        QTimer *timer_explosion;
        bool explosion_terminada;
        bool subiendo_inicial;
    public:
        obstaculo();

        bool explotando;

        void mover();
        void colocar(float x, float y);
        void configurar_movimiento(bool hacia_arriba, float velocidad);
        void reiniciar();
        void explotar();
        bool termino_explosion();
        void destruirse();
};

#endif // OBSTACULO_H

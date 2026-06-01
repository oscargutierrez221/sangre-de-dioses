#ifndef OBSTACULO_H
#define OBSTACULO_H
#include "entidad.h"
#include <QTimer>
#include <QGraphicsScene>
#include <vector>

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

        // Crea los 5 escudos y los mete en la escena y en el vector
        static void cargar_en_escena(QGraphicsScene *escena, std::vector<obstaculo*> &lista);
};

#endif // OBSTACULO_H

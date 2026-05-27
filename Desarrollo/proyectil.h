#ifndef PROYECTIL_H
#define PROYECTIL_H
#include "entidad.h"

class proyectil : public entidad
{
    private:
        float angulo;
        float fuerza_inicial;
        float fuerza_final;

        // Para saber si la lanza fue lanzada ya
        bool en_vuelo;

    public:
        proyectil();

        // Lanza
        void lanzar(float angulo_lanzamiento, float fuerza_lanzamiento);
        void mover();
        bool esta_en_vuelo();

        void calcular_trayectoria();
        void calcular_impacto();
};

#endif // PROYECTIL_H

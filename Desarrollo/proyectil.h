#ifndef PROYECTIL_H
#define PROYECTIL_H
#include "entidad.h"

class proyectil : public entidad
{
    private:
        float angulo;
        float fuerza_inicial;
        float fuerza_final;

    public:
        proyectil();
        void calcular_trayectoria();
        void calular_impacto();
};

// Faltan implementar las clases hijas jabalin y proyectil divino de artemisa que le puse simplemente flecha

#endif // PROYECTIL_H

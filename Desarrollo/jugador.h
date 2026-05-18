#ifndef JUGADOR_H
#define JUGADOR_H
#include "personaje.h"

class jugador : public personaje
{
    private:
        float angulo;
        float fuerza;
        int puntuacion;

    public:
        jugador();

        void apuntar();
        void lanzar(float x, float y);
        void calcular_lanzamiento();
};

#endif // JUGADOR_H

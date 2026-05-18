#ifndef BALDUR_H
#define BALDUR_H
#include "personaje.h"

class baldur : public personaje
{
    private:
        bool es_invulnerable;
        int golpes_recibidos;

    public:
        baldur();
        void recibir_impactos();
};

#endif // BALDUR_H

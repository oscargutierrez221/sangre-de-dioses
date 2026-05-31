#ifndef BALDUR_H
#define BALDUR_H
#include "entidad.h"

class baldur : public entidad
{
    private:
        bool es_invulnerable;
        int golpes_recibidos;

    public:
        baldur();
        void recibir_impactos();
};

#endif // BALDUR_H

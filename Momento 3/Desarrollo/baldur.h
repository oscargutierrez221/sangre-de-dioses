#ifndef BALDUR_H
#define BALDUR_H
#include "entidad.h"
#include <QGraphicsScene>

class baldur : public entidad
{
    private:
        int contador_risa;

        int lugar_actual;
        float posiciones_x[4] = {1050, 920, 1100, 800};
        float posiciones_y[4] = {200, 320, 150, 400};

    public:
        baldur();

        void cargar_en_escena(QGraphicsScene *escena);

        // La animacion
        void animar();

        // Cuando lo golpea la lanza se mueve a otro sitio
        void recibir_impacto();
};

#endif // BALDUR_H

#include "baldur.h"

baldur::baldur()
{
    contador_risa = 0;
    lugar_actual = 0;
}

void baldur::cargar_en_escena(QGraphicsScene *escena)
{
    contador_risa = 0;
    lugar_actual = 0;

    set_inicios_frames({0, 257});
    set_anchos_frames({257, 257});
    cargar_sprite(":/new/sprite_personajes/Material/baldur_sprite.png", 257, 486, 2);
    setScale(228.0 / 486.0);
    setPos(posiciones_x[0], posiciones_y[0]);
    if (scene() == nullptr)
        escena->addItem(this);
}

void baldur::animar()
{
    contador_risa++;
    if (contador_risa >= 15) {
        contador_risa = 0;
        actualizar_sprite(2);
    }
}

void baldur::recibir_impacto()
{
    lugar_actual = lugar_actual + 1;
    if (lugar_actual > 3) {
        lugar_actual = 0;
    }

    setPos(posiciones_x[lugar_actual], posiciones_y[lugar_actual]);
}

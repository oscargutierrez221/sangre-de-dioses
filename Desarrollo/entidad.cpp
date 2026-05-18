#include "entidad.h"
#include <QPixmap>

entidad::entidad(int x_inicio, int y_inicio)
{
    x = x_inicio;
    y = y_inicio;

    velocidad_x = 0;
    veloccidad_y = 0;

    setPos(x, y);
}

void entidad::set_velocidad(int vx, int vy)
{
    velocidad_x = vx;
    veloccidad_y = vy;
}

void entidad::actualizar_posicion()
{
    x += velocidad_x;
    y += veloccidad_y;

    setPos(x, y);
}

void entidad::cargar_sprite(const QString &path) {
    // 1. Cargamos la imagen desde la ruta de Resources
    QPixmap dibujo(path);

    // 2. Lo ponemos en el QGraphicsPixmapItem para que se pueda mostrar en la escena
    setPixmap(dibujo);
}
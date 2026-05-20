#include "entidad.h"
#include <QPixmap>

entidad::entidad(int x_inicio, int y_inicio)
{
    x = x_inicio;
    y = y_inicio;

    velocidad_x = 0;
    veloccidad_y = 0;

    setPos(x, y);

    frame_actual = 0;
    total_frames = 0;
    ancho_frame = 0;
    alto_frame = 0;
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

void entidad::cargar_sprite(const QString &path, int ancho, int alto, int cantidad_frames) {
    // 1. Cargamos la imagen desde la ruta de Resources
    spriteSheet = QPixmap(path);

    // 2. Guardamos las dimensiones del sprite
    ancho_frame = ancho;
    alto_frame = alto;
    total_frames = cantidad_frames;
    frame_actual = 0;

    // 3. Mostramos el primer frame
    actualizar_sprite();
}

void entidad::actualizar_sprite() {
    if (total_frames <= 0) {
        return;
    }

    // 1. Calcular donde empieza el frame actual
    int posicion_x = frame_actual * ancho_frame;

    // 2. Recortamos el rectangulo exacto del frame
    QPixmap frame_Recortado = spriteSheet.copy(posicion_x, 0, ancho_frame, alto_frame);

    // 3. Le asignamos al QGraphicsPixmapItem el frame recortado
    setPixmap(frame_Recortado);

    // 4. Avanzamos al siguiente frame
    frame_actual = (frame_actual + 1) % total_frames;
}
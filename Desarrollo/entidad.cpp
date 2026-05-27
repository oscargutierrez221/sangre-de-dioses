#include "entidad.h"
#include <QPixmap>

entidad::entidad(int x_inicio, int y_inicio)
{
    velocidad_x = 0;
    veloccidad_y = 0;

    setPos(x_inicio, y_inicio);

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
    setPos(x() + velocidad_x, y() + veloccidad_y);
}

void entidad::set_inicios_frames(std::vector<int> inicios)
{
    inicios_frames = inicios;
}

void entidad::cargar_sprite(const QString &path, int ancho, int alto, int cantidad_frames) {
    spriteSheet = QPixmap(path);

    ancho_frame = ancho;
    alto_frame = alto;
    total_frames = cantidad_frames;
    frame_actual = 0;

    // Mostramos el primer frame (quieto)
    if (!spriteSheet.isNull() && total_frames > 0 && ancho_frame > 0 && alto_frame > 0) {
        int inicio = (inicios_frames.size() > 0) ? inicios_frames[0] : 0;
        setPixmap(spriteSheet.copy(inicio, 0, ancho_frame, alto_frame));
    }
}

bool entidad::actualizar_sprite(int frames_animacion) {
    if (spriteSheet.isNull() || total_frames <= 0 || ancho_frame <= 0 || alto_frame <= 0) {
        return true;
    }

    int limite = total_frames;
    if (frames_animacion > 0 && frames_animacion < total_frames) {
        limite = frames_animacion;
    }

    // Calculamos el inicio X de este frame
    int inicio = 0;
    if (frame_actual < (int)inicios_frames.size()) {
        inicio = inicios_frames[frame_actual];
    }

    // Dibujamos el frame actual en su posicion exacta
    setPixmap(spriteSheet.copy(inicio, 0, ancho_frame, alto_frame));

    // Avanzamos al siguiente frame
    frame_actual++;

    if (frame_actual >= limite) {
        frame_actual = 0;
        int inicio0 = (inicios_frames.size() > 0) ? inicios_frames[0] : 0;
        setPixmap(spriteSheet.copy(inicio0, 0, ancho_frame, alto_frame));
        return true;
    }

    return false;
}

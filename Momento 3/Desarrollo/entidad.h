#ifndef ENTIDAD_H
#define ENTIDAD_H
#include <QGraphicsPixmapItem>
#include <QString>
#include <vector>

class entidad : public QGraphicsPixmapItem
{
    private:
        // Variables para el sprite de la entidad
        QPixmap spriteSheet;
        int alto_frame;
        int ancho_frame;
        int frame_actual;
        int total_frames;
        std::vector<int> inicios_frames;
        std::vector<int> anchos_frames;

        int ancho_de_frame(int indice) const;

    public:
        entidad(int x_inicio = 0, int y_inicio = 0);

        // Metodo para cargar el sprite de la entidad
        void cargar_sprite(const QString &path, int ancho, int alto, int cantidad_frames);
        void set_inicios_frames(std::vector<int> inicios);
        void set_anchos_frames(std::vector<int> anchos);
        bool actualizar_sprite(int frames_animacion = -1);
};

#endif // ENTIDAD_H

#ifndef ENTIDAD_H
#define ENTIDAD_H
#include <QGraphicsPixmapItem>
#include <QString>

class entidad : public QGraphicsPixmapItem
{
    private:
        int x;
        int y;

        int velocidad_x;
        int veloccidad_y;

    public:
        entidad(int x_inicio = 0, int y_inicio = 0);

        // getters y setters para x,y
        void set_velocidad(int vx, int vy);

        int set_fuerza_lanzamiento();
        int get_fuerza_lanzamiento();

        // Metodos
        void actualizar_posicion();
        void cargar_sprite(const QString &path);
        bool esta_vivo();
};

#endif // ENTIDAD_H

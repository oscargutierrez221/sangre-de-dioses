#ifndef ENTIDAD_H
#define ENTIDAD_H
#include <QPixmap>

class entidad
{
    private:
        int x;
        int y;

    public:
        entidad();

        // getters y setters para x,y
        int set_posicion();
        int get_posicionX();

        int set_fuerza_lanzamiento();
        int get_fuerza_lanzamiento();

        // Metodos
        void lanzar(float x, float y);
        void cargar_sprite(const QString &path);
        bool esta_vivo();


    protected:
        void verificacr_limites_pantalla();
};

#endif // ENTIDAD_H

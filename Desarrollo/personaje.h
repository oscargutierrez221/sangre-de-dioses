#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <string>
#include "entidad.h"

class personaje : public entidad
{
    private:
        std::string nombre;
        int poder_ataque;

    public:
        personaje();

        // setters y getters del personaje
        std::string set_nombre();
        std::string get_nombre();

        // Metodos
        void actualizar_estado();
        int poder(int cantidad);
};

#endif // PERSONAJE_H

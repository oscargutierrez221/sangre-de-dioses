#ifndef NIVELES_H
#define NIVELES_H
#include "entidad.h"

class niveles
{
public:
    niveles();

    // Segun el personaje elegido, se cargara un sprite diferente
    void cargar_nivel_zeuz();
    void cargar_nivel_poseidon();
    void cargar_nivel_hades();
    void cargar_nivel_ares();
};
#endif //

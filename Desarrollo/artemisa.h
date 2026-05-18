#ifndef ARTEMISA_H
#define ARTEMISA_H
#include "personaje.h"

class artemisa : public personaje
{
public:
    artemisa();

    // Metodos
    void tiempo_de_carga();
    void disparar_flecha();
};

#endif // ARTEMISA_H

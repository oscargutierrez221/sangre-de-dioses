#ifndef APOLO_H
#define APOLO_H
#include "personaje.h"

class apolo : public personaje
{
public:
    apolo();

    // Metodos
    void cambiar_viento();
    void afectar_trayectoria();
};

#endif // APOLO_H

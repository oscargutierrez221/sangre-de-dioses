#ifndef MUERDAGO_H
#define MUERDAGO_H
#include "obstaculo.h"

class muerdago : public obstaculo
{
    private:
        float probabilidad_aparecer();
        float tiempo_visible();

    public:
        muerdago();
};

#endif // MUERDAGO_H

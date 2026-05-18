#ifndef OBSTACULO_H
#define OBSTACULO_H
#include "entidad.h"

class obstaculo : public entidad
{
    private:
        int dureza;
        int tamanio;
        float veloidad_movimiento;
    public:
        obstaculo();

        // Metodo
        void destruirse();
        void amplitud_movimiento();
};

#endif // OBSTACULO_H

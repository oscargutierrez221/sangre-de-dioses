#ifndef LOKI_H
#define LOKI_H

class loki
{
    private:
        float tiempo_para_intervenir;
        int nivel_dificultad;

    public:
        loki();

        // Metodos
        void generar_muerdago();
        void generar_obstaculos();
        void aumentar_dificultad();
};

#endif // LOKI_H

#ifndef MOTOR_FISICO_H
#define MOTOR_FISICO_H

class motor_fisico
{
private:
    float gravedad;

public:

    motor_fisico();

    // Para la trayectoria de la lanza
    double sen(double x);
    double cos(double x);

    void aplicar_gravedad(float &velocidad_y);
    void calcular_velocidad_inicial(float angulo, float fuerza, float &velocidad_x, float &velocidad_y);

};

#endif // MOTOR_FISICO_H

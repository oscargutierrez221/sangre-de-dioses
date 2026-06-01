#ifndef MOTOR_FISICO_H
#define MOTOR_FISICO_H

class motor_fisico
{
private:
    float gravedad;
    float resistencia_aire;

public:

    motor_fisico();

    // Para la trayectoria de la lanza
    double sen(double x);
    double cos(double x);
    double calcularRaiz(double numero);

    void aplicar_gravedad(float &velocidad_y);
    void aplicar_resistencia(float &velocidad_x);
    void calcular_velocidad_inicial(float angulo, float fuerza, float &velocidad_x, float &velocidad_y);
    float fuerza_final(float vel_x, float vel_y);

};

#endif // MOTOR_FISICO_H

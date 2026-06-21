#include "motor_fisico.h"

motor_fisico::motor_fisico()
{
    gravedad = 9.8;
    resistencia_aire = 0.02;
}

double motor_fisico::sen(double x)
{
    double termino = x;
    double suma = x;
    for(int i = 1; i < 10; i++)
    {
        termino *= -1 * x * x / ((2 * i) * (2 * i + 1)); // calcular el siguiente término
        suma += termino; // agregar el término a la suma
    }
    return suma;
}

double motor_fisico::cos(double x)
{
    double ttermino = 1.0; // Primer termino de la serie
    double suma = 1.0;
    for(int i = 1; i < 10; i++)
    {
        ttermino *= -1 * x * x / ((2 * i - 1) * (2 * i)); // calcular el siguiente término
        suma += ttermino; // agregar el término a la suma
    }
    return suma;
}

double motor_fisico::calcularRaiz(double numero)
{
    if (numero < 0)
        return -1; // Manejo de error para negativos

    if (numero == 0)
        return 0;

    double estimacion = numero; // Valor inicial
    double precision = 0.000001; // Margen de error tolerado

    // Bucle de aproximación
    while ((estimacion * estimacion - numero) > precision || (numero - estimacion * estimacion) > precision)
    {
        estimacion = 0.5 * (estimacion + (numero / estimacion));
    }

    return estimacion;
}

void motor_fisico::calcular_velocidad_inicial(float angulo, float fuerza, float &velocidad_x, float &velocidad_y)
{
    // Convertimos el angulo de grados a radianes
    float angulo_rad = angulo * 3.14159265 / 180.0;

    // La fuerza se descompone en X y Y segun el angulo
    velocidad_x = fuerza * this->cos(angulo_rad);
    velocidad_y = -(fuerza * this->sen(angulo_rad));
}

void motor_fisico::aplicar_gravedad(float &velocidad_y)
{
    velocidad_y += gravedad;
}

void motor_fisico::aplicar_resistencia(float &velocidad_x)
{
    velocidad_x *= (1.0 - resistencia_aire);
}

float motor_fisico::fuerza_final(float vel_x, float vel_y)
{
    return calcularRaiz(vel_x * vel_x + vel_y * vel_y);
}
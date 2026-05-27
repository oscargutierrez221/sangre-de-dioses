#include "motor_fisico.h"

motor_fisico::motor_fisico() {}

double motor_fisico::sen(double x){
    double termino = x;
    double suma = x;
    for(int i = 1; i < 10; i++){
        termino *= -1 * x * x / ((2 * i) * (2 * i + 1)); // calcular el siguiente término
        suma += termino; // agregar el término a la suma
    }
    return suma;
}

double motor_fisico::cos(double x){
    double ttermino = 1.0; // Primer termino de la serie
    double suma = 1.0;
    for(int i = 1; i < 10; i++){
        ttermino *= -1 * x * x / ((2 * i - 1) * (2 * i)); // calcular el siguiente término
        suma += ttermino; // agregar el término a la suma
    }
    return suma;
}
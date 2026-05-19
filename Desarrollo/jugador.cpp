#include "jugador.h"
#include <iostream>
#include <string>
#include <cmath> // para funciones trigonométricas
using namespace std;

// Clase base Entidad
class Entidad {
protected:
    string nombre;
    int puntosDeVida;

public:
    Entidad(const string& n, int vida) : nombre(n), puntosDeVida(vida) {}

    virtual void mostrarInfo() const {
        cout << "Nombre: " << nombre << ", Vida: " << puntosDeVida << endl;
    }

    virtual ~Entidad() {}
};

// Clase Personaje
class Personaje : public Entidad {
protected:
    int poder;

public:
    Personaje(const string& n, int vida, int p) : Entidad(n, vida), poder(p) {}

    void cambiar_sprite() {
        cout << nombre << " cambia su sprite en pantalla." << endl;
    }

    void mostrarInfo() const override {
        cout << "Nombre: " << nombre
             << ", Vida: " << puntosDeVida
             << ", Poder: " << poder << endl;
    }
};

// Clase Jugador que hereda de Personaje
class Jugador : public Personaje {
private:
    double angulo;      // en grados
    double fuerza;      // magnitud del lanzamiento
    int puntuacion;

public:
    Jugador(const string& n, int vida, int p)
        : Personaje(n, vida, p), angulo(0), fuerza(0), puntuacion(0) {}

    void apuntar(double a) {
        angulo = a;
        cout << nombre << " apunta con un ángulo de " << angulo << " grados." << endl;
    }

    void lanzar(double f) {
        fuerza = f;
        cout << nombre << " lanza con fuerza " << fuerza << "." << endl;
        calcularLanzamiento();
    }

    void calcularLanzamiento() {
        // Ejemplo simple: calcular alcance de un proyectil
        double rad = angulo * M_PI / 180.0; // convertir a radianes
        double alcance = (pow(fuerza, 2) * sin(2 * rad)) / 9.8; // fórmula física simplificada
        cout << "El lanzamiento alcanza aproximadamente " << alcance << " metros." << endl;
    }

    void sumarPuntos(int puntos) {
        puntuacion += puntos;
        cout << nombre << " gana " << puntos << " puntos. Total: " << puntuacion << endl;
    }

    void mostrarInfo() const override {
        Personaje::mostrarInfo();
        cout << "Ángulo: " << angulo
             << ", Fuerza: " << fuerza
             << ", Puntuación: " << puntuacion << endl;
    }
};

// Ejemplo de uso
int main() {
    Jugador jugador("Jugador1", 100, 50);

    jugador.mostrarInfo();
    jugador.apuntar(45);
    jugador.lanzar(20);
    jugador.sumarPuntos(10);

    return 0;
}

jugador::jugador() {}

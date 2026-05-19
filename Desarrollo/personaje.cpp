#include "personaje.h"
#include <iostream>
#include <string>
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

// Clase Personaje que hereda de Entidad
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

// Clases hijas específicas
class Jugador : public Personaje {
public:
    Jugador(const string& n, int vida, int p) : Personaje(n, vida, p) {}
};

class Baldur : public Personaje {
public:
    Baldur(int vida, int p) : Personaje("Baldur", vida, p) {}
};

class Heroe : public Personaje {
public:
    Heroe(const string& n, int vida, int p) : Personaje(n, vida, p) {}
};

class Loki : public Personaje {
public:
    Loki(int vida, int p) : Personaje("Loki", vida, p) {}
};

class Apolo : public Personaje {
public:
    Apolo(int vida, int p) : Personaje("Apolo", vida, p) {}
};

class Artemisa : public Personaje {
public:
    Artemisa(int vida, int p) : Personaje("Artemisa", vida, p) {}
};

// Ejemplo de uso
int main() {
    Jugador jugador("Jugador1", 100, 50);
    Baldur baldur(120, 70);
    Loki loki(90, 80);

    jugador.mostrarInfo();
    jugador.cambiar_sprite();

    baldur.mostrarInfo();
    loki.mostrarInfo();

    return 0;
}

personaje::personaje() {}

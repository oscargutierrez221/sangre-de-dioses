#include "baldur.h"
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

// Clase Baldur que hereda de Personaje
class Baldur : public Personaje {
private:
    bool esInvulnerable;
    int golpesRecibidos;

public:
    Baldur(int vida, int p)
        : Personaje("Baldur", vida, p), esInvulnerable(true), golpesRecibidos(0) {}

    void recibirImpacto(bool esMuérdago) {
        if (esInvulnerable && !esMuérdago) {
            cout << nombre << " es invulnerable, el ataque no le afecta." << endl;
        } else {
            golpesRecibidos++;
            puntosDeVida -= 10; // ejemplo: cada golpe quita 10 de vida
            cout << nombre << " recibe un impacto. Vida restante: " << puntosDeVida << endl;
            if (puntosDeVida <= 0) {
                morir();
            }
        }
    }

    void morir() {
        cout << nombre << " ha muerto tras recibir " << golpesRecibidos << " golpes." << endl;
    }

    void mostrarInfo() const override {
        Personaje::mostrarInfo();
        cout << "Invulnerable: " << (esInvulnerable ? "Sí" : "No")
             << ", Golpes recibidos: " << golpesRecibidos << endl;
    }
};

// Ejemplo de uso
int main() {
    Baldur baldur(100, 80);

    baldur.mostrarInfo();
    baldur.recibirImpacto(false); // ataque normal, no le afecta
    baldur.recibirImpacto(true);  // ataque con muérdago, sí le afecta
    baldur.recibirImpacto(true);  // otro golpe con muérdago

    return 0;
}

baldur::baldur() {}

#ifndef GESTOR_COMBATES_H
#define GESTOR_COMBATES_H

#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <vector>
#include "entidad.h"
#include "proyectil.h"
#include "obstaculo.h"
#include "baldur.h"
#include "panel.h"
#include "efectos_sonido.h"

class gestor_combates : public QObject
{
    Q_OBJECT

public:
    explicit gestor_combates(QObject *parent = nullptr);
    ~gestor_combates();

    // Se llama al inicio de cada nivel para configurar el contexto
    void inicializar(QGraphicsScene *escena, panel *panel_ref, baldur *baldur_ref,
                     std::vector<obstaculo*> *obs, QTimer *timer,
                     entidad *p_zeuz, entidad *p_poseidon, entidad *p_hades,
                     entidad *p_ares, entidad *p_agente, int p_elegido);

    // Mueve las lanzas activas y devuelve el turno si la del agente se detiene
    void actualizar_lanzas();

    // Lanza el ataque del jugador con la animacion correspondiente
    void lanzar_jugador(int angulo, int fuerza);

    // Lanza el ataque del agente (maquina)
    void turno_agente();

    // Detecta colisiones de una lanza con bordes, obstaculos y Baldur
    void revisar_colisiones(proyectil *lanza, bool es_maquina);

    // Elimina lanzas y explosion_borde — llamado desde Widget::limpiar_nivel
    void limpiar_lanzas();

    proyectil* get_lanza_jugador() const;
    proyectil* get_lanza_agente()  const;

signals:
    // Widget lo conecta para reconectar el timer a actualizar_juego
    void animacion_terminada();

private:
    // Nivel
    QGraphicsScene *nivel1;
    panel *panel_juego;
    baldur *baldur_ptr;
    std::vector<obstaculo*> *obstaculos;
    QTimer *timerJuego;

    // Personajes
    entidad *zeuz;
    entidad *poseidon;
    entidad *hades;
    entidad *ares;
    entidad *agente;
    int personaje_elegido;

    // Lanzas
    proyectil *lanza_zeuz;
    proyectil *lanza_poseidon;
    proyectil *lanza_hades;
    proyectil *lanza_ares;
    proyectil *lanza_agente;
    entidad   *explosion_borde;

    // Efectos de sonido
    efectos_sonido *sonidos;

    // Getters
    entidad* get_personaje_activo() const;
    proyectil* get_lanza_jugador_interno() const; // alias interno sin const issues

    // Metodos
    void destruir_lanza(proyectil *&lanza, float pos_x, float pos_y);
    void destruir_lanza_jugador(float px, float py);
};

#endif // GESTOR_COMBATES_H

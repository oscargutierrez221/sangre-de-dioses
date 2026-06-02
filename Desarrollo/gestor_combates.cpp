#include "gestor_combates.h"
#include <QRandomGenerator>

// ─────────────────────────────────────────────
//  Constructor / Destructor
// ─────────────────────────────────────────────

gestor_combates::gestor_combates(QObject *parent)
    : QObject(parent)
{
    // Nivel
    nivel1 = nullptr;
    panel_juego = nullptr;
    baldur_ptr = nullptr;
    obstaculos = nullptr;
    timerJuego = nullptr;

    // Personajes
    zeuz = nullptr;
    poseidon = nullptr;
    hades = nullptr;
    ares = nullptr;
    agente = nullptr;
    personaje_elegido = -1;

    // Lanzas
    lanza_zeuz = nullptr;
    lanza_poseidon = nullptr;
    lanza_hades = nullptr;
    lanza_ares = nullptr;
    lanza_agente = nullptr;

    // Explosion
    explosion_borde = nullptr;

    // Efectos sonido
    sonidos = new efectos_sonido(this);
}

gestor_combates::~gestor_combates()
{
    limpiar_lanzas();
}

// ─────────────────────────────────────────────
//  Inicializacion
// ─────────────────────────────────────────────

void gestor_combates::inicializar(QGraphicsScene *escena, panel *panel_ref, baldur *baldur_ref,
                                std::vector<obstaculo*> *obs, QTimer *timer,
                                entidad *p_zeuz, entidad *p_poseidon, entidad *p_hades,
                                entidad *p_ares, entidad *p_agente, int p_elegido)
{
    nivel1 = escena;
    panel_juego = panel_ref;
    baldur_ptr = baldur_ref;
    obstaculos = obs;
    timerJuego = timer;
    zeuz = p_zeuz;
    poseidon = p_poseidon;
    hades = p_hades;
    ares = p_ares;
    agente = p_agente;
    personaje_elegido = p_elegido;

    sonidos->reproducir_musica_nivel();
}

// ─────────────────────────────────────────────
//  Helpers internos
// ─────────────────────────────────────────────

entidad* gestor_combates::get_personaje_activo() const
{
    switch (personaje_elegido)
    {
        case 0:
            return zeuz;

        case 1:
            return poseidon;

        case 2:
            return hades;

        case 3:
            return ares;

        default:
            return nullptr;
    }
}

proyectil* gestor_combates::get_lanza_jugador() const
{
    switch (personaje_elegido)
    {
        case 0:
            return lanza_zeuz;

        case 1:
            return lanza_poseidon;

        case 2:
            return lanza_hades;

        case 3:
            return lanza_ares;

        default:
            return nullptr;
    }
}

proyectil* gestor_combates::get_lanza_agente() const
{
    return lanza_agente;
}

void gestor_combates::destruir_lanza(proyectil *&lanza, float pos_x, float pos_y)
{
    if (lanza != nullptr)
    {
        nivel1->removeItem(lanza);
        delete lanza;
        lanza = nullptr;
    }

    if (explosion_borde != nullptr)
    {
        nivel1->removeItem(explosion_borde);
        delete explosion_borde;
    }

    sonidos->reproducir_explosion();

    explosion_borde = new entidad();
    explosion_borde->setPos(pos_x, pos_y);
    nivel1->addItem(explosion_borde);

    explosion_borde->set_inicios_frames({0, 226, 452, 678});
    explosion_borde->set_anchos_frames({226, 226, 226, 224});
    explosion_borde->cargar_sprite(":/new/obstaculos/Material/explosion_sprite.png", 226, 277, 4);

    QTimer *tiempo_explosion = new QTimer(this);
    connect(tiempo_explosion, &QTimer::timeout, this, [this, tiempo_explosion]()
        {
            if (explosion_borde != nullptr)
            {
                bool termino = explosion_borde->actualizar_sprite(4);
                if (termino)
                {
                    nivel1->removeItem(explosion_borde);
                    delete explosion_borde;
                    explosion_borde = nullptr;
                    tiempo_explosion->stop();
                    tiempo_explosion->deleteLater();
                }
            }
        });
    tiempo_explosion->start(80);
}

void gestor_combates::destruir_lanza_jugador(float px, float py)
{
    switch (personaje_elegido)
    {
        case 0:
            destruir_lanza(lanza_zeuz, px, py);
            break;

        case 1:
            destruir_lanza(lanza_poseidon, px, py);
            break;

        case 2:
            destruir_lanza(lanza_hades, px, py);
            break;

        case 3:
            destruir_lanza(lanza_ares, px, py);
            break;

        default:
            break;
    }
}

// ─────────────────────────────────────────────
//  Limpiar lanzas
// ─────────────────────────────────────────────

void gestor_combates::limpiar_lanzas()
{
    if (lanza_zeuz != nullptr)
    {
        if (lanza_zeuz->scene() != nullptr)
        {
            lanza_zeuz->scene()->removeItem(lanza_zeuz);
        }
        delete lanza_zeuz;
        lanza_zeuz = nullptr;
    }

    if (lanza_poseidon != nullptr)
    {
        if (lanza_poseidon->scene() != nullptr)
        {
            lanza_poseidon->scene()->removeItem(lanza_poseidon);
        }
        delete lanza_poseidon;
        lanza_poseidon = nullptr;
    }

    if (lanza_hades != nullptr)
    {
        if (lanza_hades->scene() != nullptr)
        {
            lanza_hades->scene()->removeItem(lanza_hades);
        }
        delete lanza_hades;
        lanza_hades = nullptr;
    }

    if (lanza_ares != nullptr)
    {
        if (lanza_ares->scene() != nullptr)
        {
            lanza_ares->scene()->removeItem(lanza_ares);
        }
        delete lanza_ares;
        lanza_ares = nullptr;
    }

    if (lanza_agente != nullptr)
    {
        if (lanza_agente->scene() != nullptr)
        {
            lanza_agente->scene()->removeItem(lanza_agente);
        }
        delete lanza_agente;
        lanza_agente = nullptr;
    }

    if (explosion_borde != nullptr)
    {
        if (explosion_borde->scene() != nullptr)
        {
            explosion_borde->scene()->removeItem(explosion_borde);
        }
        delete explosion_borde;
        explosion_borde = nullptr;
    }

    // Detener la musica
    sonidos->detener_musica_nivel();

}

// ─────────────────────────────────────────────
//  Actualizar lanzas
// ─────────────────────────────────────────────

void gestor_combates::actualizar_lanzas()
{
    proyectil *lanza = get_lanza_jugador();

    if (lanza != nullptr && lanza->esta_en_vuelo())
    {
        lanza->mover();
    }
    else if (lanza != nullptr && panel_juego != nullptr && panel_juego->get_turno() == 0)
    {
        float px = lanza->x();
        float py = lanza->y();
        destruir_lanza_jugador(px, py);
        panel_juego->pasar_turno_maquina();
    }

    if (lanza_agente != nullptr && lanza_agente->esta_en_vuelo())
    {
        lanza_agente->mover();
    }
    else if (lanza_agente != nullptr && panel_juego != nullptr && panel_juego->get_turno() == 1)
    {
        float px = lanza_agente->x();
        float py = lanza_agente->y();
        destruir_lanza(lanza_agente, px, py);
        panel_juego->devolver_turno_jugador();
    }
}

// ─────────────────────────────────────────────
//  Lanzar jugador
// ─────────────────────────────────────────────

void gestor_combates::lanzar_jugador(int angulo, int fuerza)
{
    if (panel_juego != nullptr && panel_juego->get_turno() != 0)
        return;

    entidad *personaje = get_personaje_activo();
    if (personaje == nullptr)
        return;

    proyectil *lanza = get_lanza_jugador();
    if (lanza != nullptr && lanza->esta_en_vuelo())
        return;

    int frames_ataque = 0;
    QString ruta_sprite;
    int ancho = 96;
    int alto = 113;
    int offset_x = 60;
    int offset_y = 0;

    switch (personaje_elegido)
    {
        case 0:
            frames_ataque = 5;
            ruta_sprite = ":/new/lanzas/Material/lanza_zeuz.png";
            break;

        case 1:
            frames_ataque = 2;
            ruta_sprite = ":/new/lanzas/Material/lanza_poseidon.png";
            ancho = 110;
            alto = 130;
            offset_x = 90;
            offset_y = 30;
            break;

        case 2:
            frames_ataque = 2;
            ruta_sprite = ":/new/lanzas/Material/lanza_hades.png";
            ancho = 110;
            alto = 130;
            offset_x = 90;
            offset_y = 30;
            break;

        case 3:
            frames_ataque = 2;
            ruta_sprite = ":/new/lanzas/Material/lanza_ares.png";
            ancho = 110;
            alto = 130;
            offset_x = 90;
            offset_y = 30;
            break;

        default:
            return;
    }

    disconnect(timerJuego, nullptr, this, nullptr);
    connect(timerJuego, &QTimer::timeout, this,
            [this, personaje, frames_ataque, angulo, fuerza, ruta_sprite, ancho, alto, offset_x, offset_y]()
    {
        if (personaje->actualizar_sprite(frames_ataque))
        {
            disconnect(timerJuego, nullptr, this, nullptr);

            // Creamos la lanza si no existe aun
            proyectil *lanza_lista = get_lanza_jugador();
            if (lanza_lista == nullptr)
            {
                lanza_lista = new proyectil();

                switch (personaje_elegido)
                {
                    case 0:
                        lanza_zeuz = lanza_lista;
                        break;

                    case 1:
                        lanza_poseidon = lanza_lista;
                        break;

                    case 2:
                        lanza_hades = lanza_lista;
                        break;

                    case 3:
                        lanza_ares = lanza_lista;
                        break;

                    default:
                        break;
                }
            }

            lanza_lista->preparar(nivel1, personaje->x(), personaje->y(), ruta_sprite, ancho, alto, offset_x, offset_y);
            lanza_lista->lanzar(angulo, fuerza);

            emit animacion_terminada();
        }
    });
    timerJuego->start(170);
}

// ─────────────────────────────────────────────
//  Turno agente (maquina)
// ─────────────────────────────────────────────

void gestor_combates::turno_agente()
{
    if (agente == nullptr)
        return;

    if (panel_juego != nullptr && panel_juego->get_turno() != 1)
        return;

    static int rondas_agente = 0;
    rondas_agente++;

    int margen = 30 - rondas_agente * 2;
    if (margen < 1)
        margen = 1;

    int angulo = 40 + QRandomGenerator::global()->bounded(-margen, margen + 1);
    int fuerza = 85 + QRandomGenerator::global()->bounded(-margen * 2, margen * 2 + 1);

    int frames_ataque = 2;
    if (personaje_elegido == 2)
        frames_ataque = 5;

    QString ruta_lanza = ":/new/lanzas/Material/lanza_hades.png";
    int ancho = 110;
    int alto = 130;
    int offset_x = 90;
    int offset_y = 30;

    switch (personaje_elegido)
    {
        case 0:
            ruta_lanza = ":/new/lanzas/Material/lanza_hades.png";
            break;

        case 1:
            ruta_lanza = ":/new/lanzas/Material/lanza_ares.png";
            break;

        case 2:
            ruta_lanza = ":/new/lanzas/Material/lanza_zeuz.png";
            ancho = 96;
            alto = 113;
            offset_x = 60;
            offset_y = 0;
            break;

        case 3:
            ruta_lanza = ":/new/lanzas/Material/lanza_poseidon.png";
            break;

        default:
            break;
    }

    disconnect(timerJuego, nullptr, this, nullptr);
    connect(timerJuego, &QTimer::timeout, this,
            [this, angulo, fuerza, frames_ataque, ruta_lanza, ancho, alto, offset_x, offset_y]()
    {
        if (agente->actualizar_sprite(frames_ataque))
        {
            disconnect(timerJuego, nullptr, this, nullptr);

            if (lanza_agente == nullptr)
                lanza_agente = new proyectil();

            lanza_agente->preparar(nivel1, agente->x(), agente->y(), ruta_lanza, ancho, alto, offset_x, offset_y);
            lanza_agente->lanzar(angulo, fuerza);

            emit animacion_terminada();
        }
    });
    timerJuego->start(170);
}

// ─────────────────────────────────────────────
//  Revisar colisiones
// ─────────────────────────────────────────────

void gestor_combates::revisar_colisiones(proyectil *lanza, bool es_maquina)
{
    if (lanza == nullptr || !lanza->esta_en_vuelo())
        return;

    // Colision con los bordes de la escena
    if (lanza->x() > 1376 || lanza->x() < 0 || lanza->y() > 2000 || lanza->y() < 0)
    {
        float px = lanza->x();
        float py = lanza->y();

        if (es_maquina)
        {
            destruir_lanza(lanza_agente, px, py);
            if (panel_juego != nullptr)
                panel_juego->devolver_turno_jugador();
        }
        else
        {
            destruir_lanza_jugador(px, py);
            if (panel_juego != nullptr)
                panel_juego->pasar_turno_maquina();
        }
        return;
    }

    // Colision con obstaculos
    if (obstaculos != nullptr)
    {
        for (obstaculo* en_pantalla : *obstaculos)
        {
            if (en_pantalla->explotando)
                continue;

            if (lanza->collidesWithItem(en_pantalla))
            {
                float px = lanza->x();
                float py = lanza->y();

                en_pantalla->explotar();

                if (es_maquina)
                {
                    destruir_lanza(lanza_agente, px, py);
                    if (panel_juego != nullptr)
                        panel_juego->devolver_turno_jugador();
                }
                else
                {
                    destruir_lanza_jugador(px, py);
                    if (panel_juego != nullptr)
                        panel_juego->pasar_turno_maquina();
                }
                return;
            }
        }
    }

    // Colision con Baldur
    if (baldur_ptr != nullptr && lanza->collidesWithItem(baldur_ptr))
    {
        float px = lanza->x();
        float py = lanza->y();
        float fuerza = lanza->get_fuerza_final();

        baldur_ptr->recibir_impacto();
        sonidos->reproducir_herido();

        if (panel_juego != nullptr)
        {
            if (es_maquina)
                panel_juego->registrar_golpe_maquina(fuerza);
            else
                panel_juego->registrar_golpe_jugador(fuerza);
        }

        if (es_maquina)
            destruir_lanza(lanza_agente, px, py);
        else
            destruir_lanza_jugador(px, py);
    }
}

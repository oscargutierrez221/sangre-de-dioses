#include "widget.h"
#include "ui_widget.h"
#include "entidad.h"
#include <QMessageBox>
#include <QTimer>
#include <QRandomGenerator>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    personaje_elegido = -1;
    panel_juego = nullptr;

    zeuz = nullptr;
    poseidon = nullptr;
    hades = nullptr;
    ares = nullptr;
    baldur_ptr = nullptr;
    agente = nullptr;
    muerdago_sprite = nullptr;

    lanza_zeuz = nullptr;
    lanza_poseidon = nullptr;
    lanza_hades = nullptr;
    lanza_ares = nullptr;
    lanza_agente = nullptr;

    timerJuego = new QTimer(this);

    explosion_borde = nullptr;

    // Configuracion escenas
    setWindowTitle("Sangre de Dioses");
    nivel1 = new QGraphicsScene(ui->graphicsView->rect(), this);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(nivel1);

    ui->stackedWidget_2->setCurrentIndex(0);

}

Widget::~Widget()
{
    limpiar_nivel();

    if (panel_juego != nullptr)
    {
        delete panel_juego;
        panel_juego = nullptr;
    }

    delete ui;
}

void Widget::limpiar_nivel()
{
    if (timerJuego != nullptr)
    {
        timerJuego->stop();
    }

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

    for (obstaculo *en_pantalla : obstaculos)
    {
        en_pantalla->destruirse();
        delete en_pantalla;
    }
    obstaculos.clear();

    if (explosion_borde != nullptr)
    {
        if (explosion_borde->scene() != nullptr)
        {
            explosion_borde->scene()->removeItem(explosion_borde);
        }
        delete explosion_borde;
        explosion_borde = nullptr;
    }

    if (muerdago_sprite != nullptr)
    {
        if (muerdago_sprite->scene() != nullptr)
        {
            muerdago_sprite->scene()->removeItem(muerdago_sprite);
        }
        delete muerdago_sprite;
        muerdago_sprite = nullptr;
    }

    // La escena borra el fondo, personajes, baldur y agente que esten dentro
    if (nivel1 != nullptr)
    {
        delete nivel1;
        nivel1 = nullptr;
    }

    zeuz = nullptr;
    poseidon = nullptr;
    hades = nullptr;
    ares = nullptr;
    agente = nullptr;
    baldur_ptr = nullptr;
    fondo1 = nullptr;
}

void Widget::iniciar_nivel(int personaje)
{
    limpiar_nivel();

    personaje_elegido = personaje;

    ui->stackedWidget_2->setCurrentIndex(1);
    setWindowTitle("Nivel 1 - Juego de Baldur");

    QPixmap mapa(":/new/Fondos/Material/fondoCombate.png");
    nivel1 = new QGraphicsScene(mapa.rect(), this);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(nivel1);

    fondo1 = new QGraphicsPixmapItem(mapa);
    fondo1->setPos(0, 0);
    nivel1->addItem(fondo1);

    // Configuramos el personaje segun cual eligio el jugador
    switch (personaje_elegido)
    {
        case 0:
            QMessageBox::information(this, "Zeuz", "Haz elejido al Dios del rayo");
            zeuz = new entidad();
            zeuz->setPos(150, 210);
            nivel1->addItem(zeuz);
            zeuz->set_inicios_frames({57, 301, 516, 720, 936});
            zeuz->cargar_sprite(":/new/sprite_personajes/Material/SEUZ_sprite.png", 161, 228, 5);
            break;

        case 1:
            QMessageBox::information(this, "Poseidon", "Haz elejido al Dios de los mares");
            poseidon = new entidad();
            poseidon->setPos(150, 210);
            nivel1->addItem(poseidon);
            poseidon->set_inicios_frames({0, 269});
            poseidon->set_anchos_frames({269, 344});
            poseidon->cargar_sprite(":/new/sprite_personajes/Material/poseidon_sprite.png", 344, 407, 2);
            poseidon->setScale(228.0 / 407.0);
            break;

        case 2:
            QMessageBox::information(this, "Hades", "Haz elejido al Dios del inframundo");
            hades = new entidad();
            hades->setPos(150, 210);
            nivel1->addItem(hades);
            hades->set_inicios_frames({0, 290});
            hades->set_anchos_frames({290, 323});
            hades->cargar_sprite(":/new/sprite_personajes/Material/hades_sprite.png", 323, 407, 2);
            hades->setScale(228.0 / 407.0);
            break;

        case 3:
            QMessageBox::information(this, "Ares", "Haz elejido al Dios de la guerra");
            ares = new entidad();
            ares->setPos(150, 210);
            nivel1->addItem(ares);
            ares->set_inicios_frames({0, 229});
            ares->set_anchos_frames({229, 384});
            ares->cargar_sprite(":/new/sprite_personajes/Material/ares_sprite.png", 384, 407, 2);
            ares->setScale(228.0 / 407.0);
            break;
    }

    // Cargamos el agente con un personaje distinto al del jugador
    agente = new entidad();
    switch (personaje_elegido)
    {
        case 0: // jugador eligio Zeus, maquina usa Hades
            agente->set_inicios_frames({0, 290});
            agente->set_anchos_frames({290, 323});
            agente->cargar_sprite(":/new/sprite_personajes/Material/hades_sprite.png", 323, 407, 2);
            agente->setScale(228.0 / 407.0);
            break;

        case 1: // jugador eligio Poseidon, maquina usa Ares
            agente->set_inicios_frames({0, 229});
            agente->set_anchos_frames({229, 384});
            agente->cargar_sprite(":/new/sprite_personajes/Material/ares_sprite.png", 384, 407, 2);
            agente->setScale(228.0 / 407.0);
            break;

        case 2: // jugador eligio Hades, maquina usa Zeus
            agente->set_inicios_frames({57, 301, 516, 720, 936});
            agente->cargar_sprite(":/new/sprite_personajes/Material/SEUZ_sprite.png", 161, 228, 5);
            agente->setScale(228.0 / 228.0);
            break;

        case 3: // jugador eligio Ares, maquina usa Poseidon
            agente->set_inicios_frames({0, 269});
            agente->set_anchos_frames({269, 344});
            agente->cargar_sprite(":/new/sprite_personajes/Material/poseidon_sprite.png", 344, 407, 2);
            agente->setScale(228.0 / 407.0);
            break;
    }

    entidad *jugador = nullptr;
    switch (personaje_elegido)
    {
        case 0:
            jugador = zeuz;
            break;

        case 1:
            jugador = poseidon;
            break;

        case 2:
            jugador = hades;
            break;

        case 3:
            jugador = ares;
            break;

        default:
            break;
    }

    float x_maquina = 1050;
    float y_maquina = 420;

    if (jugador != nullptr)
    {
        y_maquina = jugador->y() + jugador->boundingRect().height();
    }

    agente->setPos(x_maquina, y_maquina);
    nivel1->addItem(agente);

    // Iniciamos el panel
    if (panel_juego != nullptr)
        delete panel_juego;

    panel_juego = new panel(this);
    connect(panel_juego, &panel::turno_maquina, this, &Widget::turno_agente, Qt::QueuedConnection);
    connect(panel_juego, &panel::juego_terminado,  this, &Widget::fin_juego);
    connect(panel_juego, &panel::muerdago_aparecio, this, &Widget::mostrar_muerdago);
    connect(panel_juego, &panel::muerdago_desaparecio, this, &Widget::ocultar_muerdago);
    panel_juego->reiniciar();
    panel_juego->iniciar(ui->graphicsView);

    // Cargamos los obstaculos usando el metodo de la clase obstaculo
    obstaculo::cargar_en_escena(nivel1, obstaculos);

    baldur_ptr = new baldur();
    baldur_ptr->cargar_en_escena(nivel1);

    if (lanza_agente != nullptr)
    {
        destruir_lanza(lanza_agente, 0, 0);
    }

    disconnect(timerJuego, nullptr, this, nullptr);
    connect(timerJuego, &QTimer::timeout, this, &Widget::actualizar_juego);
    timerJuego->start(30);
}

void Widget::on_pushButton_clicked()
{
    iniciar_nivel(0);
}

void Widget::on_pushButton_2_clicked()
{
    iniciar_nivel(1);
}

void Widget::on_pushButton_3_clicked()
{
    iniciar_nivel(2);
}

void Widget::on_pushButton_4_clicked()
{
    iniciar_nivel(3);
}

void Widget::actualizar_juego()
{

    proyectil *lanza = nullptr;

    switch (personaje_elegido)
    {
        case 0:
            lanza = lanza_zeuz;
            break;

        case 1:
            lanza = lanza_poseidon;
            break;

        case 2:
            lanza = lanza_hades;
            break;

        case 3:
            lanza = lanza_ares;
            break;
    }

    if (lanza != nullptr && lanza->esta_en_vuelo())
    {
        lanza->mover();
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

    for (obstaculo* en_pantalla : obstaculos)
    {
        if (en_pantalla->explotando && en_pantalla->termino_explosion())
        {
            en_pantalla->reiniciar();
        }
        else if (!en_pantalla->explotando)
        {
            en_pantalla->mover();
        }
    }

    revisar_colisiones(lanza, false);
    revisar_colisiones(lanza_agente, true);

    if (baldur_ptr != nullptr)
        baldur_ptr->animar();
}

void Widget::on_pushButton_lanzar_clicked()
{
    if (timerJuego == nullptr) return;

    if (panel_juego != nullptr && panel_juego->get_turno() != 0)
    {
        return;
    }

    entidad *personaje = nullptr;
    proyectil *lanza = nullptr;
    int frames_ataque = 0;
    QString ruta_sprite;
    int ancho = 96;
    int alto = 113;
    int offset_x = 60;
    int offset_y = 0;

    switch (personaje_elegido)
    {
        case 0:
            personaje = zeuz;
            lanza = lanza_zeuz;
            frames_ataque = 5;
            ruta_sprite = ":/new/lanzas/Material/lanza_zeuz.png";
            break;

        case 1:
            personaje = poseidon;
            lanza = lanza_poseidon;
            frames_ataque = 2;
            ruta_sprite = ":/new/lanzas/Material/lanza_poseidon.png";
            ancho = 110;
            alto = 130;
            offset_x = 90;
            offset_y = 30;
            break;

        case 2:
            personaje = hades;
            lanza = lanza_hades;
            frames_ataque = 2;
            ruta_sprite = ":/new/lanzas/Material/lanza_hades.png";
            ancho = 110;
            alto = 130;
            offset_x = 90;
            offset_y = 30;
            break;

        case 3:
            personaje = ares;
            lanza = lanza_ares;
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

    if (personaje == nullptr)
    {
        return;
    }

    if (lanza != nullptr && lanza->esta_en_vuelo())
    {
        return;
    }

    int angulo = ui->spinBox_angulo->value();
    int fuerza = ui->spinBox2_fuerza->value();

    // Animacion de ataque y luego lanzamos
    disconnect(timerJuego, nullptr, this, nullptr);
    connect(timerJuego, &QTimer::timeout, this, [this, personaje, frames_ataque, angulo, fuerza, ruta_sprite, ancho, alto, offset_x, offset_y]()
        {
            if (personaje->actualizar_sprite(frames_ataque)) {
                disconnect(timerJuego, nullptr, this, nullptr);
                connect(timerJuego, &QTimer::timeout, this, &Widget::actualizar_juego);
                timerJuego->start(30);

                proyectil *lanza_lista = nullptr;

                switch (personaje_elegido)
                {
                    case 0:
                        lanza_lista = lanza_zeuz;
                        break;

                    case 1:
                        lanza_lista = lanza_poseidon;
                        break;

                    case 2:
                        lanza_lista = lanza_hades;
                        break;

                    case 3:
                        lanza_lista = lanza_ares;
                        break;

                    default:
                        break;
                }

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
            }
        });
    timerJuego->start(170);
}

void Widget::destruir_lanza(proyectil *&lanza, float pos_x, float pos_y)
{
    if (lanza != nullptr) // Si la lanza existe, la destruimos y eliminamos de la escena
    {
        nivel1->removeItem(lanza);
        delete lanza;
        lanza = nullptr;
    }

    if (explosion_borde != nullptr) // De la misma forma, si existe la explosion del borde, la eliminamos
    {
        nivel1->removeItem(explosion_borde);
        delete explosion_borde;
    }

    // Creamos una una explosion cuando la lanza golpee algo
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

void Widget::revisar_colisiones(proyectil *lanza, bool es_maquina)
{
    if (lanza == nullptr || !lanza->esta_en_vuelo())
    {
        return;
    }

    // Si la lanza choca conun borde
    if (lanza->x() > 1376 || lanza->x() < 0 || lanza->y() > 2000 || lanza->y() < 0)
    {
        float px = lanza->x();
        float py = lanza->y();

        if (es_maquina)
        {
            destruir_lanza(lanza_agente, px, py);
            if (panel_juego != nullptr)
            {
                panel_juego->devolver_turno_jugador();
            }
        }
        else
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
        return;
    }

    // Si la lanza choca con un obstaculo
    for (obstaculo* en_pantalla :  obstaculos)
    {
        if (en_pantalla->explotando) continue;

        if (lanza->collidesWithItem(en_pantalla))
        {
            float px = lanza->x();
            float py = lanza->y();

            en_pantalla->explotar();

            if (es_maquina)
            {
                destruir_lanza(lanza_agente, px, py);
                if (panel_juego != nullptr)
                {
                    panel_juego->devolver_turno_jugador();
                }
            }
            else
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
            return;
        }
    }

    if (baldur_ptr != nullptr && lanza->collidesWithItem(baldur_ptr))
    {
        float px = lanza->x();
        float py = lanza->y();
        float fuerza = lanza->get_fuerza_final();

        baldur_ptr->recibir_impacto();

        if (panel_juego != nullptr)
        {
            if (es_maquina)
            {
                panel_juego->registrar_golpe_maquina(fuerza);
            }
            else
            {
                panel_juego->registrar_golpe_jugador(fuerza);
            }
        }

        if (es_maquina)
        {
            destruir_lanza(lanza_agente, px, py);
        }
        else
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
        return;
    }
}

void Widget::turno_agente()
{
    if (agente == nullptr)
        return;

    static int rondas_agente = 0;
    rondas_agente++;

    int margen = 30 - rondas_agente * 2;

    if (margen < 1)
    {
        margen = 1;
    }

    int angulo = 40 + QRandomGenerator::global()->bounded(-margen, margen + 1);
    int fuerza = 85 + QRandomGenerator::global()->bounded(-margen * 2, margen * 2 + 1);

    int frames_ataque = 2;

    if (personaje_elegido == 2)
    {
        frames_ataque = 5;
    }

    QString ruta_lanza = ":/new/lanzas/Material/lanza_hades.png";
    int ancho = 110;
    int alto = 130;
    int offset_x = -90;
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
            offset_x = -60;
            offset_y = 0;
            break;

        case 3:
            ruta_lanza = ":/new/lanzas/Material/lanza_poseidon.png";
            break;

        default:
            break;
    }

    disconnect(timerJuego, nullptr, this, nullptr);
    connect(timerJuego, &QTimer::timeout, this, [this, angulo, fuerza, frames_ataque, ruta_lanza, ancho, alto, offset_x, offset_y]()
        {
            if (agente->actualizar_sprite(frames_ataque))
            {
                disconnect(timerJuego, nullptr, this, nullptr);
                connect(timerJuego, &QTimer::timeout, this, &Widget::actualizar_juego);
                timerJuego->start(30);

                if (lanza_agente == nullptr)
                {
                    lanza_agente = new proyectil();
                }

                lanza_agente->preparar(nivel1, agente->x(), agente->y(), ruta_lanza, ancho, alto, offset_x, offset_y);
                lanza_agente->lanzar(angulo + 90, fuerza);
        }
    });
    timerJuego->start(170);
}

void Widget::mostrar_muerdago()
{
    if (muerdago_sprite != nullptr)
    {
        nivel1->removeItem(muerdago_sprite);
        delete muerdago_sprite;
    }

    muerdago_sprite = new entidad();
    muerdago_sprite->cargar_sprite(":/new/obstaculos/Material/escudo_sprite.png", 80, 80, 1);
    muerdago_sprite->setScale(0.4);

    if (baldur_ptr != nullptr)
    {
        muerdago_sprite->setPos(baldur_ptr->x(), baldur_ptr->y() - 60);
    }

    nivel1->addItem(muerdago_sprite);
}

void Widget::ocultar_muerdago()
{
    if (muerdago_sprite != nullptr)
    {
        nivel1->removeItem(muerdago_sprite);
        delete muerdago_sprite;
        muerdago_sprite = nullptr;
    }
}

void Widget::fin_juego(bool gano_jugador, int pts_jugador, int pts_maquina)
{
    timerJuego->stop();

    QString mensaje;
    if (gano_jugador)
    {
        mensaje = "¡GANASTE!\n\nTus puntos: " + QString::number(pts_jugador) +
                  "\nMaquina: " + QString::number(pts_maquina);
    }
    else
    {
        mensaje = "¡PERDISTE!\n\nTus puntos: " + QString::number(pts_jugador) + "\nMaquina: " + QString::number(pts_maquina);
    }
    QMessageBox::information(this, "Fin del juego", mensaje);
}

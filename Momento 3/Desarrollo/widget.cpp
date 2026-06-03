#include "widget.h"
#include "ui_widget.h"
#include "entidad.h"
#include <QMessageBox>
#include <QTimer>

// ─────────────────────────────────────────────
//  Constructor / Destructor
// ─────────────────────────────────────────────

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    // Nivel
    ui->setupUi(this);
    personaje_elegido = -1;
    panel_juego = nullptr;

    // Personajes
    zeuz = nullptr;
    poseidon = nullptr;
    hades = nullptr;
    ares = nullptr;
    baldur_ptr = nullptr;
    agente = nullptr;
    muerdago_sprite = nullptr;

    timerJuego = new QTimer(this);

    // Configuracion inicial de la escena
    setWindowTitle("Sangre de Dioses");
    nivel1 = new QGraphicsScene(ui->graphicsView->rect(), this);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(nivel1);

    ui->stackedWidget_2->setCurrentIndex(0);

    // Crear el gestor y conectar la señal para reanudar el juego tras animaciones
    gestor = new gestor_combates(this);
    connect(gestor, &gestor_combates::animacion_terminada, this, &Widget::reanudar_juego);
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

// ─────────────────────────────────────────────
//  Limpiar nivel
// ─────────────────────────────────────────────

void Widget::limpiar_nivel()
{
    if (timerJuego != nullptr)
        timerJuego->stop();

    // El gestor libera lanzas y explosion_borde
    gestor->limpiar_lanzas();

    for (obstaculo *en_pantalla : obstaculos)
    {
        en_pantalla->destruirse();
        delete en_pantalla;
    }
    obstaculos.clear();

    if (muerdago_sprite != nullptr)
    {
        if (muerdago_sprite->scene() != nullptr)
            muerdago_sprite->scene()->removeItem(muerdago_sprite);
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

// ─────────────────────────────────────────────
//  Iniciar nivel
// ─────────────────────────────────────────────

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

    // Configurar el personaje del jugador
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

    // Configurar el agente (maquina) con un personaje distinto al del jugador
    agente = new entidad();
    switch (personaje_elegido)
    {
        case 0: // Jugador eligio Zeus, maquina usa Hades
            agente->set_inicios_frames({0, 290});
            agente->set_anchos_frames({290, 323});
            agente->cargar_sprite(":/new/sprite_personajes/Material/hades_sprite.png", 323, 407, 2);
            agente->setScale(228.0 / 407.0);
            break;

        case 1: // Jugador eligio Poseidon, maquina usa Ares
            agente->set_inicios_frames({0, 229});
            agente->set_anchos_frames({229, 384});
            agente->cargar_sprite(":/new/sprite_personajes/Material/ares_sprite.png", 384, 407, 2);
            agente->setScale(228.0 / 407.0);
            break;

        case 2: // Jugador eligio Hades, maquina usa Zeus
            agente->set_inicios_frames({57, 301, 516, 720, 936});
            agente->cargar_sprite(":/new/sprite_personajes/Material/SEUZ_sprite.png", 161, 228, 5);
            agente->setScale(228.0 / 228.0);
            break;

        case 3: // Jugador eligio Ares, maquina usa Poseidon
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

    float x_maquina = 80;
    float y_maquina = 350;

    if (jugador != nullptr)
    {
        x_maquina = jugador->x() - 60;
        y_maquina = jugador->y() + jugador->boundingRect().height() * jugador->scale() * 0.5f;
    }

    agente->setPos(x_maquina, y_maquina);
    nivel1->addItem(agente);

    // Iniciar el panel
    if (panel_juego != nullptr)
        delete panel_juego;

    panel_juego = new panel(this);
    connect(panel_juego, &panel::turno_maquina, this, &Widget::turno_agente, Qt::QueuedConnection);
    connect(panel_juego, &panel::juego_terminado, this, &Widget::fin_juego);
    connect(panel_juego, &panel::muerdago_aparecio, this, &Widget::mostrar_muerdago);
    connect(panel_juego, &panel::muerdago_desaparecio, this, &Widget::ocultar_muerdago);
    panel_juego->reiniciar();
    panel_juego->iniciar(ui->graphicsView);

    // Cargar obstaculos
    obstaculo::cargar_en_escena(nivel1, obstaculos);

    baldur_ptr = new baldur();
    baldur_ptr->cargar_en_escena(nivel1);

    // Dar contexto al gestor de combate con los actores del nivel
    gestor->inicializar(nivel1, panel_juego, baldur_ptr, &obstaculos, timerJuego, zeuz, poseidon, hades, ares, agente, personaje_elegido);

    // Arrancar el loop de juego
    disconnect(timerJuego, nullptr, this, nullptr);
    connect(timerJuego, &QTimer::timeout, this, &Widget::actualizar_juego);
    timerJuego->start(30);
}

// ─────────────────────────────────────────────
//  Botones de seleccion de personaje
// ─────────────────────────────────────────────

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

// ─────────────────────────────────────────────
//  Loop principal del juego
// ─────────────────────────────────────────────

void Widget::actualizar_juego()
{
    gestor->actualizar_lanzas();

    for (obstaculo* en_pantalla : obstaculos)
    {
        if (en_pantalla->explotando && en_pantalla->termino_explosion())
            en_pantalla->reiniciar();
        else if (!en_pantalla->explotando)
            en_pantalla->mover();
    }

    gestor->revisar_colisiones(gestor->get_lanza_jugador(), false);
    gestor->revisar_colisiones(gestor->get_lanza_agente(),  true);

    if (baldur_ptr != nullptr)
        baldur_ptr->animar();
}

// ─────────────────────────────────────────────
//  Reconectar timer tras animacion de ataque
// ─────────────────────────────────────────────

void Widget::reanudar_juego()
{
    disconnect(timerJuego, nullptr, this, nullptr);
    connect(timerJuego, &QTimer::timeout, this, &Widget::actualizar_juego);
    timerJuego->start(30);
}

// ─────────────────────────────────────────────
//  Lanzar jugador
// ─────────────────────────────────────────────

void Widget::on_pushButton_lanzar_clicked()
{
    if (timerJuego == nullptr) return;

    int angulo = ui->spinBox_angulo->value();
    int fuerza = ui->spinBox2_fuerza->value();

    gestor->lanzar_jugador(angulo, fuerza);
}

// ─────────────────────────────────────────────
//  Turno del agente
// ─────────────────────────────────────────────

void Widget::turno_agente()
{
    gestor->turno_agente();
}

// ─────────────────────────────────────────────
//  Muerdago
// ─────────────────────────────────────────────

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
        muerdago_sprite->setPos(baldur_ptr->x(), baldur_ptr->y() - 60);

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

// ─────────────────────────────────────────────
//  Fin de juego
// ─────────────────────────────────────────────

void Widget::fin_juego(bool gano_jugador, int pts_jugador, int pts_maquina)
{
    timerJuego->stop();

    QString mensaje;
    if (gano_jugador)
        mensaje = "¡GANASTE!\n\nTus puntos: " + QString::number(pts_jugador) +
                  "\nMaquina: "               + QString::number(pts_maquina);
    else
        mensaje = "¡PERDISTE!\n\nTus puntos: " + QString::number(pts_jugador) +
                  "\nMaquina: "                + QString::number(pts_maquina);

    QMessageBox::information(this, "Fin del juego", mensaje);
}

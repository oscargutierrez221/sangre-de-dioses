#include "widget.h"
#include "ui_widget.h"
#include "entidad.h"
#include <QMessageBox>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    personaje_elegido = -1;
    zeuz = nullptr;
    poseidon = nullptr;
    hades = nullptr;
    ares = nullptr;
    lanza_zeuz = nullptr;
    lanza_poseidon = nullptr;
    lanza_hades = nullptr;
    lanza_ares = nullptr;
    timerJuego = new QTimer(this);

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
    delete ui;
}

void Widget::actualizar_juego(){

    proyectil *lanza = nullptr;

    switch (personaje_elegido) {
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

        if (lanza != nullptr && lanza->esta_en_vuelo()) {
        lanza->mover();
    }
}

void Widget::on_pushButton_clicked()
{
    // Permite manipular las escenas y los elementos gráficos, como el fondo y los sprites de a cuerdo a la pagina
    ui->stackedWidget_2->setCurrentIndex(1);

    setWindowTitle("Nivel 1 - Juego de Baldur");

    QPixmap mapa(":/new/Fondos/Material/fondoCombate.png");

    // 1. Configuracion del fondo
    nivel1 = new QGraphicsScene(mapa.rect(), this);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(nivel1);

    // 2. agregar el fondo a la escena
    fondo1 = new QGraphicsPixmapItem(mapa);
    fondo1->setPos(0, 0);
    nivel1->addItem(fondo1);

    // 3. Cargar sprite
    QMessageBox::information(this, "Zeuz", "Haz elejido al Dios del rayo");

    personaje_elegido = 0;
    zeuz = new entidad();
    zeuz->setPos(150, 210);
    nivel1->addItem(zeuz);

    // 4. Posicion exacta donde empieza cada frame en el sprite (medido en pixeles)
    zeuz->set_inicios_frames({57, 301, 516, 720, 936});
    zeuz->cargar_sprite(":/new/sprite_personajes/Material/SEUZ_sprite.png", 161, 228, 5); // ancho=161 (el frame mas ancho), alto=228, 5 frames

    // 5. Timer del juego: solo mueve la lanza y lógica general
    disconnect(timerJuego, nullptr, this, nullptr);
    connect(timerJuego, &QTimer::timeout, this, &Widget::actualizar_juego);
    timerJuego->start(30);
}


void Widget::on_pushButton_2_clicked()
{
    // Permite manipular las escenas y los elementos gráficos, como el fondo y los sprites de a cuerdo a la pagina
    ui->stackedWidget_2->setCurrentIndex(1);

    setWindowTitle("Nivel 1 - Juego de Baldur");

    QPixmap mapa(":/new/Fondos/Material/fondoCombate.png");

    // 1. Configuracion del fondo
    nivel1 = new QGraphicsScene(mapa.rect(), this);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(nivel1);

    // 2. agregar el fondo a la escena
    fondo1 = new QGraphicsPixmapItem(mapa);
    fondo1->setPos(0, 0);
    nivel1->addItem(fondo1);

    // 3. Cargar el sprite
    QMessageBox::information(this, "Poseidon", "Haz elejido al Dios de los mares");

    personaje_elegido = 1;
    poseidon = new entidad();
    poseidon->setPos(150, 210);
    nivel1->addItem(poseidon);

    // 4. Sprite 613x407: 2 frames horizontales de distinto ancho (269 y 344 px)
    poseidon->set_inicios_frames({0, 269});
    poseidon->set_anchos_frames({269, 344});
    poseidon->cargar_sprite(":/new/sprite_personajes/Material/poseidon_sprite.png", 344, 407, 2);
    poseidon->setScale(228.0 / 407.0);

    // 5. Timer del juego
    disconnect(timerJuego, nullptr, this, nullptr);
    connect(timerJuego, &QTimer::timeout, this, &Widget::actualizar_juego);
    timerJuego->start(30);
}


void Widget::on_pushButton_3_clicked()
{
    // Permite manipular las escenas y los elementos gráficos, como el fondo y los sprites de a cuerdo a la pagina
    ui->stackedWidget_2->setCurrentIndex(1);

    setWindowTitle("Nivel 1 - Juego de Baldur");

    QPixmap mapa(":/new/Fondos/Material/fondoCombate.png");

    // 1. Configuracion del fondo
    nivel1 = new QGraphicsScene(mapa.rect(), this);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(nivel1);

    // 2. agregar el fondo a la escena
    fondo1 = new QGraphicsPixmapItem(mapa);
    fondo1->setPos(0, 0);
    nivel1->addItem(fondo1);

    // 3. Cargar el sprite
    QMessageBox::information(this, "Hades", "Haz elejido al Dios del inframundo");

    personaje_elegido = 2;
    hades = new entidad();
    hades->setPos(150, 210);
    nivel1->addItem(hades);

    hades->set_inicios_frames({0, 290});
    hades->set_anchos_frames({290, 323});
    hades->cargar_sprite(":/new/sprite_personajes/Material/hades_sprite.png", 323, 407, 2);
    hades->setScale(228.0 / 407.0);

    // 5. Timer del juego
    disconnect(timerJuego, nullptr, this, nullptr);
    connect(timerJuego, &QTimer::timeout, this, &Widget::actualizar_juego);
    timerJuego->start(30);

}

void Widget::on_pushButton_4_clicked()
{
    // Permite manipular las escenas y los elementos gráficos, como el fondo y los sprites de a cuerdo a la pagina
    ui->stackedWidget_2->setCurrentIndex(1);

    setWindowTitle("Nivel 1 - Juego de Baldur");

    QPixmap mapa(":/new/Fondos/Material/fondoCombate.png");

    // 1. Configuracion del fondo
    nivel1 = new QGraphicsScene(mapa.rect(), this);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(nivel1);

    // 2. agregar el fondo a la escena
    fondo1 = new QGraphicsPixmapItem(mapa);
    fondo1->setPos(0, 0);
    nivel1->addItem(fondo1);

    // 3. Cargar el sprite
    QMessageBox::information(this, "Ares", "Haz elejido al Dios de la guerra");

    personaje_elegido = 3;
    ares = new entidad();
    ares->setPos(150, 210);
    nivel1->addItem(ares);

    ares->set_inicios_frames({0, 229});
    ares->set_anchos_frames({229, 384});
    ares->cargar_sprite(":/new/sprite_personajes/Material/ares_sprite.png", 384, 407, 2);
    ares->setScale(228.0 / 407.0);

    // 5. Timer del juego
    disconnect(timerJuego, nullptr, this, nullptr);
    connect(timerJuego, &QTimer::timeout, this, &Widget::actualizar_juego);
    timerJuego->start(30);
}

void Widget::on_pushButton_lanzar_clicked()
{
    if (timerJuego == nullptr) {
        return;
    }

    entidad *personaje = nullptr;
    proyectil *lanza = nullptr;
    int frames_ataque = 0;

    switch (personaje_elegido) {
        case 0:
            personaje = zeuz;
            lanza = lanza_zeuz;
            frames_ataque = 5;
            break;
        case 1:
            personaje = poseidon;
            lanza = lanza_poseidon;
            frames_ataque = 2;
            break;
        case 2:
            personaje = hades;
            lanza = lanza_hades;
            frames_ataque = 2;
            break;
        case 3:
            personaje = ares;
            lanza = lanza_ares;
            frames_ataque = 2;
            break;
        default:
            return;
    }

    if (personaje == nullptr) {
        return;
    }

    // 1. Capturamos los datos del menú estético
    int angulo = ui->spinBox_angulo->value();
    int fuerza = ui->spinBox2_fuerza->value();

    // 2. Pausamos la actualizacion del juego para reproducir ataque
    disconnect(timerJuego, nullptr, this, nullptr);

    // 3. Animacion de ataque segun el personaje elegido
    connect(timerJuego, &QTimer::timeout, this, [this, personaje, frames_ataque]() {
        if (personaje->actualizar_sprite(frames_ataque) == true) {
            disconnect(timerJuego, nullptr, this, nullptr);
            connect(timerJuego, &QTimer::timeout, this, &Widget::actualizar_juego);
        }
    });
    timerJuego->start(170);

    // 4. Creamos la lanza si no existe
    if (lanza == nullptr) {
        lanza = new proyectil();
        nivel1->addItem(lanza);

        switch (personaje_elegido) {
            case 0:
                lanza_zeuz = lanza;
                break;
            case 1:
                lanza_poseidon = lanza;
                break;
            case 2:
                lanza_hades = lanza;
                break;
            case 3:
                lanza_ares = lanza;
                break;
            default:
                return;
        }
    }

    // 5. Sprite y posicion de la lanza segun personaje
    int set_x = 60;
    int set_y = 0;
    int ancho_lanza = 96;
    int alto_lanza = 113;
    QString ruta_lanza;

    switch (personaje_elegido) {
        case 0:
            ruta_lanza = ":/new/lanzas/Material/lanza_zeuz.png";
            break;
        case 1:
            ruta_lanza = ":/new/lanzas/Material/lanza_poseidon.png";
            set_x = 90;
            set_y = 30;
            ancho_lanza = 110;
            alto_lanza = 130;
            break;
        case 2:
            ruta_lanza = ":/new/lanzas/Material/lanza_hades.png";
            set_x = 90;
            set_y = 30;
            ancho_lanza = 110;
            alto_lanza = 130;
            break;
        case 3:
            ruta_lanza = ":/new/lanzas/Material/lanza_ares.png";
            set_x = 90;
            set_y = 30;
            ancho_lanza = 110;
            alto_lanza = 130;
            break;
        default:
            return;
        }

    lanza->setPos(personaje->x() + set_x, personaje->y() + set_y);

    QPixmap sprite_lanza(ruta_lanza);
    lanza->setPixmap(sprite_lanza.scaled(ancho_lanza, alto_lanza, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // 6. Angulo y fuerza con fisicas
    lanza->lanzar(angulo, fuerza);
}


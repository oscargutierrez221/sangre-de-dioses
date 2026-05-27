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

    // 3. agregar el fondo a la escena
    fondo1 = new QGraphicsPixmapItem(mapa);
    fondo1->setPos(0, 0);
    nivel1->addItem(fondo1);

    // Cargar sprite=
    QMessageBox::information(this, "Zeuz", "Haz elejido al Dios del rayo");

    // 1. Creamos el personaje y lo posicionamos en la escena
    zeuz = new entidad();
    zeuz->setPos(150, 210);
    nivel1->addItem(zeuz);

    // Posicion exacta donde empieza cada frame en el sprite (medido en pixeles)
    zeuz->set_inicios_frames({57, 301, 516, 720, 936});
    zeuz->cargar_sprite(":/new/sprite_personajes/Material/SEUZ_sprite.png", 161, 228, 5); // ancho=161 (el frame mas ancho), alto=228, 5 frames

    // 2. Temporizador para la velocidad del sprite
    timerJuego = new QTimer(this);
    connect(timerJuego, &QTimer::timeout, this, [this]() {
        zeuz->actualizar_sprite();
    });

    // // 3. Velocidad del sprite
    // timerJuego->start(800);

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

    // 3. agregar el fondo a la escena
    fondo1 = new QGraphicsPixmapItem(mapa);
    fondo1->setPos(0, 0);
    nivel1->addItem(fondo1);


    QMessageBox::information(this, "Poseidon", "Haz elejido al Dios de los mares");
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

    // 3. agregar el fondo a la escena
    fondo1 = new QGraphicsPixmapItem(mapa);
    fondo1->setPos(0, 0);
    nivel1->addItem(fondo1);


    QMessageBox::information(this, "Hades", "Haz elejido al Dios del inframundo");
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

    // 3. agregar el fondo a la escena
    fondo1 = new QGraphicsPixmapItem(mapa);
    fondo1->setPos(0, 0);
    nivel1->addItem(fondo1);


    QMessageBox::information(this, "Hera", "Haz elejido a la Diosa de la guerra");
}

void Widget::on_pushButton_lanzar_clicked()
{
    // 1. Capturamos los datos del menú estético
    int angulo = ui->spinBox_angulo->value();
    int fuerza = ui->spinBox2_fuerza->value();


    // 2. Evitamos conexiones repetidas del mismo timer
    disconnect(timerJuego, nullptr, this, nullptr);

    // 3. Creamos una conexion para controlar la animacion del ataque de Zeus
    connect(timerJuego, &QTimer::timeout, this, [this]() {
        // Ejecuta la animación.
        if (zeuz->actualizar_sprite(6) == true) {
            timerJuego->stop();
        }
    });

    // 4. Iniciamos el temporizador para la animación del ataque de Zeus
    timerJuego->start(170); // Entre menor sea el valor mas rapdo es el sprite

    // 5. Sigue implementar la gabalina
}



#include "entidad.h"
#include "niveles.h"

niveles::niveles() {}

niveles::cargar_nivel_zeuz(){
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
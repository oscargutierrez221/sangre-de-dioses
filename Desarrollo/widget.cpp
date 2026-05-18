#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

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
    // Esta línea le ordena al StackedWidget cambiar a la otra página (page_4)
    ui->stackedWidget_2->setCurrentIndex(1);

    // 1. Configuracion del fondo
    setWindowTitle("Nivel 1 - Juego de Baldur");

    QPixmap fondo_combate(":/new/Fondos/Material/fondoCombate.png");
    fondo1 = new QGraphicsPixmapItem(fondo_combate);
    fondo1->setPos(0, 0);
    nivel1->addItem(fondo1);

    // Aquí abajo pones lo que quieres que pase con los sprites de Zeus
    QMessageBox::information(this, "Zeuz", "Haz elejido al Dios del rayo");
}


void Widget::on_pushButton_2_clicked()
{
    // Esta línea le ordena al StackedWidget cambiar a la otra página (page_4)
    ui->stackedWidget_2->setCurrentIndex(1);

    QMessageBox::information(this, "Poseidon", "Haz elejido al Dios de los mares");
}


void Widget::on_pushButton_3_clicked()
{
    // Esta línea le ordena al StackedWidget cambiar a la otra página (page_4)
    ui->stackedWidget_2->setCurrentIndex(1);

    QMessageBox::information(this, "Hades", "Haz elejido al Dios del inframundo");
}


void Widget::on_pushButton_4_clicked()
{
    // Esta línea le ordena al StackedWidget cambiar a la otra página (page_4)
    ui->stackedWidget_2->setCurrentIndex(1);

    QMessageBox::information(this, "Hera", "Haz elejido a la Diosa de la guerra");
}


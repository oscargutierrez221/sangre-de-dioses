#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Configuracion
    setWindowTitle("Sangre de Dioses");
    scena = new QGraphicsScene(ui->graphicsView->rect(), this);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(scena);

    // Anadir fondo de pantalla
    QPixmap fondo_nivel1(":/new/Fondos/Material/Fondo pantalla nivel 1.png");
    fondo1 = new QGraphicsPixmapItem(fondo_nivel1);
    fondo1->setPos(0,0);
    scena->addItem(fondo1);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QMessageBox::information(this, "Zeuz", "Haz elejido al Dios del rayo");
}


void Widget::on_pushButton_2_clicked()
{
    QMessageBox::information(this, "Poseidon", "Haz elejido al Dios de los mares");
}


void Widget::on_pushButton_3_clicked()
{
    QMessageBox::information(this, "Hades", "Haz elejido al Dios del inframundo");
}


void Widget::on_pushButton_4_clicked()
{
    QMessageBox::information(this, "Hera", "Haz elejido a la Diosa de la guerra");
}


#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include  "entidad.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_lanzar_clicked();

private:
    Ui::Widget *ui;
    QGraphicsScene *nivel1;
    QGraphicsPixmapItem *fondo1;

    // Configuracion sprite
    QTimer *timerJuego;  // El temporizador para controlar el bucle de movimiento

    // Configuracion personajes
    entidad *zeuz;
};
#endif // WIDGET_H

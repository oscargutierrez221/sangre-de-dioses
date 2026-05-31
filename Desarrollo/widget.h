#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include  "entidad.h"
#include  "proyectil.h"


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

    void actualizar_juego();

private:
    // Elementos gráficos
    Ui::Widget *ui;
    QGraphicsScene *nivel1;
    QGraphicsPixmapItem *fondo1;

    // Temporizadores
    QTimer *timerJuego;

    // Configuracion personajes (0=Zeus, 1=Poseidon, 2=Hades, 3=Ares)
    int personaje_elegido;
    entidad *zeuz;
    entidad *poseidon;
    entidad *hades;
    entidad *ares;

    // Configuracion lanzas
    proyectil *lanza_zeuz;
    proyectil *lanza_poseidon;
    proyectil *lanza_hades;
    proyectil *lanza_ares;
};
#endif // WIDGET_H

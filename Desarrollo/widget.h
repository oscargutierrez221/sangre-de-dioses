#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <vector>
#include "entidad.h"
#include "proyectil.h"
#include "obstaculo.h"
#include "baldur.h"
#include "panel.h"


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

    void turno_agente();

    void fin_juego(bool gano_jugador, int pts_jugador, int pts_maquina);

    void mostrar_muerdago();

    void ocultar_muerdago();

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
    baldur *baldur_ptr;
    entidad *agente;
    entidad *muerdago_sprite;

    // Configuracion lanzas
    proyectil *lanza_zeuz;
    proyectil *lanza_poseidon;
    proyectil *lanza_hades;
    proyectil *lanza_ares;
    proyectil *lanza_agente;

    // Panel
    panel *panel_juego;

    // Configuracion de los obstaculos
    std::vector<obstaculo*> obstaculos; // Lista par alos obstaculos que pongamos en la pantaalla

    entidad *explosion_borde;

    void iniciar_nivel(int personaje);
    void revisar_colisiones(proyectil *lanza, bool es_maquina);
    void destruir_lanza(proyectil *&lanza, float pos_x, float pos_y);
    void limpiar_nivel();

};
#endif // WIDGET_H

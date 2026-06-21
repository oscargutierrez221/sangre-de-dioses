#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <vector>
#include "entidad.h"
#include "obstaculo.h"
#include "baldur.h"
#include "panel.h"
#include "gestor_combates.h"


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
    void reanudar_juego();      // reconecta el timer tras la animacion de ataque

    void turno_agente();

    void fin_juego(bool gano_jugador, int pts_jugador, int pts_maquina);

    void mostrar_muerdago();
    void ocultar_muerdago();

private:
    // Elementos graficos
    Ui::Widget *ui;
    QGraphicsScene *nivel1;
    QGraphicsPixmapItem *fondo1;

    // Temporizador principal
    QTimer *timerJuego;

    // Personajes (0=Zeus, 1=Poseidon, 2=Hades, 3=Ares)
    int personaje_elegido;
    entidad *zeuz;
    entidad *poseidon;
    entidad *hades;
    entidad *ares;
    baldur  *baldur_ptr;
    entidad *agente;
    entidad *muerdago_sprite;

    // Panel de puntuacion y turno
    panel *panel_juego;

    // Obstaculos en pantalla
    std::vector<obstaculo*> obstaculos;

    // Gestor de toda la logica de combate
    gestor_combates *gestor;

    void iniciar_nivel(int personaje);
    void limpiar_nivel();
};

#endif // WIDGET_H

#ifndef PANEL_H
#define PANEL_H
#include <QWidget>
#include <QLabel>
#include <QTimer>

class panel : public QWidget
{
    Q_OBJECT
private:
    // Puntos
    int puntos_jugador;
    int puntos_maquina;

    // Turno: 0 = jugador, 1 = maquina
    int turno_actual;

    // Tiempo restante en segundos
    int segundos_restantes;

    // Si el muerdago esta en escena ahora mismo
    bool muerdago_activo;

    // Contador para la aparicion del muerdago
    int contador_muerdago;
    int falta_para_muerdago;

    // Labels visibles en pantalla
    QLabel *label_jugador;
    QLabel *label_maquina;
    QLabel *label_tiempo;
    QLabel *label_turno;

    // Timer que cuenta el tiempo
    QTimer *timer_tiempo;

    // Timer que controla cuanto dura el muerdago en pantalla
    QTimer *timer_muerdago;

    void actualizar_labels();
    void generar_ticks_muerdago(); // sortea cuando aparece el proximo muerdago

signals:
    void turno_maquina();       // le avisa al Widget que es el turno de la maquina
    void juego_terminado(bool gano_jugador, int pts_jugador, int pts_maquina);
    void muerdago_aparecio();   // le avisa al Widget que cargue el sprite del muerdago
    void muerdago_desaparecio();

public slots:
    void tick_tiempo(); // se llama cada segundo

public:
    panel(QWidget *parent = nullptr);

    void iniciar(QWidget *contenedor); // lo posiciona sobre el graphicsView
    void reiniciar();

    // El Widget llama esto cuando una lanza golpea a Baldur
    void registrar_golpe_jugador(float fuerza_final);
    void registrar_golpe_maquina(float fuerza_final);

    void devolver_turno_jugador();
    int get_turno(); // 0 = jugador, 1 = maquina
};

#endif // PANEL_H

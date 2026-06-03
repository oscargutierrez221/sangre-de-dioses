#include "panel.h"
#include <QRandomGenerator>

panel::panel(QWidget *parent) : QWidget(parent)
{
    puntos_jugador = 0;
    puntos_maquina = 0;
    turno_actual = 0;
    segundos_restantes = 300;
    muerdago_activo = false;
    contador_muerdago = 0;

    QString estilo = "color: white; font-size: 18px; font-weight: bold;" "background: rgba(0,0,0,140); padding: 4px 10px; border-radius: 6px;";

    label_jugador = new QLabel("Tu: 0", this);
    label_maquina = new QLabel("Maquina: 0", this);
    label_tiempo = new QLabel("5:00", this);
    label_turno = new QLabel("Tu turno", this);

    label_jugador->setStyleSheet(estilo);
    label_maquina->setStyleSheet(estilo);
    label_turno->setStyleSheet(estilo);
    label_tiempo->setStyleSheet("color: yellow; font-size: 22px; font-weight: bold;" "background: rgba(0,0,0,140); padding: 4px 10px; border-radius: 6px;");

    timer_tiempo = new QTimer(this);
    connect(timer_tiempo, &QTimer::timeout, this, &panel::tick_tiempo);

    timer_muerdago = new QTimer(this);
    timer_muerdago->setSingleShot(true);
    connect(timer_muerdago, &QTimer::timeout, this, [this]()
    {
        muerdago_activo = false;
        emit muerdago_desaparecio();
        generar_ticks_muerdago();
    });

    generar_ticks_muerdago();
}

void panel::generar_ticks_muerdago()
{
    falta_para_muerdago = QRandomGenerator::global()->bounded(15, 61);
    contador_muerdago = 0;
}

void panel::iniciar(QWidget *contenedor)
{
    setParent(contenedor);
    setGeometry(contenedor->rect());
    setAttribute(Qt::WA_TransparentForMouseEvents);

    int x = contenedor->width() - 180;

    label_jugador->move(x, 10);
    label_maquina->move(x, 40);
    label_turno->move(x, 70);
    label_tiempo->move(contenedor->width() / 2 - 40, 10);

    label_jugador->show();
    label_maquina->show();
    label_tiempo->show();
    label_turno->show();

    show();
    raise();

    timer_tiempo->start(1000);
}

void panel::reiniciar()
{
    puntos_jugador = 0;
    puntos_maquina = 0;
    turno_actual = 0;
    segundos_restantes = 300;
    muerdago_activo = false;
    generar_ticks_muerdago();
    actualizar_labels();
    timer_tiempo->start(1000);
}

void panel::tick_tiempo()
{
    segundos_restantes--;

    int min = segundos_restantes / 60;
    int seg = segundos_restantes % 60;
    label_tiempo->setText(QString("%1:%2").arg(min).arg(seg, 2, 10, QChar('0')));

    contador_muerdago++;
    if (!muerdago_activo && contador_muerdago >= falta_para_muerdago)
    {
        muerdago_activo = true;
        emit muerdago_aparecio();
        timer_muerdago->start(8000);
    }

    if (segundos_restantes <= 0)
    {
        timer_tiempo->stop();
        bool gano_jugador = puntos_jugador >= puntos_maquina;
        emit juego_terminado(gano_jugador, puntos_jugador, puntos_maquina);
    }
}

void panel::actualizar_labels()
{
    label_jugador->setText("Tu: " + QString::number(puntos_jugador));
    label_maquina->setText("Maquina: " + QString::number(puntos_maquina));
    label_turno->setText(turno_actual == 0 ? "Tu turno" : "Turno maquina");
}

void panel::registrar_golpe_jugador(float fuerza_final)
{
    int puntos = (int)(fuerza_final * 10);

    if (muerdago_activo)
    {
        timer_tiempo->stop();
        emit juego_terminado(true, puntos_jugador + puntos, puntos_maquina);
        return;
    }

    puntos_jugador += puntos;
    turno_actual = 1;
    actualizar_labels();
    emit turno_maquina();
}

void panel::registrar_golpe_maquina(float fuerza_final)
{
    int puntos = (int)(fuerza_final * 10);

    if (muerdago_activo)
    {
        timer_tiempo->stop();
        emit juego_terminado(false, puntos_jugador, puntos_maquina + puntos);
        return;
    }

    puntos_maquina += puntos;
    turno_actual = 0;
    actualizar_labels();
}

int panel::get_turno()
{
    return turno_actual;
}

void panel::devolver_turno_jugador()
{
    turno_actual = 0;
    actualizar_labels();
}

void panel::pasar_turno_maquina()
{
    turno_actual = 1;
    actualizar_labels();
    emit turno_maquina();
}

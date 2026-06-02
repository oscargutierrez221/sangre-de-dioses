#include "efectos_sonido.h"
#include <QDebug>

efectos_sonido::efectos_sonido(QObject *parent)
{
    // Efectos sonido
    sonido_explosion = new QSoundEffect(parent);
    sonido_explosion->setSource(QUrl("qrc:/new/efectos_sonido/Material/Efectos_sonido/bomba_efecto_sonido.wav"));
    sonido_explosion->setVolume(1.0);

    sonido_herido = new QSoundEffect(parent);
    sonido_herido->setSource(QUrl("qrc:/new/efectos_sonido/Material/Efectos_sonido/herido_efecto_sonido.wav"));
    sonido_herido->setVolume(1.0);

    // Musica nivel
    musica_nivel = new QMediaPlayer(parent);
    salida_audio = new QAudioOutput(parent);
    musica_nivel->setAudioOutput(salida_audio);
    musica_nivel->setSource(QUrl("qrc:/new/efectos_sonido/Material/Efectos_sonido/musica_scena_efecto_sonido.wav"));
    salida_audio->setVolume(0.5);
    musica_nivel->setLoops(QMediaPlayer::Infinite); // Se repite siempre que se termine
}


void efectos_sonido::reproducir_explosion()
{
    qDebug() << "[Sonido] Status:" << sonido_explosion->status()
             << "| Source:" << sonido_explosion->source();

    if (sonido_explosion->isPlaying())
    {
        sonido_explosion->stop();
    }

    sonido_explosion->play();
}

void efectos_sonido::reproducir_herido()
{
    qDebug() << "[Sonido] Status:" << sonido_herido->status()
             << "| Source:" << sonido_herido->source();
    if (sonido_herido->isPlaying())
    {
        sonido_herido->stop();
    }

    sonido_herido->play();
}

void efectos_sonido::reproducir_musica_nivel()
{
    musica_nivel->play();
}

void efectos_sonido::detener_musica_nivel()
{
    musica_nivel->stop();
}
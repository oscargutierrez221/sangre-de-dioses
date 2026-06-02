#ifndef EFECTOS_SONIDO_H
#define EFECTOS_SONIDO_H

#include <QAudioOutput>
#include <QMediaPlayer>
#include <QObject>
#include <QSoundEffect>
#include <QUrl>

class efectos_sonido {
private:
  QSoundEffect *sonido_explosion;
  QSoundEffect *sonido_herido;

  QMediaPlayer *musica_nivel;
  QAudioOutput *salida_audio;

public:
  explicit efectos_sonido(QObject *parent = nullptr);

  void reproducir_explosion();
  void reproducir_herido();

  void reproducir_musica_nivel();
  void detener_musica_nivel();
};

#endif // EFECTOS_SONIDO_H

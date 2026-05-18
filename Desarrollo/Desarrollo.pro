QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    apolo.cpp \
    artemisa.cpp \
    baldur.cpp \
    entidad.cpp \
    heroe.cpp \
    jugador.cpp \
    loki.cpp \
    main.cpp \
    muerdago.cpp \
    objetivo.cpp \
    obstaculo.cpp \
    personaje.cpp \
    proyectil.cpp \
    widget.cpp

HEADERS += \
    apolo.h \
    artemisa.h \
    baldur.h \
    entidad.h \
    heroe.h \
    jugador.h \
    loki.h \
    muerdago.h \
    objetivo.h \
    obstaculo.h \
    personaje.h \
    proyectil.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Material/ZEUZ.png

RESOURCES += \
    imagenes.qrc

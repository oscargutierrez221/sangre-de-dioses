<div align="center">

<img src="Momento 4/Informe/Material/Escudo-UdeA.svg" height="250" alt="Universidad de Antioquia"/>

# ⚔️ Sangre de Dioses

**Proyecto Final — Informática 2 · Grupo 1**  
**Universidad de Antioquia · Facultad de Ingeniería**

<br/>

[![Qt](https://img.shields.io/badge/Qt-6.x-41CD52?style=for-the-badge&logo=qt&logoColor=white)](https://www.qt.io/)
[![C++](https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Arch Linux](https://img.shields.io/badge/Arch_Linux-1793D1?style=for-the-badge&logo=arch-linux&logoColor=white)](https://archlinux.org/)
[![GitHub](https://img.shields.io/badge/GitHub-Repositorio-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/oscargutierrez221/sangre-de-dioses)

</div>

---

## 👥 Equipo

| Integrante | GitHub |
|---|---|
| Oscar David Gutiérrez Hernández | [@oscargutierrez221](https://github.com/oscargutierrez221) |

**Curso:** Informática 2 — Grupo 1  
**Estado:** Completado ✅

---

## 🎮 Descripción

**Sangre de Dioses** es un videojuego 2D de vista lateral desarrollado en C++ con Qt, ambientado en la mitología nórdica y griega. El jugador elige a uno de cuatro dioses olímpicos y debe lanzar su arma característica contra Baldur usando física parabólica real, esquivando escudos flotantes y compitiendo en turnos contra un agente autónomo que mejora su precisión con cada ronda.

La partida termina cuando se acaba el tiempo (5 minutos) o cuando alguien golpea a Baldur mientras el muérdago está activo — condición de victoria inmediata.

---

## Características

- **Física parabólica real** — gravedad y resistencia del aire, implementados desde cero sin librerías externas

- **4 personajes jugables** — Zeus, Poseidón, Hades y Ares, cada uno con su propio sprite y lanza
- **Obstáculos móviles** — escudos que se mueven arriba y abajo y explotan al recibir impactos
- **Baldur animado** — ríe continuamente y salta de posición al recibir golpes
- **Muérdago aleatorio** — aparece en momentos aleatorios y activa la condición de victoria inmediata
- **Agente autónomo** — la máquina lanza automáticamente y mejora su precisión ronda a ronda
- **Panel de juego** — puntos en tiempo real, cuenta regresiva de 5 minutos y turno actual
- **Efectos de sonido y música** — explosiones, impactos y música de fondo en loop

---

## 🗂️ Estructura del repositorio

```
sangre-de-dioses/
├── Momento 1/
│   ├── Informe preliminar/        ← Planteamiento inicial
│   ├── Escenarios/                ← Bocetos de niveles
│   └── Sprites/                   ← Sprites iniciales
│
├── Momento 2/
│   ├── Informe descriptivo/       ← Diseño de clases y arquitectura
│   └── Material/                  ← Diagramas UML inicial
│
├── Momento 3/
│   └── Desarrollo/                ← Código fuente completo
│       ├── *.h / *.cpp            ← Clases del juego
│       ├── widget.ui              ← Interfaz Qt Designer
│       ├── imagenes.qrc           ← Recursos (sprites, sonidos)
│       └── Material/              ← Assets (sprites, fondos, audio)
│
├── Momento 4/
│   ├── Ejecutables/
│   │   └── SangreDeDioses.AppImage  ← Ejecutable Linux
│   │   └── SangreDeDioses.exe       ← Ejecutable Windows
│   └── Informe/
│       └── sangre_de_dioses_documentacion.md ← Documentación completa del proyecto
│
├── Momento 5/
│   ├── Trailer/                   ← Video trailer del videojuego
│   └── Video codigo/              ← Video explicativo del código y ejecución
│
└── README.md
```

---

## 🚀 Instalación y ejecución

### Requisitos

- Ordenador con Windows o Linux
### Descarga
- Clona el repositorio: https://github.com/oscargutierrez221/sangre-de-dioses.git


### Ejecutable Linux (AppImage)

```bash
chmod +x "Momento 4/Ejecutables/SangreDeDioses.AppImage"
./"Momento 4/Ejecutables/SangreDeDioses.AppImage"
```

---

## 🕹️ Cómo jugar

1. Elegir un personaje en la pantalla de inicio
2. Ajustar el **ángulo** (0–90°) y la **fuerza** con los spinboxes
3. Presionar **Lanzar** — la lanza sale con física parabólica real
4. Esquivar los escudos flotantes para llegar a Baldur
5. Cuando aparezca el aviso **MUÉRDAGO ACTIVO**, golpear a Baldur para ganar instantáneamente
6. Si no, ganar acumulando más puntos que la máquina antes de que acaben los 5 minutos

> **Tip:** la fuerza con la que llega la lanza determina los puntos. Lanzar con más fuerza desde cerca da más puntos que una lanza débil desde lejos.

---

## 🛠️ Tecnologías

<div align="center">

| Tecnología | Uso |
|---|---|
| <img src="https://img.shields.io/badge/C++-17-00599C?logo=cplusplus&logoColor=white"/> | Lenguaje principal |
| <img src="https://img.shields.io/badge/Qt-6.x-41CD52?logo=qt&logoColor=white"/> | Framework gráfico, audio y UI |
| <img src="https://img.shields.io/badge/Qt_Multimedia-41CD52?logo=qt&logoColor=white"/> | QSoundEffect + QMediaPlayer |
| <img src="https://img.shields.io/badge/Arch_Linux-1793D1?logo=arch-linux&logoColor=white"/> | Entorno de desarrollo |
| <img src="https://img.shields.io/badge/GitHub-181717?logo=github&logoColor=white"/> | Control de versiones |

</div>

---

## 📄 Documentación

La documentación completa del proyecto está en:

📁 [`Momento 4/Informe/sangre_de_dioses_documentacion.md`](Momento%204/Informe/sangre_de_dioses_documentacion.md)

Incluye introducción, arquitectura, algoritmos, físicas, guía de instalación, resultados y conclusiones.

---

<div align="center">

**Universidad de Antioquia · Facultad de Ingeniería · Informática 2 · 2026-1**

<div align="center">

<img src="Momento 4/Informe/Material/Escudo-UdeA.svg" height="250" alt="Universidad de Antioquia"/>
</div>

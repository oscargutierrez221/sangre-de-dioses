# Sangre de Dioses — Documentación del Proyecto

---

## Índice de Contenidos
1. [1. Introducción](#1-introducción)
2. [2. Planteamiento del problema](#2-planteamiento-del-problema)
3. [3. Definición general y objetivos](#3-definición-general-y-objetivos)
   - [Objetivos principales](#objetivos-principales)
4. [4. Especificación de requerimientos](#4-especificación-de-requerimientos)
   - [Funcionales](#funcionales)
   - [Restricciones y dependencias](#restricciones-y-dependencias)
5. [5. Metodología y planificación](#5-metodología-y-planificación)
6. [6. Diseño y arquitectura del sistema](#6-diseño-y-arquitectura-del-sistema)
   - [Jerarquía del sistema](#jerarquía-del-sistema)
   - [Descripción de cada clase](#descripción-de-cada-clase)
7. [7. Desarrollo e implementación](#7-desarrollo-e-implementación)
   - [Físicas parabólicas](#físicas-parabólicas)
   - [Agente autónomo](#agente-autónomo)
   - [Sistema de puntos](#sistema-de-puntos)
   - [Comunicación entre clases](#comunicación-entre-clases)
8. [8. Procedimientos de prueba](#8-procedimientos-de-prueba)
9. [9. Guía de instalación y uso](#9-guía-de-instalación-y-uso)
   - [Requisitos](#requisitos)
   - [Instalación](#instalación)
   - [Cómo jugar](#cómo-jugar)
10. [10. Resultados y discusión](#10-resultados-y-discusión)
    - [Limitaciones actuales](#limitaciones-actuales)
    - [Mejoras planeadas](#mejoras-planeadas)
11. [11. Conclusiones](#11-conclusiones)
12. [12. Referencias](#12-referencias)

---

## 1. Introducción

<div align="justify">

**"Sangre de Dioses"** es un videojuego 2D de vista lateral que desarrollé en `C++` usando el framework `Qt-creator` y su interfaz gráfica `Qt-Designer`. El juego está ambientado en la mitología nórdica y griega, donde el jugador encarna a una deidad que debe lanzar su arma característica contra Baldur, el dios nórdico de la luz, en un duelo de precisión y estrategia.

</div>

<div align="justify">

El proyecto nació como un trabajo académico que realicé para la asignatura de **Informática II** de la Facultad de Ingeniería, específicamente del segundo semestre de Ingeniería en Telecomunicaciones de la Universidad de Antioquia. Lo diseñé con el objetivo de aplicar conceptos de la `POO` (Programación Orientada a Objetos) como herencia, polimorfismo, encapsulamiento y diseño de clases en un contexto real y entretenido. Está dirigido principalmente a estudiantes que quieren y deben aplicar y consolidar los conocimientos de `C++` que he visto a lo largo del semestre; para esto planteé la construcción de un juego funcional desde cero usando `C++` y `Qt`.

</div>

<blockquote>
<div align="justify">

<strong>INFORMACIÓN:</strong> Originalmente, el proyecto consistía en 2 niveles, pero por temas de tiempo decidí implementar únicamente un nivel y hacerlo lo mejor que pudiera. Por esto, he combinado 2 mitologías: Nórdica (originalmente el primer nivel) y Griega (originalmente el segundo nivel) para crear un solo nivel Nórdico-Griego.

</div>

</blockquote>

---

## 2. Planteamiento del problema

<div align="justify">

Aprender programación orientada a objetos con ejemplos de consola o ejercicios puede volverse monótono y difícil de motivar. La pregunta que me planteé y que dio origen a este proyecto fue: ¿cómo se ve la `POO` aplicada a algo que la gente realmente usa, como un videojuego?
</div>


<div align="justify">

Con Sangre de Dioses respondí a esa pregunta construyendo un juego completo que demuestra en la práctica cómo organicé un sistema con múltiples clases, cómo logré que se comunicaran entre ellas, y cómo integré las físicas, la lógica de juego, los gráficos y el sonido para que convivieran en una misma aplicación sin convertirse en un desastre de código.
</div>


---

## 3. Definición general y objetivos

<div align="justify">

El juego consiste en un nivel donde el jugador elige un personaje (Zeus, Poseidón, Hades o Ares), cada uno con su propia lanza, y debe lanzarla contra Baldur usando un ángulo y una fuerza que controla manualmente. Los escudos flotantes actúan como obstáculos que bloquean el camino. La máquina también juega, alternando turnos con el jugador. Gana quien acumule más puntos al acabarse el tiempo, o quien golpee a Baldur mientras el muérdago está en escena.

</div>

### Objetivos principales

<div align="justify">

- Aplicar y consolidar mis conocimientos de `POO` como herencia, polimorfismo, encapsulamiento y diseño de clases.
- Implementar por mi cuenta un sistema de físicas parabólicas realista hecho a mano, sin recurrir a librerías externas de física.
- Construir una arquitectura de clases limpia y bien separada por responsabilidades.
- Crear un agente autónomo que mejore su precisión con cada ronda.
- Desarrollar un sistema de puntuación que dependa de la fuerza de impacto final.
- Integrar efectos de sonido y música de fondo.

</div>

---

## 4. Especificación de requerimientos

### Funcionales

<div align="justify">

- El jugador puede elegir entre 4 personajes, cada uno con su propio sprite y lanza.
- La lanza sigue una trayectoria parabólica afectada por gravedad y resistencia del aire.
- Al chocar con un obstáculo, borde o Baldur, aparece una animación de explosión y suena un efecto de audio.
- Baldur se mueve entre posiciones al recibir un golpe.
- El muérdago aparece aleatoriamente durante la partida y activa una condición de victoria inmediata.
- La máquina lanza automáticamente después del turno del jugador y mejora su precisión con cada ronda.
- El panel muestra en tiempo real los puntos de cada deidad, el tiempo restante y el turno actual.
- La partida termina a los 5 minutos o cuando alguien golpea a Baldur con el muérdago activo.

</div>

### Restricciones y dependencias

<div align="justify">

- Requerí de `Qt` con los módulos `widgets` (para el entorno gráfico del proyecto) y `multimedia` (para el audio).
- Tuve prohibido el uso de librerías externas de física y otras no autorizadas en clase, ya que mi meta era implementar las físicas desde cero.
- Desarrollé y probé el juego en `Qt-Creator` sobre mi escritorio `Arch-Linux`, y también generé ejecutables tanto para `Windows` como para `Linux`.
- Registré todos los sprites y sonidos en el archivo de recursos `.qrc`.

</div>

---

## 5. Metodología y planificación

<div align="justify">

Para el desarrollo del proyecto seguí un enfoque **incremental e iterativo**, parecido a lo que en la industria se conoce como metodología ágil, adaptándolo al ritmo de mi trabajo académico individual. En vez de planear todo desde el principio y construirlo de una sola vez, fui armando el juego por capas:

</div>

<div align="justify">

1. **Base gráfica** — Cargué el fondo, los sprites de personajes y la navegación entre pantallas.
2. **Lanza funcional** — Logré que el objeto saliera en pantalla y se moviera en línea recta.
3. **Físicas** — Le agregué parábola, gravedad y resistencia del aire a la lanza.
4. **Obstáculos** — Creé los escudos que se mueven y explotan al recibir un impacto.
5. **Baldur** — Diseñé al objetivo principal con su animación de risa y reacción al golpe.
6. **Sistema de turnos y puntos** — Implementé el panel, el agente autónomo y la condición de victoria.
7. **Audio** — Integré efectos de sonido y música de fondo.
8. **Refactorización** — Moví la lógica de `Widget` a clases especializadas (`gestor_combates`, `panel`, etc.).

</div>

<div align="justify">

Debido al tiempo disponible decidí implementar únicamente un nivel, y por temas de consistencia en la narrativa tomé la decisión de implementar una mezcla entre mitología nórdica y griega. Debido a esto, me centré en que, aunque fuera un único nivel, quedara lo mejor posible.

</div>

---

## 6. Diseño y arquitectura del sistema

<div align="justify">

Diseñé el proyecto utilizando una arquitectura en capas donde asigné a cada clase una responsabilidad bien definida. Acá presento la jerarquía completa:

</div>

### Jerarquía del sistema

```
entidad  (base gráfica de todo)
├── proyectil       (la lanza en vuelo)
├── obstaculo       (los escudos flotantes)
└── baldur          (el objetivo principal)

motor_fisico        (cálculos de física pura)
gestor_combates     (coordina el combate completo)
panel               (puntos, tiempo, turnos y muérdago)
efectos_sonido      (todos los audios del juego)
Widget              (interfaz Qt, conecta todo)
```

<div align="justify">

Sin embargo, para que pueda apreciarse de mejor manera, elaboré el siguiente diagrama de clases:

</div>

![Diagrama de clases final proyecto](<Material/Diagrama de clases final.png>)

### Descripción de cada clase

**`entidad`**

<div align="justify">

Es la base de todos los objetos visuales del juego. Hereda de `QGraphicsPixmapItem`, lo que significa que cualquier `entidad` que programé puede vivir en la escena de `Qt` y dibujarse en pantalla. Con ella manejo la carga de spritesheets y el avance de frames para animar personajes y efectos. Todo lo que se ve en pantalla, desde Zeus hasta la explosión, es una `entidad` o hereda de ella. Con esto cumplí con el requisito de tener al menos una herencia propia.

</div>

**`motor_fisico`**

<div align="justify">

Calcula toda la física del juego sin usar las funciones matemáticas estándar de `C++`, más específicamente de la librería `<cmath>`. Implementé mi propio `seno` y `coseno` mediante series de Taylor, y su propia raíz cuadrada mediante el método de Newton-Raphson. La encargué de tres cosas: descomponer la fuerza inicial en velocidades `X` e `Y` según el ángulo, aplicar la gravedad, y frenar la lanza horizontalmente con la resistencia del aire.

</div>

**`proyectil`**

<div align="justify">

Representa la lanza en vuelo. La hice heredar de `entidad` para tener sprite propio, y le añadí un objeto `motor_fisico` interno para moverse. En cada tick hace que se actualice su posición acumulando los valores de velocidad en flotante (así evité perder precisión por redondeos enteros). También almacena la fuerza final con la que viaja en el momento del impacto, dato que utilizo en el panel para calcular los puntos.

</div>

**`obstaculo`**

<div align="justify">

Creé los escudos flotantes que se interponen entre el jugador y Baldur. Programé su movimiento vertical entre dos límites a una velocidad configurable, y cuando reciben un impacto reproducen una animación de explosión de 4 frames antes de reiniciarse. Los creo a todos mediante un método estático `cargar_en_escena()` que programé para colocar 5 escudos en posiciones y velocidades distintas con una sola llamada.

</div>

**`baldur`**

<div align="justify">

Es el objetivo principal del duelo. Hice que anime dos frames de risa continuamente usando un contador interno para no ir al mismo ritmo del timer principal. Cuando recibe un golpe, programé que salte a una posición aleatoria de entre 4 posibles, lo que lo hace impredecible.

</div>

**`gestor_combates`**

<div align="justify">

Lo diseñé como el director de todo el combate. Con él centralicé la lógica que antes tenía dispersa en `Widget`: mover las lanzas, detectar colisiones, animar el ataque del jugador y del agente, y destruir lanzas con explosión. Al separarlo así, logré que `Widget` quedara como un coordinador de interfaz limpio, sin lógica de juego mezclada.

</div>

**`panel`**

<div align="justify">

Con esta clase manejo todo lo relacionado con el estado de la partida: los puntos de cada jugador, el tiempo restante (cuenta regresiva desde 5 minutos), el turno actual, y la aparición aleatoria del muérdago. La dibujé encima del `graphicsView` de forma transparente, así evité bloquear el juego. Intenté que emitiera señales cuando hay que cambiar de turno, cuando termina la partida o cuando el muérdago entra y sale de escena, pero no me funcionó como esperaba.

</div>

**`efectos_sonido`**

<div align="justify">

Aquí agrupé todos los audios. Utilicé `QSoundEffect` para los efectos cortos (explosión, herido) porque carga el archivo en memoria y lo reproduce sin latencia. Usé `QMediaPlayer` para la música de fondo porque soporta archivos más largos y la puedo repetir en loop indefinidamente.

</div>

**`Widget`**

<div align="justify">

Es la clase principal de `Qt` en mi aplicación. Con ella manejo la interfaz de usuario: los botones de selección de personaje, el botón de lanzar, y la configuración inicial de cada nivel. Decidí no darle lógica de juego directa, sino delegarla al `gestor_combates` y al `panel` mediante señales y llamadas a métodos.

</div>

---

## 7. Desarrollo e implementación

### Físicas parabólicas

<div align="justify">

Esta fue la parte más interesante del proyecto para mí. En vez de usar `sin()`, `cos()` y `sqrt()` de `<cmath>`, decidí implementar los míos desde cero en el `motor_fisico`:

</div>

<div align="justify">

- **Seno y coseno**: los calculé mediante series de Taylor truncadas a 10 términos, lo que me dio precisión suficiente para los ángulos usados en el juego.

</div>

<div align="justify">

- **Raíz cuadrada**: la implementé mediante el método iterativo de Newton-Raphson, que me converge muy rápido (en menos de 20 iteraciones para cualquier número dentro del rango del juego).

</div>

```cpp
double motor_fisico::sen(double x) // Implementación del seno mediante series de Taylor
{
    double termino = x;
    double suma = x;
    for(int i = 1; i < 10; i++)
    {
        termino *= -1 * x * x / ((2 * i) * (2 * i + 1)); // calcular el siguiente término
        suma += termino; // agregar el término a la suma
    }
    return suma;
}

double motor_fisico::cos(double x) // Implementación del coseno mediante series de Taylor
{
    double ttermino = 1.0; // Primer termino de la serie
    double suma = 1.0;
    for(int i = 1; i < 10; i++)
    {
        ttermino *= -1 * x * x / ((2 * i - 1) * (2 * i)); // calcular el siguiente término
        suma += ttermino; // agregar el término a la suma
    }
    return suma;
}

double motor_fisico::calcularRaiz(double numero) // Implementación de la raíz cuadrada mediante el método de Newton-Raphson
{
    if (numero < 0) return -1; // Manejo de error para negativos
    if (numero == 0) return 0;

    double estimacion = numero; // Valor inicial
    double precision = 0.000001; // Margen de error tolerado

    // Bucle de aproximación
    while ((estimacion * estimacion - numero) > precision || (numero - estimacion * estimacion) > precision)
    {
        estimacion = 0.5 * (estimacion + (numero / estimacion));
    }

    return estimacion;
}
```

<div align="justify">

La trayectoria la programé para que funcione así: al lanzar, calculo `vel_x` y `vel_y` iniciales a partir del ángulo y la fuerza. En cada timer, hago que `vel_y` aumente por la gravedad (`9.8 unidades`) y `vel_x` se multiplique por `0.98` (resistencia del aire). Acumulo la posición en variables `float` para no perder los decimales, y solo al final le indico a `Qt` dónde dibujar con `setPos()`. Este detalle lo descubrí como algo muy importante: si convertía a `int` antes de acumular, la parábola se rompía.

</div>


```cpp
void motor_fisico::calcular_velocidad_inicial(float angulo, float fuerza, float &velocidad_x, float &velocidad_y)
{
    // Convertimos el angulo de grados a radianes
    float angulo_rad = angulo * 3.14159265 / 180.0;

    // La fuerza se descompone en X y Y segun el angulo
    velocidad_x = fuerza * this->cos(angulo_rad);
    velocidad_y = -(fuerza * this->sen(angulo_rad));
}

void motor_fisico::aplicar_gravedad(float &velocidad_y) // Aplica la gravedad
{
    velocidad_y += gravedad;
}

void motor_fisico::aplicar_resistencia(float &velocidad_x) // Aplica la resistencia del aire
{
    velocidad_x *= (1.0 - resistencia_aire);
}

float motor_fisico::fuerza_final(float vel_x, float vel_y) // Calcula la fuerza final de la lanza
{
    return calcularRaiz(vel_x * vel_x + vel_y * vel_y);
}
```

### Agente autónomo

<div align="justify">

Para la máquina diseñé un sistema simple pero efectivo: empieza con un margen de error de `±30 grados` alrededor del ángulo ideal `35°`, y en cada ronda programé que ese margen se reduzca en `2 grados`. Después de `15 rondas` ya lanza con prácticamente la trayectoria perfecta. También hice que la fuerza varíe aleatoriamente dentro del mismo margen.

</div>

```cpp
void gestor_combates::turno_agente()
{
    if (agente == nullptr)
        return;

    if (panel_juego != nullptr && panel_juego->get_turno() != 1)
        return;

    static int rondas_agente = 0;
    rondas_agente++;

    int margen = 30 - rondas_agente * 2; // El margen de error se reduce en 2 cada ronda
    if (margen < 1)
        margen = 1; // El margen de error no puede ser menor a 1

    int angulo = 40 + QRandomGenerator::global()->bounded(-margen, margen + 1); // El angulo se calcula aleatoriamente dentro del margen
    int fuerza = 85 + QRandomGenerator::global()->bounded(-margen * 2, margen * 2 + 1); // La fuerza se calcula aleatoriamente dentro del margen

    // ... Demas del codigo carga el projectile y el spite
    
}
```

### Sistema de puntos

<div align="justify">

Diseñé el sistema de puntos de modo que cada golpe se calcule multiplicando la fuerza final de la lanza en el momento del impacto por 10. Como la resistencia del aire frena la lanza cuanto más viaja, logré que golpear desde lejos dé naturalmente menos puntos que hacerlo desde cerca con mucha fuerza. Con esto busqué crear una tensión mecánica interesante: ¿lanzo fuerte desde lejos o busco un ángulo más cercano?

</div>

### Comunicación entre clases

<div align="justify">

Utilicé el sistema de señales y slots de `Qt` para comunicar mis clases sin que se conozcan directamente entre sí. Por ejemplo, cuando el panel detecta que es turno de la máquina, emite una señal `turno_maquina()` que conecté para que `Widget` la reciba y se la pase al `gestor_combates`. Así logré que cada clase solo sepa lo mínimo necesario sobre las demás.

</div>

---

## 8. Procedimientos de prueba

<div align="justify">

Las pruebas que realicé fueron principalmente manuales e iterativas durante mi desarrollo. Probé cada funcionalidad de forma aislada antes de integrarla con el resto:

</div>

<div align="justify">

- **Físicas**: ajusté los valores de gravedad (9.8) y resistencia (0.02) haciendo lanzamientos con distintos ángulos y fuerzas hasta obtener una parábola visualmente convincente dentro del espacio de pantalla.

</div>

<div align="justify">

- **Colisiones**: verifiqué que `collidesWithItem()` de `Qt` detectara correctamente los choques entre la lanza y los obstáculos/Baldur, y evité que se dispararan doble en el mismo frame.

</div>

<div align="justify">
- **Turnos**: comprobé que el panel bloqueara el botón de lanzar durante el turno de la máquina revisando la condición `get_turno() != 0` en `lanzar_jugador()`.
- **Audio**: usé `qDebug()` para imprimir el estado del `QSoundEffect` (cargado, listo, reproduciendo) y así logré identificar por qué el sonido no sonaba inicialmente.
- **Muérdago**: reduje temporalmente el tiempo de aparición a 5 segundos para verificar que la condición de victoria inmediata funcionara correctamente.

</div>

---

## 9. Guía de instalación y uso

### Requisitos

<div align="justify">

- Tener un ordenador con `Windows` o `Linux`.
- Tener una cuenta de GitHub.

</div>

### Instalación

<div align="justify">

1. Clonar el repositorio: https://github.com/oscargutierrez221/sangre-de-dioses.git
2. Dependiendo de tu sistema operativo:
    - Windows: Ejecutar el archivo `Desarrollo.exe`
    - Linux: Abre una terminal en la carpeta del ejecutable y ejecuta el comando:
        ```bash
        chmod +x "El nombre el ejecutable" -> Dar permisos de ejecucion
        ./"El nombre el ejecutable" -> Ejecutar el juego
        ```

</div>

### Cómo jugar

<div align="justify">

1. En la pantalla de inicio, elegir un personaje (Zeus, Poseidón, Hades o Ares).
2. Ajustar el **ángulo** y la **fuerza** con los spinboxes del menú.
3. Presionar **Lanzar** para atacar.
4. Esquivar los escudos flotantes para que la lanza llegue a Baldur.
5. Cuando aparezca el aviso del **muérdago**, golpear a Baldur en ese momento para ganar instantáneamente.
6. Si no, ganar acumulando más puntos que la máquina antes de que se acaben los 5 minutos.

</div>

---

## 10. Resultados y discusión

<div align="justify">

Logré dejar el nivel completamente funcional con todas las mecánicas que planeé: físicas parabólicas, obstáculos, agente autónomo, sistema de puntos, muérdago y audio. Mi decisión de enfocarme en un solo nivel bien terminado en vez de hacer dos niveles a medias resultó acertada.

</div>

### Limitaciones actuales

<div align="justify">

- El agente autónomo es predecible en las primeras rondas y muy preciso al final, sin punto medio interesante.
- Los obstáculos no se regeneran si todos explotan, dejando el camino libre.
- No hay pantalla de resultado final elaborada, solo un `QMessageBox`.
- La música de fondo y los efectos de sonido dependen de que los archivos estén en la ruta correcta del `.qrc`, lo que puede causar silencio sin mensaje de error visible.

</div>

### Mejoras planeadas

<div align="justify">

- Agregar variación aleatoria persistente al agente para que no se vuelva perfecto.
- Regenerar obstáculos destruidos después de un tiempo.
- Implementar una pantalla de fin de partida con animación.
- Agregar un segundo nivel con Baldur como el otro personaje.

</div>

---

## 11. Conclusiones

<div align="justify">
Con el proyecto comprobé que construir un videojuego, aunque sea pequeño, me obligó a pensar seriamente en el diseño de clases. Cada vez que una clase hacía demasiadas cosas (como me pasó con `Widget` en algún momento), el código se me volvía difícil de entender y modificar. Refactorizar hacia `gestor_combates` y `panel` fue la decisión correcta que tomé, aunque me costó tiempo.

</div>

<div align="justify">

Para mí, lo más valioso del proceso fue implementar las físicas desde cero. Ver que las series de Taylor y el método de Newton-Raphson, que me parecían temas abstractos de cálculo, son exactamente lo que está detrás de cada `sin()` y `sqrt()` que utilizo normalmente, me cambió la perspectiva sobre lo que hay debajo de las librerías estándar.

</div>

<div align="justify">

Mi recomendación para quien quiera continuar mi proyecto es implementar los otros personajes jugables (Poseidón, Hades, Ares) contra enemigos distintos, y agregar un sistema de dificultad que afecte tanto al agente como a la velocidad y cantidad de obstáculos.

</div>

---

## 12. Referencias

<div align="justify">

- Documentación oficial de Qt 6: https://doc.qt.io/qt-6/
- Qt Multimedia — QSoundEffect: https://doc.qt.io/qt-6/qsoundeffect.html
- Qt Multimedia — QMediaPlayer: https://doc.qt.io/qt-6/qmediaplayer.html
- QGraphicsScene y QGraphicsItem: https://doc.qt.io/qt-6/qgraphicsscene.html
- Repositorio del proyecto: https://github.com/oscargutierrez221/sangre-de-dioses

</div>

---
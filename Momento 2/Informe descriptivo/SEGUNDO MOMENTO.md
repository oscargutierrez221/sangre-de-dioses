# Indice

- [1. Descripción](#1-descripción)
  - [1.1 Vistas de cada nivel](#11-vistas-de-cada-nivel)
  - [1.2 Interacciones entre personajes, enemigos y entorno](#12-interacciones-entre-personajes-enemigos-y-entorno)
- [2. Clases que necesitamos para hacer el juego](#2-clases-que-necesitamos-para-hacer-el-juego)
  - [2.1 Clase Entidad (la mamá de casi todos)](#21-clase-entidad-la-mamá-de-casi-todos)
  - [2.2 Clase Personaje (hereda de Entidad)](#22-clase-personaje-hereda-de-entidad)
    - [2.2.1 Clase Jugador (hereda de Personaje)](#221-clase-jugador-hereda-de-personaje)
    - [2.2.2 Clase Baldur (hereda de Personaje)](#222-clase-baldur-hereda-de-personaje)
    - [2.2.3 Clase Heroe (hereda de Personaje)](#223-clase-heroe-hereda-de-personaje)
    - [2.2.4 Clase Loki (hereda de Personaje)](#224-clase-loki-hereda-de-personaje)
    - [2.2.5 Clase Apolo (hereda de Personaje)](#225-clase-apolo-hereda-de-personaje)
    - [2.2.6 Clase Artemisa (hereda de Personaje)](#226-clase-artemisa-hereda-de-personaje)
  - [2.3 Clase Proyectil (hereda de Entidad)](#23-clase-proyectil-hereda-de-entidad)
    - [2.3.1 Clase Jabalina (hereda de Proyectil)](#231-clase-jabalina-hereda-de-proyectil)
    - [2.3.2 Clase ProyectilDivino (hereda de Proyectil)](#232-clase-proyectildivino-hereda-de-proyectil)
  - [2.4 Clase Obstaculo (hereda de Entidad)](#24-clase-obstaculo-hereda-de-entidad)
    - [2.4.1 Clase EscudoFlotante (hereda de Obstaculo)](#241-clase-escudoflotante-hereda-de-obstaculo)
    - [2.4.2 Clase Muerdago (hereda de Obstaculo)](#242-clase-muerdago-hereda-de-obstaculo)
  - [2.5 Clase Objetivo (hereda de Entidad)](#25-clase-objetivo-hereda-de-entidad)
    - [2.5.1 Clase EscudoGiratorio (hereda de Objetivo)](#251-clase-escudogiratorio-hereda-de-objetivo)
  - [2.6 Clase Nivel (clase abstracta)](#26-clase-nivel-clase-abstracta)
    - [2.6.1 Clase NivelBaldur (hereda de Nivel)](#261-clase-nivelbaldur-hereda-de-nivel)
    - [2.6.2 Clase NivelJuegosFunnebres (hereda de Nivel)](#262-clase-niveljuegosfunnebres-hereda-de-nivel)
  - [2.7 Clase MotorFisico](#27-clase-motorfisico)
  - [2.8 Clase MotorJuego](#28-clase-motorjuego)
  - [2.9 Clase AdministradorNiveles](#29-clase-administradorniveles)
- [3. Diagrama de Clases](#3-diagrama-de-clases)
  - [3.1 Diagrama de Clases - Entidades del mundo](#31-diagrama-de-clases---entidades-del-mundo)
  - [3.2 Diagrama de Clases - Sistema de juego](#32-diagrama-de-clases---sistema-de-juego)

# 1. Descripción

### 1.1 Vistas de cada nivel 

 **Nivel 1 – Juego de Baldur** 
 - La visión es cenital fija, es decir, lo que nos va a permitir es poder observar todo el terreno con claridad para poder controlar el lanzamiento de la jabalina. Baldur está ubicado en el centro del campo y a su alrededor estan los dioses que están jugando el partido y para el nivel de dificultad de éste ponemos obstáculos móviles (escudos flotantes) que siguen una línea de comportamiento conocida ( hacia arriba y abajo). Esto hace que el usuario deba calcular tanto el ángulo como la fuerza del tiro; si el angulo no es el adecuado puede irse muy arriba o muy abajo, de la misma manera, si la fuerza no es suficiente entonces la lanza puede no llegar a Baldur o puede pasar de largo. 

 **Nivel 2 – Juegos Fúnebres** 
 - La vista será lateral, pero con movimiento lateral limitado de la cámara para cambiar la perspectiva del tiro y hacer que el campo sea más dinámico. La idea detrás de esto es dar a la cámara la posibilidad de moverse a izquierda y derecha con el fin de simular un escenario más extenso. El objetivo del juego es que, además de pensar en el blanco, el jugador deba tener en cuenta factores externos, como el viento y movimientos de otros dioses.

### 1.2 Interacciones entre personajes, enemigos y entorno 

 **Nivel 1 – Juego de Baldur** 
 - **Jugador (Dios participante):** El jugador controla a un dios que lanza jabalinas hacia Baldur. El objetivo principal es calcular el ángulo y la fuerza del lanzamiento para lograr impactos efectivos, cada que una lanza golpee a Baldur entonces se brindaran puntos de acuerdo a la fuerza con la que la lanza llego, es decir, si la lanza llego con muy pooca fuerza restante entonces hay pocos puntos que si la lanza lelgará con más fuerza. Si por el contrario la lanza no llega a Baldur no se suman puntos. El reto está en superar los obstáculos móviles y adaptarse a las diferentes adversidades que imponga Loki para así poder obtener la mayor cantidad de puntos y poder ganarle a la maquina que lanza con una fuerza y un angulo cada vez más precisos. 
 
 - **Baldur (Personaje central):** Baldur es el objetivo principal del juego. Gracias a su invulnerabilidad, recibe los impactos de las jabalinas sin sufrir daños, pero durante el juego incluimos una condición crítica, si aparece el muérdago, la jabalina puede atravesarlo y causar su derrota, o en otras palabras una victoria instantanea. En teoría, el personaje es invencible por defecto, pero vulnerable ante un factor específico.
 
 - **Loki (Enemigo indirecto):** Loki no participa directamente, pero manipula el entorno. Su rol es introducir el muérdago o alterar las condiciones de juego poniendo mas obstaculos y haciendo que estos se muevan mas rapido, aumentando la dificultad.

 - **Obstáculos móviles (Escudos flotantes):** Estos obstáculos obligan al jugador a calcular con precisión y ajustar constantemente sus lanzamientos..

 **Nivel 2 – Juegos Fúnebres** 
- **Jugador (Héroe participante):** En este modo, manejamos a un héroe que compite en los juegos de Patroclo. La mecánica principal es el lanzamiento de jabalina en donde hay que considerar ciertas variables físicas como el viento y la rotación del proyectil. Lo que lo hace difícil es que el objetivo no es estático y el entorno va cambiando.

- **Dioses (Apolo y Artemisa):** Estos intervienen directamente en el juego. Apolo puede alterar el viento buscando desviar la trayectoria de la jabalina, mientras que Artemisa lanza proyectiles desde el cielo, creando obstáculos inesperados.

- **Blanco (Escudo giratorio):** Es el objetivo principal del jugador y funciona como enemigo indirecto porque requiere una mejor precisión. La rotación del escudo obliga al jugador a calcular el momento exacto del lanzamiento. 

- **Entorno dinámico (Campo con scroll lateral):** El campo se observa desde una vista lateral, simulando un espacio más amplio. El viento cambia de forma aleatoria afectando la parábola de la jabalina. Además, los proyectiles divinos caen desde el cielo en trayectorias impredecibles, obligando al jugador a reaccionar rápido y ajustar su estrategia.

---

# 2. Clases que necesitamos para hacer el juego

Después de pensarlo bien, creemos que vamos a necesitar varias clases para que todo funcione. No somos expertos pero esto es lo que se nos ocurrió:

## 2.1 Clase Entidad (la mamá de casi todos)

Esta es la clase base que va a tener todo lo que se mueve en la pantalla. La hicimos porque nos dimos cuenta que todo tiene posición y necesita actualizarse.

- **Atributos privados:** `posicionX`, `posicionY`, `velocidad`
- **Métodos públicos:** `mover()`, `dibujar()`
- **Hijas:** Personaje, Proyectil, Obstaculo, Objetivo

## 2.2 Clase Personaje (hereda de Entidad)

Aquí van todos los que participan en el juego. Tiene cosas que todos los personajes necesitan como nombre y poder.

- **Atributos privados:** `nombre`, `puntosDeVida`, `poder`
- **Métodos públicos:** `cambiar_sprite()`
- **Hijas:** Jugador, Baldur, Heroe, Loki, Apolo, Artemisa

### 2.2.1 Clase Jugador (hereda de Personaje)

El que controla el humano. Necesita guardar el ángulo y la fuerza para lanzar.

- **Atributos privados:** `angulo`, `fuerza`, `puntuacion`
- **Métodos públicos:** `apuntar()`, `lanzar()`, `calcularLanzamiento()`

### 2.2.2 Clase Baldur (hereda de Personaje)

El objetivo del primer nivel. Es invulnerable excepto cuando aparece el muérdago.

- **Atributos privados:** `esInvulnerable`, `golpesRecibidos`
- **Métodos públicos:** `recibirImpacto()`, `morir()`

### 2.2.3 Clase Heroe (hereda de Personaje)

El que usamos en el segundo nivel para los juegos fúnebres.

- **Atributos privados:** `resistencia`, `precision`
- **Métodos públicos:** `apuntar()`, `lanzar()`

### 2.2.4 Clase Loki (hereda de Personaje)

El travieso que complica todo. Aparece obstáculos y el muérdago.

- **Atributos privados:** `tiempoParaIntervenir`, `nivelDeDificultad`
- **Métodos públicos:** `generarObstaculo()`, `aparecerMuerdago()`, `aumentarDificultad()`

### 2.2.5 Clase Apolo (hereda de Personaje)

Controla el viento en el nivel 2 para desviar las jabalinas.

- **Atributos privados:** `poderDelViento`
- **Métodos públicos:** `cambiarViento()`, `afectarTrayectoria()`

### 2.2.6 Clase Artemisa (hereda de Personaje)

Lanza proyectiles desde arriba en el segundo nivel.

- **Atributos privados:** `tiempoDeRecarga`
- **Métodos públicos:** `dispararProyectilDivino()`

## 2.3 Clase Proyectil (hereda de Entidad)

Todo lo que se lanza por el aire. Necesitamos saber cómo vuela.

- **Atributos privados:** `angulo`, `fuerzaInicial`, `fuerzaActual`
- **Métodos públicos:** `actualizarTrayectoria()`, `calcularImpacto()`
- **Hijas:** Jabalina, ProyectilDivino

### 2.3.1 Clase Jabalina (hereda de Proyectil)

Lo que lanza el jugador. Puede girar en el aire.

- **Atributos privados:** `velocidadRotacion`
- **Métodos públicos:** `calcularPuntuacionDelGolpe()`

### 2.3.2 Clase ProyectilDivino (hereda de Proyectil)

Lo que tira Artemisa desde el cielo. Va por trayectorias raras.

- **Atributos privados:** `trayectoriaCaotica`
- **Métodos públicos:** `actualizarTrayectoriaCaotica()`

## 2.4 Clase Obstaculo (hereda de Entidad)

Cosas que estorban el paso de la jabalina.

- **Atributos privados:** `dureza`, `tamaño`
- **Métodos públicos:** `destruirse()`
- **Hijas:** EscudoFlotante, Muerdago

### 2.4.1 Clase EscudoFlotante (hereda de Obstaculo)

Los del primer nivel que se mueven arriba y abajo.

- **Atributos privados:** `velocidadOscilacion`, `amplitudDelMovimiento`
- **Métodos públicos:** `moverseEnOnda()`

### 2.4.2 Clase Muerdago (hereda de Obstaculo)

El único que puede matar a Baldur. Aparece de vez en cuando.

- **Atributos privados:** `probabilidadDeAparecer`, `tiempoVisible`
- **Métodos públicos:** `verificarSiTocaBaldur()`

## 2.5 Clase Objetivo (hereda de Entidad)

Lo que hay que golpear para ganar puntos.

- **Atributos privados:** `puntosQueDa`, `posicion`
- **Métodos públicos:** `recibirGolpe()`
- **Hijas:** EscudoGiratorio

### 2.5.1 Clase EscudoGiratorio (hereda de Objetivo)

El blanco del nivel 2 que gira y gira.

- **Atributos privados:** `velocidadRotacion`, `radio`
- **Métodos públicos:** `rotar()`

## 2.6 Clase Nivel (clase abstracta)

La base para hacer los niveles. Aquí se pone lo que todos los niveles necesitan.

- **Atributos privados:** `tiempoLimite`, `puntuacionMinima`, `listaDeEntidades`
- **Métodos públicos:** `iniciar()`, `actualizar()`, `verificarSiGano()`, `verificarSiPerdio()`
- **Hijas:** NivelBaldur, NivelJuegosFunnebres

### 2.6.1 Clase NivelBaldur (hereda de Nivel)

El primer nivel con Baldur en el centro y los escudos flotantes.

- **Atributos privados:** `baldur`, `escudos[]`, `loki`, `tiempoRestante`
- **Métodos públicos:** `aparecerMuerdagoAleatorio()`, `aumentarDificultad()`

### 2.6.2 Clase NivelJuegosFunnebres (hereda de Nivel)

El segundo nivel con viento, Apolo, Artemisa y el escudo giratorio.

- **Atributos privados:** `heroe`, `escudoGiratorio`, `apolo`, `artemisa`, `viento`, `impactosNecesarios`
- **Métodos públicos:** `actualizarViento()`, `generarProyectilDivino()`

## 2.7 Clase MotorFisico

Esta es la que hace las cuentas de cómo vuela la jabalina. Es súper importante porque sin ella no se mueve nada.

- **Atributos privados:** `gravedad`, `configuracionDelJuego`
- **Métodos públicos:** `calcularTrayectoria()`, `calcularColision()`, `calcularRebote()`, `calcularEfectoViento()`

## 2.8 Clase MotorJuego

El que manda en todo. Es como el director que dice qué pasa y cuándo.

- **Atributos privados:** `estadoActual`, `nivelActual`, `puntuacionTotal`
- **Métodos públicos:** `iniciarJuego()`, `pausar()`, `cambiarNivel()`, `terminarJuego()`

## 2.9 Clase AdministradorNiveles

Se encarga de pasar de un nivel a otro sin que todo se rompa.

- **Atributos privados:** `nivelActual`, `nivelesDesbloqueados[]`
- **Métodos públicos:** `cargarNivel()`, `guardarProgreso()`, `cambiarDeNivel()`

---

Creemos que con estas clases podemos hacer que el juego funcione. Algunas heredan de otras para no repetir código y todo se conecta con el MotorJuego que es el jefe de todo.

# 3. Diagrama de Clases

Para poder entender de mejor manera cómo se conectan todas las clases, hemos desarrollado 2 diagramas de clases debido a que el codigo se podria decir que se divide en 2 ambitos:

## 3.1 Diagrama de Clases - Entidades del mundo

![Diagrama de clases entidades](Material/Entidades_diagrama_de_clases.png)

Siendo la primera parte la que se encarga de las entidades del mundo.

## 3.2 Diagrama de Clases - Sistema de juego

![Diagrama de clases cerebro del sistema](Material/cerebro_sistema_diagrama_de_clases.png)

que el segundo representa el cerebro del sistema que controla todo el juego. Desde los niveles hasta las fisicas.
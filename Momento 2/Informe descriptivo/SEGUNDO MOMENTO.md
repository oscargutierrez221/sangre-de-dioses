# 1. Descripción

### 1.1 Vistas de cada nivel 

 **Nivel 1 – Juego de Baldur** 
 - La vista es **cenital fija**, es decir, esto lo que nos permite es tener un rango visual de todo el escenario de manera clara y facilita el control del lanzamiento de la jabalina. Baldur se ubica en el centro del campo y alrededor están los dioses que participan en el juego, para la dificultad del juego incluimos obstáculos móviles (escudos flotantes) que siguen trayectorias predecibles. Esto obliga al usuario a analizar y calcular con precisión tanto el **ángulo** como la **fuerza** del tiro. 

 **Nivel 2 – Juegos Fúnebres** 
 - La vista es **lateral con desplazamiento horizontal limitado** lo que cambia la perspectiva del tiro y hace que el campo se sienta más dinámico. Al permitir que la cámara se mueva hacia los lados, simulamos un entorno más amplio. El enfoque aquí es que el jugador no solo se preocupe por el blanco (escudo giratorio), sino también por variables externas como el viento y las acciones de los otros dioses, obligándolo a ajustar su estrategia en cada intento. 

### 1.2 Interacciones entre personajes, enemigos y entorno 

 **Nivel 1 – Juego de Baldur** 
 - **Jugador (Dios participante):** El jugador controla a un dios que lanza jabalinas hacia Baldur. El objetivo principal es calcular el ángulo y la fuerza del lanzamiento para lograr impactos efectivos. El reto está en superar los obstáculos móviles y adaptarse a las diferentes adversidades que imponga Loki. 
 
 - **Baldur (Personaje central):** Baldur como el objetivo principal del juego. Gracias a su invulnerabilidad, recibe los impactos de las jabalinas sin sufrir daños, lo que plantea una dinámica interesante en el nivel no obstante durante el juego incluimos una **condición crítica**: Si aparece el muérdago, la jabalina puede atravesarlo y causar su derrota. En teoría, el personaje es invencible por defecto, pero vulnerable ante un factor específico, obligando al jugador a estar atento a ese "comodín" dentro de las reglas de juego. 
 
 - **Loki (Enemigo indirecto):** Loki no participa directamente, pero manipula el entorno. Su rol es introducir el muérdago o alterar las condiciones de juego, aumentando la dificultad.

 - **Obstáculos móviles (Escudos flotantes):** Estos obstáculos obligan al jugador a calcular con precisión y ajustar constantemente sus lanzamientos. Funcionan como barreras dinámicas que aumentan la complejidad del nivel. 

 **Nivel 2 – Juegos Fúnebres** 
- **Jugador (Héroe participante):** En este modo, manejamos a un héroe que compite en los juegos de Patroclo. La mecánica principal es el lanzamiento de jabalina en donde hay que considerar ciertas variables físicas como el **viento** y la **rotación** del proyectil. Lo que lo hace difícil es que el objetivo no es estático y el entorno va cambiando. 

- **Dioses (Apolo y Artemisa):** Estos intervienen directamente en el juego. Apolo puede alterar el viento buscando desviar la trayectoria de la jabalina, mientras que Artemisa lanza proyectiles desde el cielo, creando obstáculos inesperados.

- **Blanco (Escudo giratorio):** Es el objetivo principal del jugador y funciona como enemigo indirecto porque requiere una mejor precisión. La rotación del escudo obliga al jugador a calcular el momento exacto del lanzamiento. 

- **Entorno dinámico (Campo con scroll lateral):** El campo se observa desde una vista lateral, simulando un espacio más amplio. El viento cambia de forma aleatoria afectando la parábola de la jabalina. Además, los proyectiles divinos caen desde el cielo en trayectorias impredecibles, obligando al jugador a reaccionar rápido y ajustar su estrategia.



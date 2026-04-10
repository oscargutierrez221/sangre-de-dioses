# 1. CONTEXTO

**El Juego de la Invulnerabilidad de Baldur**

> *En Asgard, la seguridad de los dioses se vio amenazada cuando Baldur, el hijo predilecto de Odín y Frigg, comenzó a tener sueños proféticos sobre su propia muerte. Ante el temor de perder al más amado de los dioses, su madre, Frigg, recorrió los nueve mundos exigiendo un juramento a cada elemento de la creación: el fuego, el agua, los metales, las piedras, las enfermedades, las bestias y las plantas juraron jamás dañar a su hijo.*
> 
> *Al saberse protegido por la naturaleza misma, lo que comenzó como una medida de seguridad se transformó en una forma de entretenimiento en las asambleas divinas. Los dioses colocaban a Baldur en el centro del círculo y, a modo de demostración de poder y asombro, le lanzaban dardos, piedras y pesadas lanzas. La fascinación no radicaba en el deporte, sino en el espectáculo místico de ver cómo las armas más letales se desviaban o caían inertes al suelo sin causar un solo rasguño. Para ellos, no era un entrenamiento de puntería, sino una celebración de la "inmortalidad" de su compañero, hasta que la omisión del muérdago convirtió el juego en el preludio del Ragnarök.*

**Los Juegos Fúnebres en Honor a Patroclo**

> *En la mitología griega, el lanzamiento de lanza no era un pasatiempo casual de los dioses, sino una extensión de la areté (excelencia) que estos exigían a los mortales y que ellos mismos personificaban. El contexto más famoso se da durante la Guerra de Troya, específicamente tras la muerte de Patroclo. Aquiles, sumido en el dolor, organiza una serie de competiciones atléticas para honrar el espíritu de su amigo caído.*
> 
> *En estos juegos, la lanza era la prueba reina. Para los griegos, este acto representaba la unión entre la fuerza física y la voluntad divina. Mientras los héroes como Áyax o Agamenón se preparaban para lanzar, los dioses en el Olimpo no solo observaban, sino que participaban activamente en el contexto de la competencia política celestial. Apolo o Atenea solían intervenir desviando una lanza con una ráfaga de viento o fortaleciendo el brazo de su favorito. Así, el lanzamiento de lanza era el escenario donde se medía el favor de los dioses; si una lanza volaba lejos y firme, no solo se elogiaba al atleta, sino a la deidad que lo respaldaba en ese momento de gloria militar y religiosa.*

---

## 2. Idea central:
Juego mitológico de lanzamiento de jabalina. Los protagonistas son dioses de distintas culturas (Odín, Atenea, Lugh), cada uno con poderes y características únicas. El objetivo general es lanzar la jabalina desde una posición determinada para impactar un blanco, pero cada nivel introduce dinámicas distintas.

### **Nivel 1:** El ***“Juego de Baldur”*** (Mitología Nórdica)

> **Sinopsis:** *Los dioses se divierten lanzando armas contra Baldur, quien es invulnerable… excepto al muérdago. El jugador controla a un dios que participa en este extraño “juego”.*

1. **Vista:** Cenital fija (desde arriba).
2. **Dinámicas físicas:**
   - **Movimiento parabólico:** Trayectoria de la jabalina al ser lanzada, ajustable por ángulo y fuerza.
   - **Oscilación armónica:** Obstáculos móviles (escudos flotantes) que se mueven con ecuaciones sinusoidales.
   - **Colisión paramétrica:** Rebote de las armas contra Baldur, con ángulos de reflexión variables.
3. **Retos:** Evitar que Loki manipule el entorno; si aparece muérdago, la jabalina puede atravesar a Baldur y terminar el nivel en tragedia.
4. **Objetivo:** Impactar a Baldur con la mayor precisión posible, acumulando puntos por rebotes espectaculares.
5. **Funcionamiento general:** El jugador ajusta ángulo y potencia, lanza la jabalina, y debe superar obstáculos móviles. El nivel está controlado por tiempo (timer de 90 segundos): se deben lograr la mayor cantidad de impactos antes de que Loki intervenga.

### Nivel 2: ***Juegos Fúnebres en la Ilíada*** (Mitología Griega)

> **Sinopsis:** *Durante los juegos en honor a Patroclo, los héroes compiten en lanzamiento de jabalina mientras los dioses observan y alteran el resultado.*

1. **Vista:** Lateral con scroll limitado (el campo se desplaza horizontalmente).
2. **Dinámicas físicas:**
   - **Movimiento parabólico con viento:** La jabalina sigue una parábola, pero el viento (variable aleatoria) altera su trayectoria.
   - **Movimiento caótico (ecuación logística):** Aparición de proyectiles divinos que caen desde el cielo en trayectorias impredecibles.
   - **Rotación angular:** La jabalina puede girar en el aire, afectando su precisión al impactar.
3. **Retos:** Los dioses (Apolo y Artemisa) alteran el viento y lanzan obstáculos desde el Olimpo.
4. **Objetivo:** Alcanzar el blanco en movimiento (un escudo giratorio) y acumular puntos por precisión.
5. **Funcionamiento general:** El jugador debe calcular el lanzamiento considerando viento y rotación. El nivel termina cuando se alcanzan 5 impactos exitosos o se agota el tiempo de 3 minutos.

---

### Características de los personajes:

1. **Dioses del Olimpo:** Se otorga la posibilidad de elegir entre una pequeña variedad de dioses con el que se desea jugar.
2. **Veloz impulsivo:** Puede cargar energía para lanzar más rápido, pero esto reduce el tiempo de cálculo y aumenta el riesgo de fallar.

---

### Agente autónomo:

1. **Percepción:** Detecta cuándo el jugador lanza una jabalina.
2. **Razonamiento:** Evalúa si puede intervenir para desviar el proyectil o introducir muérdago.
3. **Acción:** Genera un obstáculo o altera la física del lanzamiento.
4. **Aprendizaje:** Si el jugador repite un patrón de lanzamiento, aprende y anticipa la trayectoria para aumentar la dificultad.

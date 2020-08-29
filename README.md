# TareasGeometria

Mis soluciones a las tareas del ramo CC5502. Magister Ciencias Computacion Universidad de Chile.

# Tarea 1 - Elementos geométricos

## 1. Introducción
Teniendo sus bases directamente en la matemática, la idea de utilizar la computación
sobre la geometría no sólo viene a resolver problemas, sino también a mejorarlos en términos
de precisión, así como en tiempo de resolución.

Sin embargo, la precisión es un tema complejo, ya que la precisión numérica de un
computador está acotada justamente a cuanto puede almacenar un número (recuerden, por
ejemplo, que un Integer está entre los valores \[−2^31, 2^31 − 1\] contabilizando negativos) y
además a la precisión de un computador mismo para realizar operaciones. Por todo ello hoy
en día los software más precisos son justamente los más caros, como los CAD, ya que en la
ingeniería un error podría llevar a que un edificio fácilmente se cayera.

Paralelamente, el tiempo de ejecución es algo intrínsecamente importante. No es lo
mismo resolver un problema en 5 minutos a demorarse 5 semanas. Por esta razón la mayoría
de los algoritmos geométricos se programan en C++, siendo este uno de los lenguajes más
eficientes1 que se pueden utilizar actualmente, sólo estando a la par C, pero con la diferencia
de que C++ tiene clases, que es justamente lo que se utiliza en geometría.

## 2. Elementos a implementar.
La idea tras esta tarea (y todas en general) es ir construyendo los elementos y algoritmos
geométricos más tradicionales de forma incremental. Por esta razón en la presente tarea
implementaremos los elementos más básicos para posteriormente usarlos y refinarlos. Toda
esta tarea debe estar implementada en C++. Algunos puntos incluirán preguntas
que deberán ser respondidas en un archivo txt sólo usando la enumeración de la pregunta.
No es necesario hacer un informe.

A continuación se presentarán los elementos a ser construidos en un orden sugerido, ya
que perfectamente algunos elementos pueden y serán parte de otros.

1. **Clase PUNTO.** Por el momento se trabajará en 2D, pero se deberá poder instanciar
tanto como Integer o como Double u otro tipo primitivo, por tanto debe usar un
template. Un punto debe poder realizar operaciones básicas con otros puntos como la
suma, la resta, etc.

2. **Clase VECTOR.** No confundir con un vector de C++. Para ello, se les recuerda que
un vector parte en el origen y se debe poder normalizar y operar con otros vectores
utilizando producto cruz y punto. ¿Qué ocurre cuando se normaliza un vector con
base en Integer y otro en base a Double? (Pregunta válida producto cruz y punto) Si
se empezaran a usar números muy pequeños o muy grandes y principalmente números
primos, ¿Qué ocurre en términos de precisión? Ejemplifique.

3. **Clase SEGMENTO.** Un segmento está constituido por dos puntos, tiene un determinado largo y tiene la facultad de poder identificar si un punto está a la izquierda o
a la derecha de este (o eventualmente sobre). Para este caso se deberá probar nuevamente con Integers y Doubles y evaluar los problemas de precisión para puntos muy
cercanos al segmento en sí. ¿En qué caso es más preciso? ¿Por qué?

4. **Clase POLÍGONO.** Un polígono contiene puntos que pueden (o no) formar segmentos. Se necesita saber si sus puntos están o no en formato CCW2 para poder calcular
el área del polígono. Así mismo se debe poder averiguar si un punto está o no dentro
del polígono. Discuta sobre posibles problemas de precisión.

## Intro Solución 1.

En esta tarea se vio la implementación de elementos de la geometría computaional y sus operaciones. Se analizaron casos de precisión y se confirmó lo explicado en clase.

Con respecto a las preguntas del enunciado, se pudo apreciar que, en la mayoría de los cálculos, las operaciones tienen correctitud para valores con mantisa <= 16. Para valores mayores, hay errores de aproximación, entregando los peores resultados para encontrar si un punto está sobre una recta o si un polígono pueda ser con orientación positiva o negativa, dependiendo de los valores entregados.

Lo anterior se probó para valores muy pequeños (.9999999999999999) y muy grandes (1234567890123456). Ambos con mantisa 16. En ambos casos, se perdió precisión. Dado el resultado anterior, no se vió cambios para cuando los valores fueran primos. Se probó con valores desde https://primes.utm.edu/lists/small/millions/ y los resultados fueron correctos para primos de mantisa == 9.

Se intentó responder la pregunta de para que casos la evaluación de si un punto está a la derecha o la izquierda era más preciso, sin embargo, como se menciona en varias fuentes, el error existe por ambos lados.
- https://people.mpi-inf.mpg.de/~mehlhorn/ftp/classroomExamplesNonrobustness.pdf
- https://www.youtube.com/watch?v=yuGo2m_B5V8
- https://github.com/mikolalysenko/robust-arithmetic-notes

# Tarea 2 - Cerradura Convexa

## 1. Introducción
La cerradura convexa, aparte de ser un conjunto matemático de puntos que cumplen
ciertas condiciones, es algo que va más allá de la teoría y se utiliza activamente en distintas aplicaciones. Tales como reconocimiento de patrones, procesamiento de imágenes,
información geográfica e incluso cosas como la teoría de juegos.
Por todo ello y mucho más, hoy en día existen al menos 8 formas distintas de implementar dicho algoritmo y el objetivo principal de esta tarea, será probar al menos dos de
ellas utilizando como base su Tarea 1.

## 2. Elementos a implementar
Esta tarea será implementada sobre su Tarea 1 y, por tanto, toda esta tarea debe
estar implementada en C++.

La tarea está dividida en tres secciones:

1. Debe usted implementar el algoritmo de Gift Wrapping, el cual debe recibir como
argumento un listado de puntos y debe retornar el polígono que representa la cerradura. Puede usted guiarse por la siguiente firma: Polygon giftWrapping(Point\[\]cloud).

2. Como Gift Wrapping tiene peor caso O(n^2) y podemos estar trabajando con nubes de
millones de puntos, es necesario poder utilizar otro algoritmo de cerradura convexa
que tenga un mejor peor caso. Por ello, usted debe implementar UNO de los siguientes
algoritmos (que siga la misma firma que Gift Wrapping):
- Graham scan
- Quickhull
- Divide and conquer
- Monotone chain
- Incremental convex hull algorithm
- The ultimate planar convex hull algorithm
- Chan’s algorithm

3. Una vez implementado ambos métodos, es necesario compararlos para ver cuál es
más eficiente con respecto a la cantidad de puntos. Por ello, debe implementar un
método que genere una lista aleatoria de puntos de tamaño 2^10 y a continuación
otro método debe utilizar dicha lista para calcular la cerradura convexa con ambos
algoritmos (y en consecuencia, medir sus tiempos). OJO: También debe comparar
que una vez terminado el procesamiento de ambas cerraduras, estas deben
ser idénticas, ya que la cerradura convexa es única.


## Propuesta solucion 

Para la tarea 2 se tomó como base la tarea 1.
El código de esta tarea, al igual que en la anterior, corre en el Main.
Main por su parte llama a las distintas librerías (GiftWrapping & QuickHull).
En main se prueba con 2 sets de puntos creados a mano y al final con una lista de puntos (1024) generados al azar, dentro de un rango (0-1000).
La respuesta del main es el tiempo de ejecución de cada algoritmo y el tamaño y listado de puntos de cada polígono de la cerradura convexa.
Se puede apreciar que la lista de los puntos son iguales y se puede apreciar los tiempos de ejecución.

### Generalidades:

En esta tarea se requieren construir dos algoritmos de cerradura convexa.
Se implementó GiftWrapping y QuickHull.
Ambos algoritmos se desarrollaron desde el pseudocódigo en Wikipedia.
Ambos algoritmos se programaron para funcionar con Templates.
Por simplicidad, ambos algoritmos se programaron en los archivos de headers (.h).
Para el cálculo del tiempo de ejecución se trabajó con la función clock_gettime.
    Al revisar los resultados, se pueden apreciar ciertas diferencias entre los tiempos,
    que no concuerdan en todos los casos con lo esperado GW: O(nh) vs QH: O(n log n).
    Dado a que se trabajó en una máquina Virtual (Oracle VirtualBox) con Ubuntu, montada sobre Windows 7;
    Se propone que el método para el cálculo de tiempo de ejecución podría estar incorrecto.

### Sobre las restricciones y conseraciones:

Se realizaron ciertas pruebas:
1. 4 puntos: triangulo con punto intermedio. La cerradura fue correcta.
2. 10 puntos: un cuadrado con varios puntos en el centro. La cerradura fue correcta.
3. 1024 puntos: Puntos generados al azar con una función srand, con seed del time().
    La cerradura se presume correcta.
    Ambos algoritmos dieron el mismo resultado: Mismos puntos, mismo orden.

No se tomaron muchos supuestos, es decir, no se analizaron en profundidad los casos degenerados.
Si bien se estudiaron varios posibles casos degenerados en clases, no se probaron para esta implementación.

### Resultados
La información de la ejecución del código se entrega en el siguiente formato:
GiftWrapping elapsed time: 2.428587 (ms) //Tiempo de ejecución
Polygon: [15] // Número de puntos y lista de puntos:
((1, 354, 0),
(5, 33, 0),
(9, 17, 0),
(24, 8, 0),
(48, 4, 0),
(337, 0, 0),
(974, 0, 0),
(999, 27, 0),
(998, 967, 0),
(974, 994, 0),
(877, 999, 0),
(152, 999, 0),
(54, 988, 0),
(6, 982, 0),
(2, 598, 0))

De la misma manera para QuickHull:

QuickHull elapsed time: 0.832499 (ms)
Polygon: [15]
((1, 354, 0),
(5, 33, 0),
(9, 17, 0),
(24, 8, 0),
(48, 4, 0),
(337, 0, 0),
(974, 0, 0),
(999, 27, 0),
(998, 967, 0),
(974, 994, 0),
(877, 999, 0),
(152, 999, 0),
(54, 988, 0),
(6, 982, 0),
(2, 598, 0))

Al realizar varias pruebas se puede construir la siguiente tabla:

Iter	Puntos	Poly	GiftWrapp(ms)	QuickHull(ms)
1	    1024	15	    2.428587	    0.832499
2	    1024	16	    0.490488	    0.393661
3	    1024	21	    0.980652	    0.659969
4	    1024	16	    0.501581	    0.402675
5	    1024	20	    0.655186	    0.438908
6	    1024	15	    0.468952	    0.400286
7	    1024	20	    0.62599	        0.690908
8	    1024	17	    0.561482	    1.800043
9	    1024	18	    0.776858	    0.676925
10	    1024	15	    0.47111	        0.702385

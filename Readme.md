# Prefacio
Como habéis visto en los proyectos anteriores (Cetris y CSnake), la prioridad era sacar rápidamente el codigo y había poco o ninguno cuidado con la arquitectura del proyecto.
Dichos proyectos únicamente tenían la intención de expresar un algoritmos y unos conceptos como estructuras (struct), punteros (o arreglos) y la estructura básica de cualquier programa orientado al desarrollo de un videojuego.
Ahora lo veréis un codigo mas orientado a la Arquitectura del Proyecto.

# Introduccion
Quiero desmontar que un codigo bien hecho (limpio y ordenado), no depende del lenguaje.Depende se su organización.
Como habéis visto en proyectos como el Cetris ( un Tetris en C) todo el proyecto era un único archivo de poco mas de 500 lineas.Este parecía un espagueti pero funcional. Donde teníamos las constantes y variables al principio seguido las funciones o métodos y por ultimo el Main que llamaba a todos.
Para CSnake ( un Snake en C) eran demasiadas líneas y muchos conceptos y se optó por fraccionar en codigo en otros ficheros guardando cierta coherencia.
Pois con BlockDude usando la experiencia de proyectos anteriores, "vamos" desde zero organizar y montar un nuevo proyecto. Rompiendo asi el mito de que en lenguajes antiguos no se puede hacer codigo limpio y ordenado

# Estructura 
Creo que para todos es fácil comprender la arquitectura MVC (Modelo-Vista-Controlador) y es lo que pretendo usar aqui.
Nuestros modelos serán los tipo de datos (Struct) que crearemos para resolver el problema. Las vistas serán todo el apartado grafico y de interface de usuario. Y por ultimo los Controladores serán las funciones que atendiendo una petición de la interface de usuario, manipulará las estructura para dotarlas de información y responder a la interface la petición.

```
📁Proyecto
├─📁Dependencia
│ ├─ ...
│ ├─ ...
│ └─📄 ...
├─📁Modelo
├─📁Vista
├─📁Controlador
└─📝main.c
```
No todo el codigo lo escribiremos nosotros, parte de él serán librerías externas como SDL que usaremos para dibujar en pantalla. Son `Dependencias` que tiene nuestro proyecto.
Otras cosa importante, será el "correcto" uso de los ficheros de cabecera (.h) . Los cuales únicamente contendrán estructuras y definición de funciones  implementada en el fichero del mismo nombre pero con extension (.c)

## ¡Manos a obras!
Puede parecer de lo mas desnecesario. pero a la larga y conforme pase el tiempo resulta mas rapido consultar cada estructura/tipo dato en su fichero en vez de hacer una collecion de varios en un mismo. Este debe ser nuestro primer paso para logra un codigo ordenado.


```
📁Proyecto
└─📁Modelo
  ├─📄 Collection.c
  ├─📄 Collection.h
  ├─📄 Player.h
  └─📄 Point2D.h
```
**Nota:**
>Lo normal es que cuando tenemos en una carpeta de Modelo; Definicion del modelo (Entidad)  y Funciones/Metodos(Repositorio, Casteo o Mapeo) que manipula el modelo independientemente del uso que se dará mas adelante,  por ejemplo:
>> _como una funciono que convierte un array a una lista._
>"Lo normal" .. es que separemos en carpeta Entidad y carpeta Helper (ayudantes).
>Aqui no lo haremos porque los ficheros com extension ".c" cumplem esta funcion.


# Prueba-Unidad-2
Sistema de Gestión de Proyectos Académicos y Módulo Ahorcado
Este proyecto es una solución integral desarrollada en C++ diseñada para facilitar la administración de evaluaciones académicas. El sistema permite registrar grupos de estudiantes, evaluar sus proyectos mediante múltiples criterios y gestionar un submódulo de entretenimiento interactivo, todo bajo una arquitectura orientada a objetos.

1. Gestión de Evaluación y Calificaciones
Este componente se encarga de procesar las métricas de rendimiento de cada grupo. La lógica permite desglosar la nota en funcionalidad, defensa y estructura, asegurando que la suma base no exceda los 10 puntos. Además, incorpora un sistema de bonificación por innovación y una penalización automática de 0.5 puntos por cada retraso registrado, garantizando un cálculo justo y estandarizado de la nota final.

2. Estructura de Datos y Orientación a Objetos
El sistema utiliza el paradigma de Programación Orientada a Objetos (POO) para organizar la información. Mediante las clases GrupoProyecto y Evaluacion, se logra un alto nivel de encapsulamiento donde cada objeto es responsable de sus propios datos y validaciones. Para el almacenamiento, se combina el uso de arreglos estáticos para la gestión de grupos y vectores dinámicos para el historial del juego, optimizando el uso de la memoria según la necesidad de cada módulo.

3. Algoritmos de Procesamiento y Ordenamiento
Para la presentación de reportes, el software implementa un algoritmo de Ordenamiento de Burbuja (Bubble Sort) modificado. Este no solo organiza a los grupos de mayor a menor nota, sino que aplica un criterio de desempate basado en la profundidad de las observaciones registradas. Esta sección demuestra el manejo de lógica algorítmica manual para manipular estructuras de datos sin depender exclusivamente de funciones predefinidas del lenguaje.

4. Análisis Estadístico y Recursividad
Una de las funcionalidades avanzadas es el cálculo del promedio general de notas mediante un enfoque recursivo. En lugar de utilizar ciclos iterativos tradicionales, el sistema emplea una función que se llama a sí misma para recorrer el arreglo de grupos. Esto permite obtener métricas globales, como el promedio del curso y la identificación del criterio con menor desempeño general, facilitando al docente la toma de decisiones pedagógicas.

5. Control de Errores y Robustez del Sistema
El proyecto pone especial énfasis en la experiencia del usuario y la estabilidad del programa. Se han implementado funciones de validación de tipos (como validarEntero) que previenen cierres inesperados si el usuario ingresa caracteres no numéricos. Asimismo, se gestiona la limpieza del buffer de entrada (cin.ignore) para evitar conflictos entre la lectura de datos primitivos y cadenas de texto completas, asegurando que el flujo del programa sea fluido y sin errores de lectura.

6. Submódulo Lúdico: Ahorcado
El sistema integra una faceta recreativa mediante un juego de Ahorcado que utiliza terminología relacionada con la gestión de proyectos. Este módulo opera de forma independiente pero integrada, permitiendo al usuario elegir niveles de dificultad y acumular puntajes. El juego demuestra el manejo de aleatoriedad, manipulación de strings y persistencia temporal de datos a través de una estructura de historial de partidas.

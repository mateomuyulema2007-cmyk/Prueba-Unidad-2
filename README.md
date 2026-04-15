# Prueba-Unidad-2 GRUPO M
Evaluación de proyectos estudiantiles y defensa técnica
Contexto del caso: Registrar grupos, avances, retrasos, criterios, penalizaciones, bonificaciones y nota final.

1.	ANALISIS

El presente proyecto resuelve la necesidad de gestionar proyectos académicos y evaluaciones de grupos, integrando a su vez un submódulo de entretenimiento (Ahorcado).

•	Actores: Docente (usuario principal del sistema), Grupos de Estudiantes, y el Jugador (para el submódulo lúdico).

•	Variables principales: codigo, tema, integrantes, avance, retrasos, y las notas desglosadas (funcionalidad, defensa, estructura, innovacion).

•	Validaciones y Restricciones: La validación más crítica ocurre en el registro de evaluación: la suma de la nota base (funcionalidad, defensa, estructura) no puede ser mayor a 10.0. Adicionalmente, el sistema restringe las entradas numéricas mediante una función dedicada (validarEntero) para evitar desbordamientos o caídas del programa por caracteres no válidos. La nota final se topa a un máximo de 10 y un mínimo de 0, aplicando una penalización de 0.5 puntos por cada retraso.

•	Reportes y Casos Críticos: El sistema genera reportes de notas ordenadas, estadísticas de promedios, búsqueda lineal y el cálculo del criterio con menor desempeño general. Un caso crítico identificado es el intento de calcular un promedio o buscar el menor desempeño cuando no existen grupos registrados (evitado lógicamente).

•	Prueba de escritorio mínima: 
Escenario: 
Registro de un grupo con retrasos.
Entrada: Funcionalidad = 3.0, Defensa = 3.0, Estructura = 3.0, Innovación = 1.0. Retrasos = 2.
Proceso: Suma base = 9.0. Suma + Innovación = 10.0. Penalización = 2 * 0.5 = 1.0. Nota final = 10.0 - 1.0.
Salida esperada: Nota final = 9.0

2.	DISEÑO

El diseño del sistema se fundamenta en la Programación Orientada a Objetos, definiendo las siguientes estructuras:
	
•	Clases y Atributos: 
Evaluacion: Encapsula las métricas de calificación y valida matemáticamente la coherencia de las notas.
GrupoProyecto: Contiene los datos descriptivos del grupo y una instancia de Evaluacion (composición).	
ModuloAhorcado: Gestiona la lógica del minijuego, con arreglos de palabras clasificadas por dificultad y un vector dinámico para el historial.

•	Estructuras de almacenamiento: Se utiliza un arreglo estático de objetos GrupoProyecto grupos[50] para la gestión en memoria de los registros, y la estructura de C++ vector<HistorialAhorcado> para almacenar las partidas del juego sin un límite rígido predefinido.

•	Menús y Relación: El sistema opera a través de un menú principal de 7 opciones que orquesta las funciones del arreglo de objetos. La opción 6 actúa como un puente hacia un submenú independiente de 4 opciones para el Ahorcado. Ambos módulos operan de forma encapsulada pero convergen en la misma interfaz de consola.


3.	CONSTRUCCION INCREMENTAL

El código fue construido siguiendo una metodología escalonada para asegurar la estabilidad en cada etapa:

•	Estructura base: Se implementó el cascarón del archivo main, las bibliotecas necesarias (iostream, vector, algorithm, etc.) y el bucle principal do-while del menú.

•	Registros y Validaciones: Se programaron las clases GrupoProyecto y Evaluacion. Se implementó el control de errores validarEntero y el método setNotas para evitar el ingreso de datos basura o lógicamente incorrectos.

•	Reportes y Búsqueda: Se programó el recorrido del arreglo para mostrar los grupos y la función buscarGrupo mediante coincidencia de strings.

•	Recursividad: Se diseñó la función calcularPromedioRecursivo, aplicando el caso base (n <= 0 y n == 1) y el llamado recursivo para iterar matemáticamente sobre el arreglo de notas sin usar ciclos convencionales.

•	Ordenamiento Manual: Se implementó el algoritmo de "Bubble Sort" (Ordenamiento de burbuja) modificado. Éste no solo ordena descendentemente por la nota final, sino que en caso de empate, desempata midiendo la longitud del string de las observaciones.

•	Módulo Ahorcado: Finalmente, se construyó la clase ModuloAhorcado, implementando la aleatoriedad (srand), el control de intentos, la verificación por caracteres (isalpha, toupper) y el almacenamiento en la estructura HistorialAhorcado.

4.	PRUEBAS Y DEPURACION
•	Casos Normales: Registro de múltiples proyectos con datos estándar, visualización del ranking ordenado y partidas de ahorcado completadas con éxito, verificando la acumulación correcta de puntos.

•	Casos Límite: Ingreso de letras en los campos de nota o menús. El programa no se colgó, gracias al limpiado del buffer (cin.clear() y cin.ignore()). Se intentó calcular el promedio con el arreglo vacío, arrojando correctamente el mensaje de prevención.

•	Corrección Importante: Durante el desarrollo y registro de datos mezclados (números y cadenas de texto), se detectaron saltos de línea residuales en el buffer que causaban que la variable "Tema" u "Observaciones" se saltaran el ingreso por teclado (getline tomaba el Enter residual). Explicación de la solución: Se procedió a incluir cin.ignore(); antes de invocar getline(cin, ...) tras la lectura de datos primitivos (int, string sencillo). Además, se corrigió un problema de tipeo detectado en la línea defectuosa del esqueleto donde se duplicaba la salida cout << "Estructura:"; cout << "Estructura: "; cin >> est;.
encia temporal de datos a través de una estructura de historial de partidas.

Depuracion del Codigo defectudoso(Freagmento Asignado)

float calcularNotaFinal(float funcionalidad, float defensa, float penalizacion) {
    // Sumamos los criterios y restamos la penalización
    // Nota: Asumimos que la suma de funcionalidad + defensa es la base
    float nota = (funcionalidad + defensa) - penalizacion;

    // Validación de límites (Rango 0 - 10)
    if (nota > 10) {
        nota = 10;
    }
    if (nota < 0) {
        nota = 0;
    }

    return nota;
}
Prueba de solcion Pequenia
<img width="593" height="335" alt="image" src="https://github.com/user-attachments/assets/28157ce9-6291-45ff-8678-6482bee3881a" />


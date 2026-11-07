# Sistema de control de calificaciones de un centro educativo

- **Nombre:** John Sevastian Lake Mota
- **Matrícula:** 2025-3713

## Descripción del programa

Programa de consola en C++ para el centro educativo "La Nueva Escuela". Registra las calificaciones de un grupo de estudiantes, calcula el promedio de cada uno, indica si está **Aprobado** (70 o más) o **Reprobado** y, al terminar el grupo, muestra un resumen con la cantidad de aprobados y reprobados, el promedio general y el estudiante con el mejor promedio. Al final pregunta si se desea procesar otro grupo y, si la respuesta es `s`, el programa se repite desde el inicio.

El programa se resuelve únicamente con variables y bucles, sin arreglos, vectores ni funciones propias.

## Datos de entrada

- Cantidad de estudiantes del grupo (número entero mayor que 0).
- Nombre de cada estudiante.
- 4 calificaciones por estudiante (cada una entre 0 y 100).
- Respuesta a la pregunta de si desea procesar otro grupo (`s` o `n`).

## Proceso

1. Solicita la cantidad de estudiantes; si el valor no es válido (0, negativo o texto), vuelve a solicitarlo.
2. Para cada estudiante solicita el nombre y las 4 calificaciones; si una calificación está fuera del rango de 0 a 100, repite la solicitud de esa calificación.
3. Suma las calificaciones en un **acumulador** y calcula el promedio del estudiante (suma ÷ 4). Si el promedio es 70 o más, incrementa el **contador** de aprobados; en caso contrario, el de reprobados.
4. Acumula los promedios de todos los estudiantes para obtener el promedio general del grupo y va guardando el nombre y el promedio del estudiante con el promedio más alto.
5. Al terminar el grupo muestra el resumen y pregunta si desea procesar otro grupo; con `s` repite desde el paso 1 (reiniciando contadores y acumuladores) y con `n` finaliza.

## Datos de salida

- Por cada estudiante: su promedio con dos decimales y su condición (Aprobado o Reprobado).
- Resumen del grupo: cantidad de aprobados y reprobados, promedio general del grupo (dos decimales) y nombre y promedio del estudiante con el promedio más alto.
- Mensajes de error cuando se ingresa un dato no válido.

## Capturas de pantalla

**1. Ejecución normal** (grupo de 3 estudiantes con aprobados y reprobados)

![Ejecución normal](imagenes/captura1_ejecucion_normal.png)

**2. Validación de la cantidad de estudiantes** (se rechazan 0, -5 y texto)

![Validación de la cantidad de estudiantes](imagenes/captura2_validacion_cantidad.png)

**3. Validación de las calificaciones** (se rechazan 105, -10 y texto)

![Validación de las calificaciones](imagenes/captura3_validacion_calificaciones.png)

**4. Repetición del programa** (otro grupo con `s` y salida con `n`)

![Repetición del programa](imagenes/captura4_repetir_grupo.png)

## Uso de los bucles: dónde y por qué

| Bucle | Dónde se usa | Por qué |
|-------|--------------|---------|
| `for` | Recorre los estudiantes del grupo. | Se conoce de antemano cuántas veces se repite: una por cada estudiante (`cantidadEstudiantes`). |
| `for` | Recorre las 4 calificaciones de cada estudiante (dentro del `for` anterior). | La cantidad de repeticiones es fija (4) y se controla con un contador. |
| `while` | Validación de la cantidad de estudiantes, de cada calificación y de la respuesta `s`/`n`. | No se sabe cuántas veces se equivocará el usuario. La solicitud se repite **mientras** el dato no sea válido (`while (!datoValido)`). |
| `do-while` | Bucle principal que repite todo el programa para procesar otro grupo. | El grupo debe procesarse **al menos una vez**, y la pregunta "¿desea procesar otro grupo?" se hace al final, por lo que la condición se evalúa después de ejecutar el cuerpo. |

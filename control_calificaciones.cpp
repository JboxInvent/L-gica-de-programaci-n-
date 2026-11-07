/*
 * ===========================================================================
 *  SISTEMA DE CONTROL DE CALIFICACIONES - Centro educativo "La Nueva Escuela"
 * ===========================================================================
 *  Estudiante : John Sevastian Lake Mota
 *  Matricula  : 2025-3713
 *  Asignatura : Logica de Programacion
 *  Profesor   : Ing. Gamalier Reyes del Carmen
 *  Tema       : Uso de bucles (estructuras de control repetitivas)
 *
 *  Programa de consola que registra las calificaciones de un grupo de
 *  estudiantes, calcula el promedio de cada uno, indica si esta Aprobado o
 *  Reprobado y muestra un resumen del grupo. Al final pregunta si se desea
 *  procesar otro grupo.
 * ===========================================================================
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    // -----------------------------------------------------------------------
    // CONSTANTES (valores fijos del problema)
    // -----------------------------------------------------------------------
    const int    CANTIDAD_CALIFICACIONES = 4;      // calificaciones por estudiante
    const double CALIFICACION_MINIMA     = 0.0;    // nota minima permitida
    const double CALIFICACION_MAXIMA     = 100.0;  // nota maxima permitida
    const double PROMEDIO_APROBACION     = 70.0;   // promedio minimo para aprobar

    // -----------------------------------------------------------------------
    // VARIABLES
    // -----------------------------------------------------------------------
    int    cantidadEstudiantes   = 0;    // cuantos estudiantes tiene el grupo
    int    numeroEstudiante      = 0;    // contador del bucle de estudiantes
    int    numeroCalificacion    = 0;    // contador del bucle de calificaciones
    string nombreEstudiante      = "";   // nombre del estudiante actual
    double calificacion          = 0;    // calificacion que ingresa el usuario
    double sumaNotas             = 0;    // ACUMULADOR: suma de las notas de un estudiante
    double promedioEstudiante    = 0;    // promedio del estudiante actual

    int    cantidadAprobados     = 0;    // CONTADOR de estudiantes aprobados
    int    cantidadReprobados    = 0;    // CONTADOR de estudiantes reprobados
    double sumaPromedios         = 0;    // ACUMULADOR: suma de los promedios del grupo
    double promedioGrupo         = 0;    // promedio general del grupo
    double mejorPromedio         = 0;    // promedio mas alto del grupo
    string nombreMejorEstudiante = "";   // estudiante con el promedio mas alto

    bool   datoValido            = false; // bandera para los bucles de validacion
    char   respuestaOtroGrupo    = 'n';   // respuesta del usuario: 's' o 'n'

    // Todos los numeros con decimales se muestran con dos decimales.
    cout << fixed << setprecision(2);

    cout << "===== SISTEMA DE CONTROL DE CALIFICACIONES =====\n";
    cout << "Centro educativo \"La Nueva Escuela\"\n\n";

    // =======================================================================
    // BUCLE DO-WHILE (principal): repite el programa completo.
    // Se usa do-while porque el grupo se debe procesar al menos una vez; la
    // pregunta "otro grupo?" se hace al final, cuando ya se proceso el grupo.
    // =======================================================================
    do {
        // -------------------------------------------------------------------
        // Se reinician los contadores y acumuladores para el nuevo grupo
        // (si no se reiniciaran, conservarian los valores del grupo anterior).
        // -------------------------------------------------------------------
        cantidadAprobados     = 0;
        cantidadReprobados    = 0;
        sumaPromedios         = 0;
        mejorPromedio         = -1;   // menor que cualquier promedio posible
        nombreMejorEstudiante = "";

        // -------------------------------------------------------------------
        // PASO 1: pedir la cantidad de estudiantes.
        // BUCLE WHILE (validacion): repite la solicitud MIENTRAS el dato no
        // sea valido (numero entero mayor que 0). No se sabe cuantas veces se
        // equivocara el usuario, por eso la condicion controla la repeticion.
        // -------------------------------------------------------------------
        datoValido = false;
        while (!datoValido) {
            cout << "Cantidad de estudiantes: ";
            cin >> cantidadEstudiantes;

            if (cin.fail()) {              // se escribio texto en lugar de un numero
                cin.clear();               // se restablece el estado de cin
                cantidadEstudiantes = 0;   // se marca como valor invalido
            }
            cin.ignore(1000, '\n');        // se descarta el resto de la linea (el Enter)

            if (cantidadEstudiantes > 0) {
                datoValido = true;         // dato correcto: el bucle termina
            } else {
                cout << "  Error: debe ingresar un numero entero mayor que 0.\n";
            }
        }

        // -------------------------------------------------------------------
        // PASO 2 y 3: datos, promedio y estado de cada estudiante.
        // BUCLE FOR (estudiantes): se conoce de antemano cuantas veces se
        // repite (una vez por cada estudiante del grupo).
        // -------------------------------------------------------------------
        for (numeroEstudiante = 1; numeroEstudiante <= cantidadEstudiantes; numeroEstudiante++) {
            cout << "\n--- Estudiante " << numeroEstudiante << " ---\n";
            cout << "Nombre: ";
            getline(cin, nombreEstudiante);

            sumaNotas = 0;   // el acumulador empieza en 0 con cada estudiante

            // ---------------------------------------------------------------
            // BUCLE FOR (calificaciones): se repite exactamente 4 veces, una
            // por cada calificacion del estudiante.
            // ---------------------------------------------------------------
            for (numeroCalificacion = 1; numeroCalificacion <= CANTIDAD_CALIFICACIONES; numeroCalificacion++) {

                // -----------------------------------------------------------
                // BUCLE WHILE (validacion): repite la solicitud de ESTA
                // calificacion MIENTRAS no este entre 0 y 100.
                // -----------------------------------------------------------
                datoValido = false;
                while (!datoValido) {
                    cout << "Calificacion " << numeroCalificacion << ": ";
                    cin >> calificacion;

                    if (cin.fail()) {          // se escribio texto en lugar de un numero
                        cin.clear();
                        calificacion = -1;     // valor fuera de rango (invalido)
                    }
                    cin.ignore(1000, '\n');

                    if (calificacion >= CALIFICACION_MINIMA && calificacion <= CALIFICACION_MAXIMA) {
                        datoValido = true;
                    } else {
                        cout << "  Error: la calificacion debe estar entre 0 y 100.\n";
                    }
                }

                sumaNotas = sumaNotas + calificacion;   // ACUMULADOR de notas
            }

            // Promedio del estudiante y su estado (Aprobado / Reprobado)
            promedioEstudiante = sumaNotas / CANTIDAD_CALIFICACIONES;
            cout << "Promedio: " << promedioEstudiante << " - ";

            if (promedioEstudiante >= PROMEDIO_APROBACION) {
                cout << "Aprobado\n";
                cantidadAprobados++;        // CONTADOR de aprobados
            } else {
                cout << "Reprobado\n";
                cantidadReprobados++;       // CONTADOR de reprobados
            }

            // ACUMULADOR de promedios (sirve para el promedio general)
            sumaPromedios = sumaPromedios + promedioEstudiante;

            // Se guarda el mejor promedio (si hay empate, se queda el primero)
            if (promedioEstudiante > mejorPromedio) {
                mejorPromedio = promedioEstudiante;
                nombreMejorEstudiante = nombreEstudiante;
            }
        }

        // -------------------------------------------------------------------
        // PASO 4: resumen del grupo
        // -------------------------------------------------------------------
        promedioGrupo = sumaPromedios / cantidadEstudiantes;

        cout << "\n===== RESUMEN =====\n";
        cout << "Aprobados: " << cantidadAprobados
             << " | Reprobados: " << cantidadReprobados << "\n";
        cout << "Promedio del grupo: " << promedioGrupo << "\n";
        cout << "Mejor promedio: " << nombreMejorEstudiante
             << " (" << mejorPromedio << ")\n";

        // -------------------------------------------------------------------
        // PASO 5: preguntar si se desea procesar otro grupo.
        // BUCLE WHILE (validacion): repite la pregunta MIENTRAS la respuesta
        // no sea 's' ni 'n' (se aceptan mayusculas y minusculas).
        // -------------------------------------------------------------------
        cout << "\n";
        datoValido = false;
        while (!datoValido) {
            cout << "Desea procesar otro grupo? (s/n): ";
            cin >> respuestaOtroGrupo;
            cin.ignore(1000, '\n');

            if (respuestaOtroGrupo == 's' || respuestaOtroGrupo == 'S' ||
                respuestaOtroGrupo == 'n' || respuestaOtroGrupo == 'N') {
                datoValido = true;
            } else {
                cout << "  Error: escriba 's' para si o 'n' para no.\n";
            }
        }
        cout << "\n";

    } while (respuestaOtroGrupo == 's' || respuestaOtroGrupo == 'S');

    cout << "Programa finalizado. Hasta luego!\n";
    return 0;
}

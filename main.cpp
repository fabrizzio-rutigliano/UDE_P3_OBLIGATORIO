#include "menu.h"
//#include "testEscolaridad.h"
//#include "testAsignatura.h"
//#include "testAsignaturas.h"
//#include "testAlumno.h"
//#include "testAlumnos.h"
//#include "testCurricula.h"

/*

Fecha String arreglar boolean, y limpiar no utilizables (Gus)9 Done!

Alumno  GP
Alumnos GP
Asignatura Gus Done!
Asignaturas Gus Done!
Curricula Fabri
Constantes GP
Menu Gus

Crear alumno -> Crear de escolaridad
*/

int main() {

    int opcion;
    Asignaturas asigns;
    Alumnos als;


    Crear(asigns);
    
    //crear alumnos
    Make(als);

    //Inicializar matriz de adyacencia Curricula

    
    //testEscolaridad();
    //testEscolaridad();
    //testAlumno();
    //testAlumnos();
    //ejecutarTestAsignatura();
    //ejecutarTestAsignaturas();

    do
    {
        desplegarMenuPrincipal(opcion);
        switch (opcion)
        {
        case 1:
            printf("\nSelecciono registrar nueva asignatura\n");
            AgregarAsignaturaEnAsignaturas(asigns);
            break;
        case 2:
            printf("Selecciono agregar previatura");
            // Fabri
            break;
        case 3:
            printf("Selecciono inscribir nuevo alumno");
            //GP en curso
            break;
        case 4:
            printf("Selecciono registrar curso en escolaridad");
            break;
        case 5:
            printf("Selecciono listar asignaturas");//GUS
            break;
        case 6:
            printf("Selecciono listar previaturas");
            // Fabri
            break;
        case 7:
            printf("Selecciono listar alumno por cédula");//Gus
            break;
        case 8:
            printf("Selecciono listar escolaridad alumno");
            //GP
            break;
        case 9:
            break;
        default:
            printf("Opcion incorrecta!\n");
            break;
        }

    }
    while(opcion!=9);

    //destruir Asignaturas
    destruirAsignaturas(asigns);

    //destruir alumnos


   

    return 0;
}
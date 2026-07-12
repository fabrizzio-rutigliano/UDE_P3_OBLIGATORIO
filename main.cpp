#include "menu.h"
#include "stdio.h"
#include "testEscolaridad.h"
#include "testAsignatura.h"
#include "testAsignaturas.h"
/*

Fecha String arreglar boolean, y limpiar no utilizables (Gus)9 Done!

Alumno  GP
Alumnos GP
Asignatura Gus Done!
Asignaturas Gus Done!
Curricula Fabri
Constantes GP
Menu Gus

*/

int main() {

    int opcion;
    //testEscolaridad();
    //ejecutarTestAsignatura();
    ejecutarTestAsignaturas();

    /*do
    {
        desplegarMenuPrincipal(opcion);
        switch (opcion)
        {
        case 1:
            printf("Selecciono registrar nueva asignatura");
            break;
        case 2:
            printf("Selecciono agregar previatura");
            break;
        case 3:
            printf("Selecciono inscribir nuevo alumno");
            break;
        case 4:
            printf("Selecciono registrar curso en escolaridad");
            break;
        case 5:
            printf("Selecciono listar asignaturas");
            break;
        case 6:
            printf("Selecciono listar previaturas");
            break;
        case 7:
            printf("Selecciono listar alumno por cédula");
            break;
        case 8:
            printf("Selecciono listar escolaridad alumno");
            break;
        case 9:
            break;
        default:
            printf("Opcion incorrecta!\n");
            break;
        }

    }
    while(opcion!=9);*/

    return 0;
}
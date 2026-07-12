#include "menu.h"

//Muestra el menu principal
void desplegarMenuPrincipal(int &opcion){
    printf("\n***Menu de Principal***\n");
    printf("Ingrese una opcion:\n");
    printf("1 - Registrar nueva asignatura\n");
    printf("2 - Agregar previatura\n");
    printf("3 - Inscribir nuevo alumno\n");
    printf("4 - Registrar curso en escolaridad\n");
    printf("5 - Listar asignaturas\n");
    printf("6 - Listar previaturas\n");
    printf("7 - Listar alumno por cédula\n");
    printf("8 - Listar escolaridad alumno\n");
    printf("9 - Salir del programa\n");

    scanf("%d", &opcion);
}
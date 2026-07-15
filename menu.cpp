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

// Auxiliares para requerimiento 2

void AsignaturaInvalida(Asignaturas asigns, int &asig){
    if (!ExisteAsignatura(asigns, asig))
        printf("Error: Asignatura ingresada no es valida...");
}

void IngresarPreviatura(Asignaturas asigns, int &prev, int &requiere){
    
    do{
        printf("\nIngrese el nro de la asignatura previa: \n");
        scanf("%d", &prev);
        AsignaturaInvalida(asigns, prev);
    }while(ExisteAsignatura(asigns, prev) == false);

    do{
    printf("\nIngrese el nro de la asignatura de la que es previa: \n");
    scanf("%d", &requiere);
    }while(ExisteAsignatura(asigns, requiere) == false);
}



void ErrorGeneraCiclo(){
    printf("Error: La asignatura previa genera un ciclo....");
}

// Auxiliares para requerimiento 6
void IngresarNroAsignatura(Asignaturas asigns,int &asig){
    do{
        printf("\nIngrese el nro de la asignatura: \n");
        scanf("%d", &asig);
        AsignaturaInvalida(asigns, asig);
    }
    while(ExisteAsignatura(asigns, asig) == false);
}


void ErrorExisteAlumno()
{
    printf("\nError: El alumno ya esta registrado...\n ");
}

void ErrorCursoYaExiste()
{
    printf("\nERROR: El curso ya existe para este alumno...\n");
}

void ErrorFechaCursoAnteriorAlUltimo()
{
    printf("\nERROR: El curso ingresado tiene fecha de fin anterior al ultimo registrado para el alumno...\n");
}

void ErrorNoExisteAlumno()
{
    printf("\nERROR: El alumno no existe...\n");
}

void ErrorEscolaridadVacia()
{
    printf("\nLa escolaridad es vacia...\n");
}

void ErrorAsignaturasMaximas()
{
    printf("\nSe alcanzo el numero maximo de asignaturas...\n");
}
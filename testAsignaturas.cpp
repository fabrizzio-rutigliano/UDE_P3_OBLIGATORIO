#include "testAsignaturas.h"
#include "asignaturas.h"

void testCrear(){
    printf("Test Crear: ");

    Asignaturas asigns;

    Crear(asigns);

    if (asigns.tope == 0)
        printf("OK\n");
    else
        printf("ERROR\n");
}

void testEsVacia(){
    printf("Test esVacia: ");

    Asignaturas asigns;

    Crear(asigns);

    if (esVacia(asigns))
        printf("OK\n");
    else
        printf("ERROR\n");
}

void testInsBack(){
    printf("Test InsBack: ");

    Asignaturas asigns;
    Crear(asigns);

    String nom;
    strCrear(nom);
    strCop(nom, (String)"Programacion 3");

    Asignatura asig = cargarAsignatura(301, nom, 96, false);

    InsBack(asig, asigns);

    if (!esVacia(asigns) &&
        asigns.tope == 1 &&
        DarNumero(asigns.arre[0]) == 301)
    {
        printf("OK\n");
    }
    else
    {
        printf("ERROR\n");
    }

    destruirAsignaturas(asigns);
    strDestruir(nom);
}

void testDestruirAsignaturas(){
    printf("Test destruirAsignaturas: ");

    Asignaturas asigns;
    Crear(asigns);

    String nom;
    strCrear(nom);
    strCop(nom, (String)"Base de Datos");

    Asignatura asig = cargarAsignatura(210, nom, 80, false);

    InsBack(asig, asigns);

    destruirAsignaturas(asigns);

    if (esVacia(asigns))
        printf("OK\n");
    else
        printf("ERROR\n");

    strDestruir(nom);
}

void ejecutarTestAsignaturas(){

    printf("\n=================================\n");
    printf("     TESTS DE ASIGNATURAS\n");
    printf("=================================\n");

    testCrear();
    testEsVacia();
    testInsBack();
    testDestruirAsignaturas();

    printf("=================================\n\n");
}
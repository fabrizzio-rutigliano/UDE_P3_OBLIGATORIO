/*#include <stdio.h>

#include "testAsignatura.h"
#include "asignatura.h"

void testDarNumero(){
    printf("Test DarNumero: ");

    String nom;
    strCrear(nom);
    strCop(nom, "Programacion 3");

    Asignatura asig = cargarAsignatura(301, nom, 96, false);

    if (DarNumero(asig) == 301)
        printf("OK\n");
    else
        printf("ERROR\n");

    destruirAsignatura(asig);
    strDestruir(nom);
}

void testDarNombre(){
    printf("Test DarNombre: ");

    String nom;
    String aux;

    strCrear(nom);
    strCrear(aux);

    strCop(nom, "Base de Datos");

    Asignatura asig = cargarAsignatura(210, nom, 80, false);

    DarNombre(asig, aux);

    if (strEq(aux, nom))
        printf("OK\n");
    else
        printf("ERROR\n");

    destruirAsignatura(asig);
    strDestruir(nom);
    strDestruir(aux);
}

void testDarCantidadHoras(){
    printf("Test DarCantidadHoras: ");

    String nom;
    strCrear(nom);
    strCop(nom, "Redes");

    Asignatura asig = cargarAsignatura(400, nom, 120, false);

    if (DarCantidadHoras(asig) == 120)
        printf("OK\n");
    else
        printf("ERROR\n");

    destruirAsignatura(asig);
    strDestruir(nom);
}

void testDarOptativa(){
    printf("Test DarOptativa: ");

    String nom;
    strCrear(nom);
    strCop(nom, "Inteligencia Artificial");

    Asignatura asig = cargarAsignatura(500, nom, 64, true);

    if (DarOptativa(asig))
        printf("OK\n");
    else
        printf("ERROR\n");

    destruirAsignatura(asig);
    strDestruir(nom);
}

void testCargarAsignatura(){
    printf("Test cargarAsignatura: ");

    String nom;
    String aux;

    strCrear(nom);
    strCrear(aux);

    strCop(nom, "Algoritmos");

    Asignatura asig = cargarAsignatura(100, nom, 90, false);

    DarNombre(asig, aux);

    if (DarNumero(asig) == 100 &&
        DarCantidadHoras(asig) == 90 &&
        DarOptativa(asig) == false &&
        strEq(aux, nom))
    {
        printf("OK\n");
    }
    else
    {
        printf("ERROR\n");
    }

    destruirAsignatura(asig);
    strDestruir(nom);
    strDestruir(aux);
}

void ejecutarTestAsignatura(){

    printf("\n=================================\n");
    printf("      TESTS DE ASIGNATURA\n");
    printf("=================================\n");

    testDarNumero();
    testDarNombre();
    testDarCantidadHoras();
    testDarOptativa();
    testCargarAsignatura();

    printf("=================================\n\n");
}

*/
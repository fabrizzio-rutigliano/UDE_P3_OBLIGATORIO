// testCurricula.cpp
/*
#include "testCurricula.h"

// ObtenerPrevias esta implementada en curricula.cpp pero NO esta declarada
// en curricula.h (el header declara en su lugar "ListarTodasLasPrevias",
// que no tiene implementacion). Se declara aqui a mano para poder probarla.
void ObtenerPrevias(Curricula matriz, int numAsig, int topeActual, int resultado[], int &topeResultado);



static void separador(const char *titulo)
{
    printf("\n----- %s -----\n", titulo);
    fflush(stdout);
}

static void mostrarResultado(int resultado[], int topeResultado)
{
    printf("[");
    for (int i = 0; i < topeResultado; i++)
    {
        printf("%d", resultado[i]);
        if (i < topeResultado - 1) printf(", ");
    }
    printf("]");
}

void testCurricula()
{
    printf("=================================================\n");
    printf(" TEST AUTONOMO DEL MODULO CURRICULA\n");
    printf("=================================================\n");
    printf("NOTA IMPORTANTE: el header declara 'GradoVertice' y\n");
    printf("'ListarTodasLasPrevias', pero ninguna de las dos esta\n");
    printf("implementada en curricula.cpp (darian error de linker si\n");
    printf("se llaman). Por eso este test no las invoca. En su lugar,\n");
    printf("curricula.cpp implementa 'ObtenerPrevias' (no declarada en\n");
    printf("el .h), que parece ser la version real del requerimiento 6;\n");
    printf("se prueba mas abajo declarandola a mano.\n");

    // ---------- Crear ----------
    separador("Crear(matriz)");
    Curricula matriz;
    Crear(matriz);
    printf("Resultado: matriz creada (todas las posiciones en 0)\n");

    // ---------- PerteneceVertice ----------
    separador("PerteneceVertice(matriz, vertice, topeActual) - topeActual = 5");
    printf("PerteneceVertice(matriz, 0, 5)  = %s (esperado: true)\n", PerteneceVertice(matriz, 0, 5) ? "true" : "false");
    printf("PerteneceVertice(matriz, 4, 5)  = %s (esperado: true)\n", PerteneceVertice(matriz, 4, 5) ? "true" : "false");
    printf("PerteneceVertice(matriz, 5, 5)  = %s (esperado: false, fuera de rango)\n", PerteneceVertice(matriz, 5, 5) ? "true" : "false");
    printf("PerteneceVertice(matriz, -1, 5) = %s (esperado: false, fuera de rango)\n", PerteneceVertice(matriz, -1, 5) ? "true" : "false");

    // ---------- PerteneceArista antes de insertar ----------
    separador("PerteneceArista(matriz, previa, asignatura) - antes de insertar");
    printf("PerteneceArista(matriz, 0, 1) = %s (esperado: false)\n", PerteneceArista(matriz, 0, 1) ? "true" : "false");

    // ---------- InsertarArista ----------
    // Se arma este grafo de previaturas (previa -> asignatura):
    //   0 -> 1, 1 -> 2, 0 -> 2   (una cadena con un atajo)
    //   3 -> 4                  (una cadena separada)
    separador("InsertarArista(matriz, previa, asignatura)");
    printf("Se ingresa arista (0 -> 1)\n"); InsertarArista(matriz, 0, 1);
    printf("Se ingresa arista (1 -> 2)\n"); InsertarArista(matriz, 1, 2);
    printf("Se ingresa arista (0 -> 2)\n"); InsertarArista(matriz, 0, 2);
    printf("Se ingresa arista (3 -> 4)\n"); InsertarArista(matriz, 3, 4);
    printf("Resultado: 4 aristas insertadas\n");

    // ---------- PerteneceArista despues de insertar ----------
    separador("PerteneceArista(matriz, previa, asignatura) - despues de insertar");
    printf("PerteneceArista(matriz, 0, 1) = %s (esperado: true)\n", PerteneceArista(matriz, 0, 1) ? "true" : "false");
    printf("PerteneceArista(matriz, 1, 2) = %s (esperado: true)\n", PerteneceArista(matriz, 1, 2) ? "true" : "false");
    printf("PerteneceArista(matriz, 0, 2) = %s (esperado: true)\n", PerteneceArista(matriz, 0, 2) ? "true" : "false");
    printf("PerteneceArista(matriz, 3, 4) = %s (esperado: true)\n", PerteneceArista(matriz, 3, 4) ? "true" : "false");
    printf("PerteneceArista(matriz, 2, 0) = %s (esperado: false, no se inserto la inversa)\n", PerteneceArista(matriz, 2, 0) ? "true" : "false");

    // ---------- GeneraCiclo ----------
    separador("GeneraCiclo(matriz, previa, asignatura, topeActual)");
    printf("Se consulta: si agrego (previa=2 -> asignatura=0), formaria ciclo?\n");
    printf("Resultado: %s (esperado: true, ya existe camino 0->1->2 o 0->2)\n",
           GeneraCiclo(matriz, 2, 0, 5) ? "true" : "false");

    printf("Se consulta: si agrego (previa=0 -> asignatura=3), formaria ciclo?\n");
    printf("Resultado: %s (esperado: false, 3 no tiene camino hacia 0)\n",
           GeneraCiclo(matriz, 0, 3, 5) ? "true" : "false");

    printf("Se consulta: si agrego (previa=4 -> asignatura=3), formaria ciclo?\n");
    printf("Resultado: %s (esperado: true, ya existe camino 3->4)\n",
           GeneraCiclo(matriz, 4, 3, 5) ? "true" : "false");

    printf("Se consulta: si agrego (previa=2 -> asignatura=3), formaria ciclo?\n");
    printf("Resultado: %s (esperado: false, cadenas independientes)\n",
           GeneraCiclo(matriz, 2, 3, 5) ? "true" : "false");

    // ---------- ObtenerPrevias (no declarada en el .h, probada igual) ----------
    separador("ObtenerPrevias(matriz, numAsig, topeActual, resultado, topeResultado)");
    int resultado[5];
    int topeResultado;

    ObtenerPrevias(matriz, 2, 5, resultado, topeResultado);
    printf("Previas de 2 = "); mostrarResultado(resultado, topeResultado);
    printf(" (esperado: [0, 1])\n");

    ObtenerPrevias(matriz, 4, 5, resultado, topeResultado);
    printf("Previas de 4 = "); mostrarResultado(resultado, topeResultado);
    printf(" (esperado: [3])\n");

    ObtenerPrevias(matriz, 0, 5, resultado, topeResultado);
    printf("Previas de 0 = "); mostrarResultado(resultado, topeResultado);
    printf(" (esperado: [] , no tiene previas)\n");

    printf("\n=================================================\n");
    printf(" FIN DEL TEST DE CURRICULA\n");
    printf("=================================================\n");
}
    */
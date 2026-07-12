// test_escolaridad.cpp
#include "testEscolaridad.h"

// Muestra un Curso usando las funciones reales del modulo curso
static void mostrarCurso(Curso c)
{
    printf("numero=");
    DesplegarNumero(c);
    printf(", calificacion=");
    DesplegarCalificacion(c);
    printf(", fechaFin=");
    DesplegarFechaFin(c);
    printf("\n");
}

static void separador(const char *titulo)
{
    printf("\n----- %s -----\n", titulo);
    fflush(stdout);
}

void testEscolaridad()
{
    printf("=================================================\n");
    printf(" TEST AUTONOMO DEL MODULO ESCOLARIDAD\n");
    printf(" (usando el modulo curso ya implementado)\n");
    printf("=================================================\n");

    // ---------- Construccion de cursos con CargarCurso ----------
    separador("CargarCurso(nro, fecha, cal) - construccion de datos de prueba");
    Fecha f1 = {15, 3, 2024};
    Fecha f2 = {20, 6, 2024};
    Fecha f3 = {10, 12, 2023};

    Curso c1 = CargarCurso(101, f1, 85);
    Curso c2 = CargarCurso(102, f2, 90);
    Curso c3 = CargarCurso(103, f3, 78);
    printf("c1 = "); mostrarCurso(c1);
    printf("c2 = "); mostrarCurso(c2);
    printf("c3 = "); mostrarCurso(c3);

    // ---------- Verificacion de los Devolver* sobre c1 ----------
    separador("Devolver*(c1) - verificacion de getters de curso");
    printf("DevolverNumero(c1) = %d (esperado 101)\n", DevolverNumero(c1));
    printf("DevolverCalificacion(c1) = %d (esperado 85)\n", DevolverCalificacion(c1));
    Fecha ffAux = DevolverFechaFin(c1);
    printf("DevolverFechaFin(c1) = "); mostrarFecha(ffAux); printf(" (esperado 15/3/2024)\n");

    // ---------- Crear ----------
    Escolaridad e;
    separador("Crear(e)");
    Crear(e);
    printf("Resultado: escolaridad creada (prim y ult en NULL)\n");

    // ---------- EsVacia (lista vacia) ----------
    separador("EsVacia(e) - antes de insertar");
    printf("Resultado: %s\n", EsVacia(e) ? "true (vacia)" : "false (no vacia)");

    // ---------- InsFront ----------
    separador("InsFront(e, c1)");
    printf("Se ingresa: "); mostrarCurso(c1);
    InsFront(e, c1);
    printf("Resultado: insertado al frente. Largo actual = %d\n", Largo(e));

    separador("InsFront(e, c2)");
    printf("Se ingresa: "); mostrarCurso(c2);
    InsFront(e, c2);
    printf("Resultado: insertado al frente. Largo actual = %d\n", Largo(e));

    separador("InsFront(e, c3)");
    printf("Se ingresa: "); mostrarCurso(c3);
    InsFront(e, c3);
    printf("Resultado: insertado al frente. Largo actual = %d\n", Largo(e));
    printf("Orden esperado tras 3 InsFront (c1,c2,c3): c3, c2, c1\n");

    // ---------- EsVacia (lista con elementos) ----------
    separador("EsVacia(e) - despues de insertar");
    printf("Resultado: %s\n", EsVacia(e) ? "true (vacia)" : "false (no vacia)");

    // ---------- Largo ----------
    separador("Largo(e)");
    int largo = Largo(e);
    printf("Resultado: %d\n", largo);

    // ---------- Primero ----------
    separador("Primero(e)");
    Curso primero = Primero(e);
    printf("Resultado: "); mostrarCurso(primero);
    printf("Esperado: numero=103 (c3)\n");

    // ---------- Kesimo ----------
    separador("Kesimo(e, k) para k = 1..Largo(e)");
    for (int k = 1; k <= largo; k++)
    {
        Curso ck = Kesimo(e, k);
        printf("Kesimo(e, %d) = ", k); mostrarCurso(ck);
    }
    printf("Esperado: k=1 -> 103, k=2 -> 102, k=3 -> 101\n");

    // ---------- ExisteEnEscolaridad ----------
    separador("ExisteEnEscolaridad(e, nasig)");
    int buscar1 = 102, buscar2 = 999;
    printf("Se busca numero=%d\n", buscar1);
    printf("Resultado: %s (esperado: true)\n", ExisteEnEscolaridad(e, buscar1) ? "true" : "false");
    printf("Se busca numero=%d\n", buscar2);
    printf("Resultado: %s (esperado: false)\n", ExisteEnEscolaridad(e, buscar2) ? "true" : "false");

    // ---------- Resto (recorrido completo) ----------
    separador("Resto(e, resto) - recorrido de toda la secuencia");
    Escolaridad actual = e;
    int pos = 1;
    while (!EsVacia(actual))
    {
        Curso c = Primero(actual);
        printf("Elemento en posicion %d antes de Resto: ", pos); mostrarCurso(c);
        Escolaridad siguiente;
        Resto(actual, siguiente);
        actual = siguiente;
        pos++;
    }
    printf("Resultado: se recorrieron %d elementos. EsVacia(actual) final = %s\n",
           pos - 1, EsVacia(actual) ? "true" : "false");

    // ---------- InsBack (prueba de riesgo) ----------
    separador("InsBack(e2, c1) sobre secuencia recien creada");
    printf("NOTA: InsBack hace 'e.ult->sig = aux' sin chequear si e.ult es NULL.\n");
    printf("Crear(e2) deja e2.ult = NULL -> se espera fallo (acceso a puntero nulo) en la siguiente linea.\n");
    fflush(stdout);
    Escolaridad e2;
    Crear(e2);
    printf("Se ingresa: "); mostrarCurso(c1);
    fflush(stdout);
    InsBack(e2, c1); // <-- punto esperado de fallo segun analisis del codigo
    printf("Resultado: si esto se imprime, InsBack NO fallo. Largo(e2) = %d\n", Largo(e2));

    printf("\n=================================================\n");
    printf(" FIN DEL TEST DE ESCOLARIDAD\n");
    printf("=================================================\n");
}
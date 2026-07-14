/*
#include "testAlumno.h"



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

// Construye un String (del modulo String) a partir de un literal C,
// sin depender de <string.h>/<cstring>: el largo y la copia se calculan
// "a mano" con new[] e indexado, y luego se usan las primitivas propias
// del modulo String (strCrear/strCop/strDestruir) para el resto.
static void construirString(String &s, const char *texto)
{
    int largo = 0;
    while (texto[largo] != '\0')
        largo++;

    String aux = new char[largo + 1];
    for (int i = 0; i <= largo; i++)
        aux[i] = texto[i];

    strCrear(s);     // deja "s" inicializado (precondicion de strCop)
    strCop(s, aux);  // copia real usando la primitiva del modulo String
    strDestruir(aux);
}

void testAlumno()
{
    printf("=================================================\n");
    printf(" TEST AUTONOMO DEL MODULO ALUMNO\n");
    printf(" (usando los modulos curso, escolaridad y String)\n");
    printf("=================================================\n");

    // ---------- Construccion de un Alumno de prueba ----------
    // NOTA: alumno.h no tiene funcion "cargar/crear alumno", solo getters
    // (Dar*), ExisteEnEscolaridadAlumno e InsertarEscolaridadAlu. Por eso
    // el fixture se arma asignando los campos del struct directamente.
    separador("Construccion del Alumno de prueba");
    Alumno al;
    al.ci = 45678123;
    construirString(al.nombre, "Juan");
    construirString(al.apellido, "Perez");
    construirString(al.telefono, "099123456");
    Crear(al.escolaridad);
    InsBack(al.escolaridad, CargarCurso(201, (Fecha){10, 3, 2023}, 80));
    InsBack(al.escolaridad, CargarCurso(202, (Fecha){15, 7, 2023}, 92));

    printf("Alumno creado: ci=%d, nombre=", al.ci); strPrint(al.nombre);
    printf(", apellido="); strPrint(al.apellido);
    printf(", telefono="); strPrint(al.telefono);
    printf("\nEscolaridad inicial cargada con 2 cursos (numero=201 y numero=202)\n");

    // ---------- DarCi ----------
    separador("DarCi(al)");
    int ci = DarCi(al);
    printf("Resultado: %d (esperado 45678123)\n", ci);

    // ---------- DarNombre ----------
    // NOTA (precondicion no documentada en el header): DarNombre llama
    // internamente a strCop(nom, al.nombre), y strCop hace "delete[] s1"
    // sobre el destino antes de copiar. Por eso "nom" debe llegar ya
    // inicializado (por ejemplo con strCrear) antes de invocar DarNombre;
    // pasar una String sin inicializar produciria comportamiento indefinido.
    separador("DarNombre(al, nom)");
    String nom;
    strCrear(nom);
    printf("nom antes de llamar (recien creado con strCrear): '"); strPrint(nom); printf("'\n");
    DarNombre(al, nom);
    printf("Resultado: "); strPrint(nom); printf(" (esperado: Juan)\n");
    strDestruir(nom);

    // ---------- DarApellido ----------
    separador("DarApellido(al, ape)");
    String ape;
    strCrear(ape);
    DarApellido(al, ape);
    printf("Resultado: "); strPrint(ape); printf(" (esperado: Perez)\n");
    strDestruir(ape);

    // ---------- DarTelefono ----------
    separador("DarTelefono(al, tel)");
    String tel;
    strCrear(tel);
    DarTelefono(al, tel);
    printf("Resultado: "); strPrint(tel); printf(" (esperado: 099123456)\n");
    strDestruir(tel);

    // ---------- DarEscolaridad ----------
    separador("DarEscolaridad(al)");
    Escolaridad esc = DarEscolaridad(al);
    int largoEsc = Largo(esc);
    printf("Largo(DarEscolaridad(al)) = %d (esperado 2)\n", largoEsc);
    for (int k = 1; k <= largoEsc; k++)
    {
        Curso ck = Kesimo(esc, k);
        printf("Kesimo(escolaridad, %d) = ", k); mostrarCurso(ck);
    }

    // ---------- ExisteEnEscolaridadAlumno ----------
    separador("ExisteEnEscolaridadAlumno(al, nasig)");
    int buscar1 = 201, buscar2 = 999;
    printf("Se busca numero=%d\n", buscar1);
    printf("Resultado: %s (esperado: true)\n", ExisteEnEscolaridadAlumno(al, buscar1) ? "true" : "false");
    printf("Se busca numero=%d\n", buscar2);
    printf("Resultado: %s (esperado: false)\n", ExisteEnEscolaridadAlumno(al, buscar2) ? "true" : "false");

    // ---------- InsertarEscolaridadAlu ----------
    separador("InsertarEscolaridadAlu(al, nasig, ffin, calif)");
    int nuevoNasig = 203;
    Fecha nuevaFecha = {1, 12, 2023};
    int nuevaCalif = 88;
    printf("Se ingresa: numero=%d, calificacion=%d, fechaFin=", nuevoNasig, nuevaCalif);
    mostrarFecha(nuevaFecha);
    printf("\n");
    InsertarEscolaridadAlu(al, nuevoNasig, nuevaFecha, nuevaCalif);

    Escolaridad escFinal = DarEscolaridad(al);
    int largoFinal = Largo(escFinal);
    printf("Resultado: Largo(DarEscolaridad(al)) = %d (esperado 3)\n", largoFinal);
    printf("ExisteEnEscolaridadAlumno(al, %d) = %s (esperado: true)\n",
           nuevoNasig, ExisteEnEscolaridadAlumno(al, nuevoNasig) ? "true" : "false");
    Curso ultimo = Kesimo(escFinal, largoFinal);
    printf("Ultimo elemento (Kesimo, %d) tras InsertarEscolaridadAlu = ", largoFinal);
    mostrarCurso(ultimo);
    printf("Esperado: numero=203 en la ultima posicion (InsertarEscolaridadAlu usa InsBack)\n");

    // ---------- limpieza ----------
    strDestruir(al.nombre);
    strDestruir(al.apellido);
    strDestruir(al.telefono);

    printf("\n=================================================\n");
    printf(" FIN DEL TEST DE ALUMNO\n");
    printf("=================================================\n");
}

*/
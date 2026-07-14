/*
#include "testAlumnos.h"

static void separador(const char *titulo)
{
    printf("\n----- %s -----\n", titulo);
    fflush(stdout);
}

// Construye un String (del modulo String) a partir de un literal C,
// sin depender de <string.h>/<cstring>.
static void construirString(String &s, const char *texto)
{
    int largo = 0;
    while (texto[largo] != '\0')
        largo++;

    String aux = new char[largo + 1];
    for (int i = 0; i <= largo; i++)
        aux[i] = texto[i];

    strCrear(s);
    strCop(s, aux);
    strDestruir(aux);
}

// Construye un Alumno de prueba con una escolaridad de un solo curso.
static Alumno construirAlumno(int ci, const char *nombre, const char *apellido,
                               const char *telefono, int nasigCurso)
{
    Alumno al;
    al.ci = ci;
    construirString(al.nombre, nombre);
    construirString(al.apellido, apellido);
    construirString(al.telefono, telefono);
    Crear(al.escolaridad);
    InsBack(al.escolaridad, CargarCurso(nasigCurso, (Fecha){1, 1, 2024}, 75));
    return al;
}

static void mostrarAlumno(Alumno al)
{
    String nom; strCrear(nom);
    String ape; strCrear(ape);
    String tel; strCrear(tel);
    DarNombre(al, nom);
    DarApellido(al, ape);
    DarTelefono(al, tel);
    printf("ci=%d, nombre=", DarCi(al)); strPrint(nom);
    printf(", apellido="); strPrint(ape);
    printf(", telefono="); strPrint(tel);
    printf(", cursos=%d", Largo(DarEscolaridad(al)));
    strDestruir(nom);
    strDestruir(ape);
    strDestruir(tel);
}

void testAlumnos()
{
    printf("=================================================\n");
    printf(" TEST AUTONOMO DEL MODULO ALUMNOS\n");
    printf(" (diccionario con dispersion por CI)\n");
    printf("=================================================\n");

    // ---------- h ----------
    separador("h(ci) - funcion de dispersion (ci % MAX_ALU, MAX_ALU=100)");
    printf("h(5)   = %d\n", h(5));
    printf("h(105) = %d (colisiona con ci=5, misma cubeta)\n", h(105));
    printf("h(20)  = %d\n", h(20));
    printf("h(120) = %d (colisiona con ci=20, misma cubeta)\n", h(120));
    printf("h(42)  = %d (cubeta propia, sin colision)\n", h(42));

    // ---------- Make ----------
    separador("Make(as)");
    Alumnos as;
    Make(as);
    printf("Resultado: diccionario creado (todas las cubetas en NULL)\n");

    // ---------- Member sobre diccionario vacio ----------
    separador("Member(as, 5) - diccionario vacio");
    printf("Resultado: %s (esperado: false)\n", Member(as, 5) ? "true" : "false");

    // ---------- Construccion de alumnos de prueba ----------
    separador("Construccion de Alumnos de prueba");
    Alumno alA = construirAlumno(5,   "Ana",   "Diaz",  "091111111", 301);
    Alumno alB = construirAlumno(105, "Luis",  "Gomez", "092222222", 302); // colisiona con alA
    Alumno alC = construirAlumno(20,  "Marta", "Ruiz",  "093333333", 303);
    Alumno alD = construirAlumno(120, "Pedro", "Lopez", "094444444", 304); // colisiona con alC
    Alumno alE = construirAlumno(42,  "Sofia", "Perez", "095555555", 305); // sin colision
    printf("alA: "); mostrarAlumno(alA); printf("\n");
    printf("alB: "); mostrarAlumno(alB); printf("\n");
    printf("alC: "); mostrarAlumno(alC); printf("\n");
    printf("alD: "); mostrarAlumno(alD); printf("\n");
    printf("alE: "); mostrarAlumno(alE); printf("\n");

    // ---------- Insert ----------
    separador("Insert(as, al) x5");
    Insert(as, alA);
    printf("Insertado ci=5.   Member(as,5)   = %s\n", Member(as, 5) ? "true" : "false");
    Insert(as, alB);
    printf("Insertado ci=105. Member(as,105) = %s, Member(as,5) sigue = %s\n",
           Member(as, 105) ? "true" : "false", Member(as, 5) ? "true" : "false");
    Insert(as, alC);
    printf("Insertado ci=20.  Member(as,20)  = %s\n", Member(as, 20) ? "true" : "false");
    Insert(as, alD);
    printf("Insertado ci=120. Member(as,120) = %s, Member(as,20) sigue = %s\n",
           Member(as, 120) ? "true" : "false", Member(as, 20) ? "true" : "false");
    Insert(as, alE);
    printf("Insertado ci=42.  Member(as,42)  = %s\n", Member(as, 42) ? "true" : "false");

    // ---------- Member ----------
    separador("Member(as, ci) - existentes y no existentes");
    int existentes[] = {5, 105, 20, 120, 42};
    for (int i = 0; i < 5; i++)
        printf("Member(as, %d) = %s (esperado: true)\n", existentes[i], Member(as, existentes[i]) ? "true" : "false");
    printf("Member(as, 7) = %s (esperado: false, nunca se inserto)\n", Member(as, 7) ? "true" : "false");

    // ---------- Find ----------
    separador("Find(as, ci)");
    for (int i = 0; i < 5; i++)
    {
        Alumno encontrado = Find(as, existentes[i]);
        printf("Find(as, %d) = ", existentes[i]); mostrarAlumno(encontrado); printf("\n");
    }

    // ---------- Modify ----------
    separador("Modify(as, al) - reemplazar datos del alumno ci=20");
    Alumno alCNuevo = construirAlumno(20, "Marta", "Ruiz", "099000000", 306);
    printf("Se ingresa: "); mostrarAlumno(alCNuevo); printf("\n");
    Modify(as, alCNuevo);
    Alumno verifModify = Find(as, 20);
    printf("Resultado tras Modify, Find(as,20) = "); mostrarAlumno(verifModify); printf("\n");
    printf("Esperado: mismo ci=20, telefono=099000000, cursos=1 (nasig=306)\n");

    // ---------- Delete: caso normal, cubeta sin colision ----------
    separador("Delete(as, 42) - cubeta sin colision");
    Delete(as, 42);
    printf("Resultado: Member(as,42) = %s (esperado: false)\n", Member(as, 42) ? "true" : "false");

    // ---------- Delete: cabeza de una cubeta con colision ----------
    separador("Delete(as, 105) - CABEZA de cubeta con colision (cubeta 5: 105 -> 5)");
    printf("NOTA: segun el codigo, cuando el nodo a borrar es la cabeza de la cubeta,\n");
    printf("Delete hace 'as[cubeta] = NULL' en vez de 'as[cubeta] = aux->sig'.\n");
    printf("Si hay otro elemento detras en la misma cubeta (aqui, ci=5), se esperaria\n");
    printf("que sobreviva, pero es probable que tambien se pierda por ese motivo.\n");
    fflush(stdout);
    Delete(as, 105);
    printf("Resultado: Member(as,105) = %s (esperado: false, se borro)\n", Member(as, 105) ? "true" : "false");
    printf("Resultado: Member(as,5)   = %s (esperado: true, nunca se borro)\n", Member(as, 5) ? "true" : "false");

    // ---------- Delete: cola de una cubeta con colision ----------
    separador("Delete(as, 20) - COLA de cubeta con colision (cubeta 20: 120 -> 20)");
    Delete(as, 20);
    printf("Resultado: Member(as,20)  = %s (esperado: false, se borro)\n", Member(as, 20) ? "true" : "false");
    printf("Resultado: Member(as,120) = %s (esperado: true, nunca se borro)\n", Member(as, 120) ? "true" : "false");

    // ---------- Prueba de riesgo: precondicion violada ----------
    separador("Find(as, 555) - clave inexistente (viola la precondicion)");
    printf("NOTA: el header indica 'Precondicion: el elemento es miembro del diccionario'.\n");
    printf("Como Find no valida esto, con una clave ausente (cubeta vacia) se espera un\n");
    printf("fallo por acceso a puntero nulo (aux == NULL al hacer aux->info).\n");
    fflush(stdout);
    Find(as, 555);
    printf("Resultado: si esto se imprime, no fallo.\n");

    printf("\n=================================================\n");
    printf(" FIN DEL TEST DE ALUMNOS\n");
    printf("=================================================\n");
}
    */
#include "escolaridad.h"


// Crea una secuencia vacía.  
void CrearEscolaridad(Escolaridad &e)
{
    e.prim = NULL;
    e.ult = NULL;
}

// Secuencia  Agrega un elemento al principio de la secuencia. 
void InsFrontEscolaridad(Escolaridad &e, Curso c)
{
    nodoCurso *aux = new nodoCurso;
    aux->info = c;
    aux->sig = e.prim;
    if(e.prim == NULL)
        e.ult = aux;
    e.prim = aux;

}

// Secuencia  Agrega un elemento al final de la secuencia. 
void InsBackEscolaridad(Escolaridad &e, Curso c)
{
    nodoCurso *aux = new nodoCurso;
    aux->info = c;
    aux->sig = NULL;
    if(e.ult == NULL)
        e.prim = aux;
    else 
        e.ult->sig = aux;
    e.ult = aux;
}

// Boolean Determina si la secuencia está vacía o no. 
bool EsVaciaEscolaridad(Escolaridad e)
{
    bool vacio = false;
    if(e.prim == NULL)
        vacio = true;
    return vacio;
}


// Devuelve el primer elemento de la secuencia. 
// Precondición: la secuencia no es vacía. 
Curso PrimeroEscolaridad(Escolaridad e)
{
    return e.prim->info;
}

// Devuelve la secuencia sin su primer elemento. 
// Precondición: la secuencia no es vacía 
void RestoEscolaridad(Escolaridad inicial, Escolaridad &final)
{
    final.prim = inicial.prim->sig;
    final.ult = inicial.ult;
}

// Devuelve la cantidad de elementos de la secuencia.
int LargoEscolaridad(Escolaridad e)
{
    int i=0;
    nodoCurso *aux = new nodoCurso;
    aux = e.prim;
    while(aux != NULL)
    {
        aux = aux->sig;
        i++;
    }
    return i;
}

// Devuelve el numero de cursos aprobados
int CursosAprobadosEscolaridad(Escolaridad e){
    int i=0;
    nodoCurso *aux = new nodoCurso;
    aux = e.prim;
    while(aux != NULL)
    {
        Curso c = aux->info;
        if(CursoAprobado(c) == true)
            i++;
        aux = aux->sig;
    }
    return i;
}

// Devuelve el elemento que ocupa la posición K de la secuencia.
// Precondición: El largo de la secuencia es mayor o igual a K. 
Curso KesimoEscolaridad(Escolaridad e, int k)
{
    int i;
    nodoCurso *aux = new nodoCurso;
    aux = e.prim;
    for(i=1; i<k; i++)
    {
        aux = aux->sig;
    }
    return aux->info;
}

//determina el elemento existe en la secuencia.
bool ExisteEnEscolaridad(Escolaridad e, int nasig)
{
    bool existe = false;
    nodoCurso *aux = new nodoCurso;
    aux = e.prim;
    while(aux != NULL && !existe)
    {
        if(aux->info.numero == nasig)
            existe = true;
        else
            aux = aux->sig;
    }
    return existe;
}

Curso DarUltimoEscolaridad(Escolaridad e)
{
    return e.ult->info;
}
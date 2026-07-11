#include "escolaridad.h"


// Crea una secuencia vacía.  
void Crear(Escolaridad &e)
{
    e.prim = NULL;
    e.ult = NULL;
}

// Secuencia  Agrega un elemento al principio de la secuencia. 
void InsFront(Escolaridad &e, Curso c)
{
    nodoCurso *aux = new nodoCurso;
    aux->info = c;
    aux->sig = e.prim;
    e.prim = aux;

}

// Secuencia  Agrega un elemento al final de la secuencia. 
void InsBack(Escolaridad &e, Curso c)
{
    nodoCurso *aux = new nodoCurso;
    aux->info = c;
    aux->sig = NULL;
    e.ult->sig = aux;
    e.ult = aux;
}

// Boolean Determina si la secuencia está vacía o no. 
bool EsVacia(Escolaridad e)
{
    bool vacio = false;
    if(e.prim == NULL)
        vacio = true;
    return vacio;
}


// Devuelve el primer elemento de la secuencia. 
// Precondición: la secuencia no es vacía. 
Curso Primero(Escolaridad e)
{
    return e.prim->info;
}

// Devuelve la secuencia sin su primer elemento. 
// Precondición: la secuencia no es vacía 
void Resto(Escolaridad inicial, Escolaridad &final)
{
    final.prim = inicial.prim->sig;
    final.ult = inicial.ult;
}

// Devuelve la cantidad de elementos de la secuencia.
int Largo(Escolaridad e)
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

// Devuelve el elemento que ocupa la posición K de la secuencia.
// Precondición: El largo de la secuencia es mayor o igual a K. 
Curso Kesimo(Escolaridad e, int k)
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
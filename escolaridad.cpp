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

}

// Boolean Determina si la secuencia está vacía o no. 
bool EsVacia(Escolaridad e)
{

}


// Devuelve el primer elemento de la secuencia. 
// Precondición: la secuencia no es vacía. 
Curso Primero(Escolaridad e)
{

}

// Devuelve la secuencia sin su primer elemento. 
// Precondición: la secuencia no es vacía 
void Resto(Escolaridad inicial, Escolaridad &final)
{

}

// Devuelve la cantidad de elementos de la secuencia.
int Largo(Escolaridad e)
{

}

// Devuelve el elemento que ocupa la posición K de la secuencia.
// Precondición: El largo de la secuencia es mayor o igual a K. 
Curso Kesimo(Escolaridad e, int k)
{

}

//determina el elemento existe en la secuencia.
bool ExisteEnEscolaridad(Escolaridad e, int nasig)
{

}
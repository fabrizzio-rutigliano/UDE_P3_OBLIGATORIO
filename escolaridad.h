#ifndef ESCOLARIDAD_H_INCLUDED
#define ESCOLARIDAD_H_INCLUDED

#include "curso.h"

typedef struct nodoCurso {
            	            Curso info;
            	            nodoCurso * sig;
                        } nodoCurso;

typedef struct {
                nodoCurso * prim;
                nodoCurso * ult;
                } Escolaridad;


// Teorico 6 TAD, las primitivas por alguna razon estan en español en el teorico.

// Crea una secuencia vacía.  
void CrearEscolaridad(Escolaridad &e);

// Secuencia  Agrega un elemento al principio de la secuencia. 
void InsFrontEscolaridad(Escolaridad &e, Curso c);

// Secuencia  Agrega un elemento al final de la secuencia. 
void InsBackEscolaridad(Escolaridad &e, Curso c);

// Boolean Determina si la secuencia está vacía o no. 
bool EsVaciaEscolaridad(Escolaridad e); 

// Devuelve el primer elemento de la secuencia. 
// Precondición: la secuencia no es vacía. 
Curso PrimeroEscolaridad(Escolaridad e);

// Devuelve la secuencia sin su primer elemento. 
// Precondición: la secuencia no es vacía 
void RestoEscolaridad(Escolaridad inicial, Escolaridad &final);

// Devuelve la cantidad de elementos de la secuencia.
int LargoEscolaridad(Escolaridad e);

// Devuelve el numero de cursos aprobados
int CursosAprobadosEscolaridad(Escolaridad e);

// Devuelve el elemento que ocupa la posición K de la secuencia.
// Precondición: El largo de la secuencia es mayor o igual a K. 
Curso Kesimo(Escolaridad e, int k);

//determina el elemento existe en la secuencia.
bool ExisteEnEscolaridad(Escolaridad e, int nasig);

Curso DarUltimoEscolaridad(Escolaridad e);

void DesplegarEscolaridad(Escolaridad e);


#endif// ESCOLARIDAD_H_INCLUDED
#include "curso.h"

typedef struct nodoCurso {
            	            Curso info;
            	            nodoCurso * sig;
                        };

typedef struct {
                nodoCurso * prim;
                nodoCurso * ult;
                } Escolaridad;


// Teorico 6 TAD, las primitivas por alguna razon estan en español en el teorico.

// Crea una secuencia vacía.  
void Crear(Escolaridad &e);

// Secuencia  Agrega un elemento de tipo T a la secuencia. 
void InsFront(Escolaridad &e, Curso c);

// Boolean Determina si la secuencia está vacía o no. 
bool EsVacia(Escolaridad e); 

// Devuelve el primer elemento de la secuencia. 
// Precondición: la secuencia no es vacía. 
Curso Primero(Escolaridad e);

// Devuelve la secuencia sin su primer elemento. 
// Precondición: la secuencia no es vacía 
void Resto(Escolaridad inicial, Escolaridad &final);

// Devuelve la cantidad de elementos de la secuencia.
int Largo(Escolaridad e);

// Devuelve el elemento que ocupa la posición K de la secuencia.
// Precondición: El largo de la secuencia es mayor o igual a K. 
Curso Kesimo(Escolaridad e, int k);

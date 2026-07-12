#ifndef ASIGNATURAS_H_INCLUDED
#define ASIGNATURAS_H_INCLUDED

#include "constantes.h"
#include "asignatura.h"

typedef struct Asignaturas {         
        Asignatura arre[MAX_ASIG];
        int tope;
   } Asignaturas;

//Crea una Curricula vacia
void Crear(Asignaturas &asigns);

//Agrega una asignatura a la Curricula
void InsBack(Asignatura asig, Asignaturas &asigns);

//devuelve si es vacia la curricula
bool esVacia(Asignaturas asigns);

//libera memoria de todas las asignaturas
void destruirAsignaturas(Asignaturas &asigns);

//agrega nueva asignatura despues de hacer los controles necesarios
void AgregarAsignaturaEnAsignaturas(Asignaturas &asigns);

#endif// ASIGNATURAS_H_INCLUDED
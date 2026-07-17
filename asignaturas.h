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

//lista todas las asignaturas
void listarAsignaturas(Asignaturas asings);

// Retornar el tope de asignatura
int TopeActualAsignaturas(Asignaturas asigns);

// Retorna si la asignatura existe
bool ExisteAsignatura(Asignaturas asigns, int asig);

Asignatura DarAsignatura(Asignaturas asigns, int num);

#endif// ASIGNATURAS_H_INCLUDED

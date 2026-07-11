#ifndef ASIGNATURA_H_INCLUDED
#define ASIGNATURA_H_INCLUDED

#include "String.h"

typedef struct Asignatura {
                int numero;
                String nombre;
                int cantidadHoras;
                bool optativa;
} Asignatura;

//devuelve el numero de la Asignatura
int DarNumero(Asignatura asig);

//devuelve el nombre de la Asignatura
String DarNombre(Asignatura asig);

//devuelve el cantidadHoras de la Asignatura
int DarCantidadHoras(Asignatura asig);

//devuelve si es optativa o no la Asignatura
bool DarOptativa (Asignatura asig);

#endif// ASIGNATURA_H_INCLUDED
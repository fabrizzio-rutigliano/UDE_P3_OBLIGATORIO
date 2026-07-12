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
void DarNombre(Asignatura asig, String &strNom);

//devuelve el cantidadHoras de la Asignatura
int DarCantidadHoras(Asignatura asig);

//devuelve si es optativa o no la Asignatura
bool DarOptativa (Asignatura asig);

//Carga una asignatura
Asignatura cargarAsignatura(int numero, String nombre, int cantidadHoras, bool optativa);

#endif// ASIGNATURA_H_INCLUDED
#ifndef ASIGNATURA_H_INCLUDED
#define ASIGNATURA_H_INCLUDED

#include "String.h"

typedef struct Asignatura {
                String nombre;
                int cantidadHoras;
                bool optativa;
} Asignatura;

//devuelve el nombre de la Asignatura
void DarNombre(Asignatura asig, String &strNom);

//devuelve el cantidadHoras de la Asignatura
int DarCantidadHoras(Asignatura asig);

//devuelve si es optativa o no la Asignatura
bool DarOptativa (Asignatura asig);

//Carga una asignatura
Asignatura cargarAsignatura(String nombre, int cantidadHoras, bool optativa);

//Ingresa una asignatura desde teclado
void IngresarAsignatura(Asignatura &a);

// Libera la memoria utilizada por una Asignatura
void destruirAsignatura(Asignatura &asig);

#endif// ASIGNATURA_H_INCLUDED
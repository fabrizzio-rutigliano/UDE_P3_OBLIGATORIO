#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "alumnos.h"
#include "curricula.h"

//Muestra el menu principal
void desplegarMenuPrincipal(int &opcion);

void IngresarPreviatura(int prev, int requiere);

void AsignaturaInvalida(int asig);

void ErrorGeneraCiclo();

void IngresarNroAsignatura(int asig);

void ErrorExisteAlumno();

void ErrorCursoYaExiste();

void ErrorFechaCursoAnteriorAlUltimo();

void ErrorNoExisteAlumno();

#endif// MENU_H_INCLUDED
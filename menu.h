#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "alumnos.h"
#include "curricula.h"

//Muestra el menu principal
void desplegarMenuPrincipal(int &opcion);

void IngresarPreviatura(Asignaturas asigns, int &prev, int &requiere);

void AsignaturaInvalida(Asignaturas asigns, int &asig);

void IngresarNroAsignatura(int &nroAsig)

void ErrorGeneraCiclo();

void IngresarNroAsignatura(Asignaturas asigns, int &asig);

void ErrorExisteAlumno();

void ErrorCursoYaExiste();

void ErrorFechaCursoAnteriorAlUltimo();

void ErrorNoExisteAlumno();

void ErrorEscolaridadVacia();

void ErrorAsignaturasMaximas();

#endif// MENU_H_INCLUDED
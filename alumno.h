#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include "escolaridad.h"

typedef struct Alumno {
                	int ci;
                	String nombre;
                	String apellido;
                	String telefono;
                	Escolaridad escolaridad;
} Alumno;


//devuelve la CI de un alumno
int DarCi(Alumno al);

//devuelve el nombre de un Alumno
void DarNombre(Alumno al, String &nom);

//devuelve el apellido de un Alumno
void DarApellido(Alumno al, String &ape);

//devuelve el telefono de un Alumno
void DarTelefono(Alumno al, String &tel);

//devuelve la escolaridad de un alumno
Escolaridad DarEscolaridad(Alumno al);


//verifica si la asignatura existe en la escolaridad del alumno
bool ExisteEnEscolaridadAlumno(Alumno al, int nasig);


//insertar registro nuevo en escolaridad de alumno
void InsertarEscolaridadAlu(Alumno &al, int nasig, Fecha ffin, int calif);

#endif// ALUMNO_H_INCLUDED
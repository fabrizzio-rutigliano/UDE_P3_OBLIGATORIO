#ifndef CURSO_H_INCLUDED
#define CURSO_H_INCLUDED

#include "String.h"
#include "Fecha.h"

typedef struct Curso {
                        int numero;
            	        Fecha fechaFin; 
                        int calificacion;
                    } Curso;

int DevolverNumero(Curso c);

Fecha DevolverFechaFin(Curso c);

int DevolverCalificacion(Curso c);

void DesplegarNumero(Curso c);

void DesplegarFechaFin(Curso c);

void DesplegarCalificacion(Curso c);

Curso CargarCurso(int nro, Fecha ffin, int cal); 

void IngresarCurso(Curso &c); 

#endif// CURSO_H_INCLUDED
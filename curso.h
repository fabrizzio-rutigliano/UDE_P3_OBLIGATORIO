#include "String.h"
#include "Fecha.h"

typedef struct Curso {
                        int numero;
                        String nombreAsignatura;
            	        Fecha fechaFin; 
                        int calificacion;
                    };

int DevolverNumero(Curso c);

void DevolverNombreAsignatura(Curso c);

Fecha DevolverFechaFin(Curso c);

int DevolverCalificacion(Curso c);

void DesplegarNumero(Curso c);

void DesplegarNombreAsignatura(Curso c);

void DesplegarFechaFin(Curso c);

void DesplegarCalificacion(Curso c);

Curso CargarCurso(int nro, String nom, Fecha ffin, int cal); 

void IngresarCurso(Curso &c); // Usamos esto como auxiliar para pasarlo dentro de cargar curso.
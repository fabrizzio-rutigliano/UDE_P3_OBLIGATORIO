#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <stdio.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

//===================================================================================================================

// Cargar fecha por teclado
void cargarFecha(Fecha &fecha);

// Mostrar por pantalla la fecha ingresada
void mostrarFecha(Fecha fecha);

// Funciones que retornan el atributo especificado de la fecha
int darDia(Fecha fecha);
int darMes(Fecha fecha);
int darAnio(Fecha fecha);

// Retorna verdadero si la fecha es v�lida (d�a, mes y a�o coherentes, incluyendo a�os bisiestos)
bool esValidaFecha(Fecha fecha);

// Retorna verdadero si a > b
// Pre: ambas fechas son v�lidas.
bool esMayorFechas(Fecha a, Fecha b);

// Retorna verdadero si ambas fechas representan el mismo d�a, mes y a�o
// Pre: ambas fechas son v�lidas.
bool sonIgualesFechas(Fecha a, Fecha b);

// Copia una fecha en otra fecha
void copFecha(Fecha &fec1, Fecha fec2);

#endif // FECHA_H_INCLUDED

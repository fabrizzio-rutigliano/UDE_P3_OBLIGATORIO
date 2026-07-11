#ifndef CURRICULA_H_INCLUDED
#define CURRICULA_H_INCLUDED

#include "asignaturas.h"
#include "constantes.h"

typedef int MatrizPreviaturas[MAX_ASIG][MAX_ASIG];

// Crea un grafo vacío (Inicializa toda la matriz de adyacencia en 0).
void Crear(MatrizPreviaturas &matriz);

// Determina si en el grafo existe la arista especificada.
bool PerteneceArista(MatrizPreviaturas matriz, int previa, int requiere);

// Inserta la nueva arista al grafo.
// Precondición: la arista no pertenece al grafo. 
void InsertarArista(MatrizPreviaturas &matriz, int previa, int requiere);

// Determina si en el grafo existe el vertice especificado.
bool PerteneceVertice(MatrizPreviaturas matriz, int previa, int requiere);

// Devuelve el grado del vértice especificado.
// Precondición: el vértice pertenece al grafo.
int GradoVertice (MatrizPreviaturas matriz, int vertice, int topeActual);

// ==========================================
// Operaciones especificas
// ==========================================

// Requerimiento 2: Determina si agregar la arista formaría un ciclo cerrado
bool GeneraCiclo(MatrizPreviaturas matriz, int previa, int requiere, int topeActual);

// Requerimiento 6: Lista por pantalla los números de todas las materias previas 
//(directas e indirectas) de un vértice dado.
void ListarTodasLasPrevias(MatrizPreviaturas matriz, int numAsig, int topeActual);

#endif// CURRICULA_H_INCLUDED
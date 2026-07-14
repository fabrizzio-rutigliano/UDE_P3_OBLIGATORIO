#ifndef CURRICULA_H_INCLUDED
#define CURRICULA_H_INCLUDED

#include "asignaturas.h"
#include "constantes.h"

typedef int Curricula[MAX_ASIG][MAX_ASIG];

// Crea un grafo vacío (Inicializa toda la matriz de adyacencia en 0).
void Crear(Curricula &matriz);

// Determina si en el grafo existe la arista especificada.
bool PerteneceArista(Curricula matriz, int previa, int requiere);

// Inserta la nueva arista al grafo.
// Precondición: la arista no pertenece al grafo. 
void InsertarArista(Curricula &matriz, int previa, int requiere);

// Determina si en el grafo existe el vertice especificado.
bool PerteneceVertice(Curricula matriz, int previa, int topeActual);

// ==========================================
// Operaciones especificas
// ==========================================

// Requerimiento 2: Determina si agregar la arista formaría un ciclo cerrado
void DFS_BuscarCamino(Curricula matriz, int actual, int destino, bool visitado[], int topeActual);
bool GeneraCiclo(Curricula matriz, int previa, int requiere, int topeActual);

// Requerimiento 6: Lista por pantalla los números de todas las materias previas 
//(directas e indirectas) de un vértice dado.
void DFS_BuscarPrevias(Curricula matriz, int actual, bool visitado[], int topeActual, int resultado[], int &topeResultado);
void ListarTodasLasPrevias(Curricula matriz, int numAsig, int topeActual, int resultado[], int &topeResultado);

#endif// CURRICULA_H_INCLUDED
#include "curricula.h"
#include "constantes.h"

// Crea un grafo vacío (Inicializa toda la matriz de adyacencia en 0).
void Crear(MatrizPreviaturas &matriz){
    for(int i = 0; i < MAX_ASIG; i++){
        for(int j = 0; j < MAX_ASIG; j++){
            matriz[i][j] = 0;
        }
    }
}

// Determina si en el grafo existe la arista especificada. 
// *(La materia previa es la fila y la asignatura a cursar es la columna.)
bool PerteneceArista(MatrizPreviaturas matriz, int previa, int asignatura){

    if (matriz[previa][asignatura] == 1) {
        return true;
    } else {
        return false;
    }
}

// Inserta la nueva arista al grafo.
// Precondición: la arista no pertenece al grafo. 
void InsertarArista(MatrizPreviaturas &matriz, int previa, int asignatura){

    matriz[previa][asignatura] = 1;
}

// Determina si en el grafo existe el vertice especificado.
// *A discutir* se valida usando el tope del ACT de asignaturas.
bool PerteneceVertice(MatrizPreviaturas matriz, int asignatura, int topeActual){
    if((asignatura >= 0) && (asignatura < topeActual)){
        return true;
    } else {
        return false;
    }
}

// ==========================================
// Operaciones especificas
// ==========================================


// Requerimiento 2: Determina si agregar la arista formaría un ciclo cerrado
// Antes de insertar la arista, lanzamos una DFS empezando desde el vértice asignatura. 
// Si mediante esa búsqueda logramos visitar el vértice de la previa, significa que agregar la conexión formaría un ciclo.

void DFS_BuscarCamino(MatrizPreviaturas matriz, int actual, int destino, bool visitado[], int topeActual) {
    // Marcamos el vértice actual como visitado
    visitado[actual] = true;
    
    int j = 0;
    // Recorremos los adyacentes mientras no nos pasemos del tope 
    // y MIENTRAS no hayamos encontrado el destino
    while (j < topeActual && !visitado[destino]) {
        
        // Si hay flecha desde actual hacia j (es adyacente)
        if (matriz[actual][j] == 1) {
            // Si 'j' no fue visitado, aplicamos recursividad desde él
            if (!visitado[j]) {
                DFS_BuscarCamino(matriz, j, destino, visitado, topeActual);
            }
        }
        j++;
    }
}

bool GeneraCiclo(MatrizPreviaturas matriz, int previa, int asignatura, int topeActual) {
    
    // Inicializamos el arreglo de visitados en false
    bool visitado[MAX_ASIG];
    for (int i = 0; i < topeActual; i++) {
        visitado[i] = false;
    }
    
    // DFS saliendo desde asignatura buscando a previa
    DFS_BuscarCamino(matriz, asignatura, previa, visitado, topeActual);
    
    // Si el DFS logró marcar la previa como visitada, entonces SÍ genera ciclo
    return visitado[previa];
}


// Requerimiento 6: Lista por pantalla los números y nombres de todas las materias previas.
// (directas e indirectas) de un vértice dado.
// En este modulo solo podemos listar numeros de materias, por lo tanto le tenemos que pasar
// un arreglo de numeros de materia para que se procese utilizando asignaturas para acceder a los nombres.

void DFS_BuscarPrevias(MatrizPreviaturas matriz, int actual, bool visitado[], int topeActual, int resultado[], int &topeResultado) {
    // Marcamos el vértice actual como visitado para no procesarlo dos veces
    visitado[actual] = true;
    
    // Iteramos sobre la columna de actual para buscar sus previas
    for (int i = 0; i < topeActual; i++) {
        
        // Si hay 1, significa que la asignatura i apunta hacia actual (es previa)
        if (matriz[i][actual] == 1) {
            
            // Recursividad: Si esta previa no fue visitada en otro camino
            if (!visitado[i]) {
                 // Guardamos el número en el arreglo
                resultado[topeResultado] = i;
                topeResultado++; 
                
                // Saltamos hacia i para buscar las previas de la previa (previas indirectas)
                DFS_BuscarPrevias(matriz, i, visitado, topeActual, resultado, topeResultado);
            }
        }
    }
}

void ObtenerPrevias(MatrizPreviaturas matriz, int numAsig, int topeActual, int resultado[], int &topeResultado) {
    
    // Inicializamos el arreglo de visitados en false
    bool visitado[MAX_ASIG];
    for (int i = 0; i < topeActual; i++) {
        visitado[i] = false;
    }
    
    // Inicializamos la cantidad de resultados en 0
    topeResultado = 0;
    
    // Lanzamos el DFS
    DFS_BuscarPrevias(matriz, numAsig, visitado, topeActual, resultado, topeResultado);
}
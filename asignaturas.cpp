#include "asignaturas.h"

//Crea una Curricula vacia
void Crear(Asignaturas &asigns){
    asigns.tope = 0;
}

//Agrega una asignatura a la Curricula
void InsBack(Asignatura asig, Asignaturas &asigns){
    if(asigns.tope < MAX_ASIG){
        asigns.arre[asigns.tope] = asig;
        asigns.tope++;
    }
}

//devuelve si es vacia la curricula
bool esVacia(Asignaturas asigns){
    bool vacia = false;
    if(asigns.tope == 0)
        vacia = true;
    return vacia;
}

//libera memoria de todas las asignaturas
void destruirAsignaturas(Asignaturas &asigns){
    for (int i = 0; i < asigns.tope; i++){
        destruirAsignatura(asigns.arre[i]);
    }

    asigns.tope = 0;
}
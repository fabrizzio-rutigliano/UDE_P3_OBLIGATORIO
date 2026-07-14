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

//lista todas las asignaturas
void listarAsignaturas(Asignaturas asings){
    int i;
    for(i = 0; i<asings.tope; i++){
        DesplegarAsignatura(asings.arre[i]);
    }
}

//agrega nueva asignatura despues de hacer los controles necesarios
void AgregarAsignaturaEnAsignaturas(Asignaturas &asigns){
    if(asigns.tope < 30)
    {
        int num = asigns.tope;
        asigns.tope++;
        IngresarAsignatura(asigns.arre[num], num);
    }
    else
        printf("\nError"); //desplegar mensaje de error
}

// Retornar el tope de asignatura
int TopeActualAsignaturas(Asignaturas asigns){
    return asigns.tope;
}

// Retorna si la asignatura existe 
bool ExisteAsignatura(Asignaturas asigns, int asig){
    if (asig < asigns.tope)
        return true;
    else 
        return false;
};
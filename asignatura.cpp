#include "asignatura.h"

//devuelve el numero de la Asignatura
int DarNumero(Asignatura asig){
    int num;
    num = asig.numero;

    return num;
}

//devuelve el nombre de la Asignatura
void DarNombre(Asignatura asig, String &strNom){
    strCop(strNom, asig.nombre);
}

//devuelve el cantidadHoras de la Asignatura
int DarCantidadHoras(Asignatura asig){
    int cantHoras;
    cantHoras = asig.cantidadHoras;

    return cantHoras;
}

//devuelve si es optativa o no la Asignatura
bool DarOptativa (Asignatura asig){
    bool opt;
    opt = asig.optativa;

    return opt;
}

//Carga una asignatura
Asignatura cargarAsignatura(int numero, String nombre, int cantidadHoras, bool optativa){
    Asignatura asig;

    asig.numero = numero;
    asig.nombre = nombre;
    asig.cantidadHoras = cantidadHoras;
    asig.optativa = optativa;

    return asig;
}
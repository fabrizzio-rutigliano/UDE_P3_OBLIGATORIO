#include "asignatura.h"

//devuelve el numero de la Asignatura
int DarNumero(Asignatura asig){
    int num;
    num = asig.numero;

    return num;
}

//devuelve el nombre de la Asignatura
String DarNombre(Asignatura asig){
    String nom;
    nom = asig.nombre;

    return nom;
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
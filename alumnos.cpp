#include "alumnos.h"


//funcion auxiliar para dispersion
int h(int ci)
{
    return ci % MAX_ALU;
}


//Crea un diccionario vacío.
void Make(Alumnos &als)
{
    int i;
    for(i=0; i<100; i++)
    {
        als[i] = NULL;
    }
}



//Determina si en el diccionario existe un elemento con la clave especificada.
bool Member(Alumnos als, int ci)
{
    int cubeta = h(ci);
    nodoAlumno *aux = als[cubeta];
    bool esta = false;
    while (aux != NULL && !esta)
    {
        if (DarCi(aux->info) == ci)
            esta = true;
        else
            aux = aux->sig;
    }
    return esta;
}



//Precondición: el elemento a insertar no es miembro del diccionario.
//Inserta un elemento en el diccionario.
void Insert(Alumnos &as, Alumno al)
{
    int cubeta = h(DarCi(al));
    nodoAlumno *nuevo = new nodoAlumno;
    nuevo->info = al;
    nuevo->sig = as[cubeta];
    as[cubeta] = nuevo;
}



//Dada la clave de un elemento devuelve el elemento con dicha clave
//Precondición: el elemento es miembro del diccionario.
Alumno Find(Alumnos as, int ci)
{
    int cubeta = h(ci);
    nodoAlumno *aux = as[cubeta];
    bool esta = false;
    Alumno al;
    while(!esta)
    {
        if(DarCi(aux->info) == ci)
        {
            esta = true;
            al = aux->info;
        }
        else
            aux = aux->sig;
    }
    return al;
}



//Sustituye el viejo elemento de tipo T en el diccionario por el nuevo elemento.
//Precondición: el elemento a sustituir es miembro del diccionario.
void Modify(Alumnos &as, Alumno al)
{
    int ci = DarCi(al);
    int cubeta = h(ci);
    nodoAlumno *aux = as[cubeta];
    while (DarCi(aux->info) != ci)
    {
        aux = aux->sig;
    }
    aux->info = al;
}



//Dada la clave de un elemento lo borra del diccionario
//Precondición: el elemento es miembro del diccionario.
void Delete(Alumnos &as, int ci)
{
    int cubeta = h(ci);
    nodoAlumno *aux = as[cubeta];
    nodoAlumno *ant = NULL;
    while (DarCi(aux->info) != ci)
    {
        ant = aux;
        aux = aux->sig;
    }
    if(ant == NULL)
        as[cubeta] = aux->sig;
    else
        ant->sig = aux->sig;
    delete(aux);
}

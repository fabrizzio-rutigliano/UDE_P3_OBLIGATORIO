#include "constantes.h"
#include "alumno.h"


typedef struct nodoAlumno {
                            			Alumno info;
                            			nodoAlumno * sig;
};

typedef nodoAlumno * ListaAlumnos;

typedef ListaAlumnos Alumnos[B];



//Crea un diccionario vacío.
void Make();



//Determina si en el diccionario existe un elemento con la clave especificada.
bool Member();



//Precondición: el elemento a insertar no es miembro del diccionario.
//Inserta un elemento en el diccionario.
void Insert(%Alumnos as, Alumno al);



//Dada la clave de un elemento devuelve el elemento con dicha clave
//Precondición: el elemento es miembro del diccionario.
Alumno Find(Alumnos as, int ci);



//Sustituye el viejo elemento de tipo T en el diccionario por el nuevo elemento.
//Precondición: el elemento a sustituir es miembro del diccionario.
void Modify(Alumnos &as, Alumno al) : Diccionario x T  Diccionario



//Dada la clave de un elemento lo borra del diccionario
//Precondición: el elemento es miembro del diccionario.
void Delete(Alumnos &as, int ci);

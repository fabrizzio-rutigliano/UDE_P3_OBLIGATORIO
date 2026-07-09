#include "escolaridad.h"

typedef struct Alumno {
                	int ci;
                	String nombre;
                	String apellido;
                	String telefono;
                	Escolaridad escolaridad;
};


//devuelve la CI de un alumno
int DarCi(Alumno al);

//devuelve el nombre de un Alumno
String DarNombre(Alumno al);

//devuelve el apellido de un Alumno
String DarApellido(Alumno al);

//devuelve el telefono de un Alumno
String DarTelefono(Alumno al);

//devuelve la escolaridad de un alumno
Escolaridad DarEscolaridad(Alumno al);
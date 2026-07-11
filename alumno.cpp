#include "alumno.h"


//devuelve la CI de un alumno
int DarCi(Alumno al)
{
    int salida;
    salida = al.ci;
    return salida;
}

//devuelve el nombre de un Alumno
String DarNombre(Alumno al)
{
    String nom;
    strCop(nom, al.nombre);
    return nom;
}

//devuelve el apellido de un Alumno
String DarApellido(Alumno al)
{
    String ape;
    strCop(ape, al.apellido);
    return ape;
}

//devuelve el telefono de un Alumno
String DarTelefono(Alumno al)
{
    String tel;
    strCop(tel, al.telefono);
    return tel;
}

//devuelve la escolaridad de un alumno
Escolaridad DarEscolaridad(Alumno al)
{
    return al.escolaridad;
}

//verifica si la asignatura existe en la escolaridad del alumno
bool ExisteEnEscolaridadAlumno(Alumno al, int nasig)
{
    return ExisteEnEscolaridad(al.escolaridad, nasig);
}

//insertar registro nuevo en escolaridad de alumno
void InsertarEscolaridadAlu(Alumno &al, int nasig, Fecha ffin, int calif)
{

    InsBack(al.escolaridad, CargarCurso(nasig, ffin, calif));
}
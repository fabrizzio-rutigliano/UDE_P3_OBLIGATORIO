#include "alumno.h"

//TODO inicializar y cargar no es lo mismo, se esta usando este metodo para
// cargar un alumno al sistema y en realidad no tiene ningún dato, ademas detener variables no utilizadas
//inicializar alumno
Alumno CargarAlumno()
{
    Alumno a;
    printf("\nIngrese la Cedula del alumno(con digito verificador, sin puntos ni guiones)... ");
    scanf("%d", &a.ci);
    strCrear(a.nombre);
    printf("\nIngrese el nombre del alumno... ");
    strScan(a.nombre);
    strCrear(a.apellido);
    printf("\nIngrese el apellido del alumno... ");
    strScan(a.apellido);
    strCrear(a.telefono);
    printf("\nIngrese el telefono del alumno... ");
    strScan(a.telefono);
    CrearEscolaridad(a.escolaridad);
    return a;
}

//devuelve la CI de un alumno
int DarCi(Alumno al)
{
    int salida;
    salida = al.ci;
    return salida;
}

//devuelve el nombre de un Alumno
void DarNombre(Alumno al, String &nom)
{
    strCop(nom, al.nombre);
}

//devuelve el apellido de un Alumno
void DarApellido(Alumno al, String &ape)
{
    strCop(ape, al.apellido);
}

//devuelve el telefono de un Alumno
void DarTelefono(Alumno al, String &tel)
{
    strCop(tel, al.telefono);
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
void InsertarEscolaridadAlu(Alumno &al, Curso cur)
{

    InsBackEscolaridad(al.escolaridad, cur);
}

//desplegar alumno
void DesplegarAlumno(Alumno al){
    printf("\nNombre: ");
    String strTemp;
    strCrear(strTemp);
    DarNombre(al, strTemp);
    strPrint(strTemp);

    printf("\nApellido: ");
    DarApellido(al, strTemp);
    strPrint(strTemp);

    printf("\nTeléfono: ");
    DarTelefono(al, strTemp);
    strPrint(strTemp);

    strDestruir(strTemp);

    Escolaridad escolaridad;
    escolaridad = DarEscolaridad(al);

    printf("\nCantidad total de cursos: %d", LargoEscolaridad(escolaridad));
    printf("\nCantidad de cursos aprobados: %d", CursosAprobadosEscolaridad(escolaridad));
}

// Libera la memoria utilizada por una alumno
void DestruirAlumno(Alumno &al){
    strDestruir(al.nombre);
    strDestruir(al.apellido);
    strDestruir(al.telefono);
}

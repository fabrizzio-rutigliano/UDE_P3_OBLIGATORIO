#include "asignatura.h"

//devuelve el nombre de la Asignatura
void DarNombre(Asignatura asig, String &strNom){
    strCop(strNom, asig.nombre);
}

//devuelve el nombre de la Asignatura
void DesplegarNombre(Asignatura asig){
    String strAux;
    strCrear(strAux);
    strCop(strAux, asig.nombre);
    strPrint(strAux);
    strDestruir(strAux);
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
Asignatura cargarAsignatura(String nombre, int cantidadHoras, bool optativa){
    Asignatura asig;

    strCrear(asig.nombre);
    strCop(asig.nombre, nombre);

    asig.cantidadHoras = cantidadHoras;
    asig.optativa = optativa;

    return asig;
}

//Ingresa una asignatura desde teclado
void IngresarAsignatura(Asignatura &a)
{
    int auxOpt;
    printf("\nIngrese el nombre de la asignatura... ");
    strCrear(a.nombre);
    strScan(a.nombre);
    printf("\nIngrese la cantidad de horas de la asignatura... ");
    scanf("%d",&a.cantidadHoras);
    printf("\nLa asignatura es optativa?(1 - Si / 0 - No)... ");
    scanf("%d", &auxOpt);
    bool optativa = (auxOpt != 0);
    a.optativa = optativa;
}

//desplegar asignatura
void DesplegarAsignatura(Asignatura a, int num){

    printf("\nNúmero: %d", num);
    printf("\nNombre: ");
    
    DesplegarNombre(a);
    
    printf("\nCantidad de horas: %d", DarCantidadHoras(a));
    if(DarOptativa(a))
        printf("\n Optativa: SI");
    else
        printf("\n Optativa: NO");
}

// Libera la memoria utilizada por una Asignatura
void destruirAsignatura(Asignatura &asig){
    strDestruir(asig.nombre);
}
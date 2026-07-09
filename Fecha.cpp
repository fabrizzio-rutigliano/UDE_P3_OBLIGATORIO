#include "Fecha.h"

// Cargar
void cargarFecha(Fecha &fecha)
{
    printf("Ingrese un dia: ");
    scanf("%d", &fecha.dia);
    printf("Ingrese un mes: ");
    scanf("%d", &fecha.mes);
    printf("Ingrese un anio: ");
    scanf("%d", &fecha.anio);
}

// Desplegar
void mostrarFecha(Fecha fecha)
{
    printf("%d/%d/%d", fecha.dia, fecha.mes, fecha.anio);
}

// Selectoras
int darDia(Fecha fecha)
{
    return fecha.dia;
}
int darMes(Fecha fecha)
{
    return fecha.mes;
}
int darAnio(Fecha fecha)
{
    return fecha.anio;
}

// Validez de la fecha ingresada
bool esValidaFecha(Fecha fecha)
{

    bool check = false;

    // validamos rango de dias por mes
    switch(fecha.mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (fecha.dia >= 1 && fecha.dia <= 31)
            check = true;
        else
            check = false;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (fecha.dia >= 1 && fecha.dia <= 30)
            check = true;
        else
            check = false;
        break;
    case 2:// validamos que el a�o sea biciesto
        if (fecha.anio % 4 == 0)
        {
            if (fecha.dia >= 1 && fecha.dia <= 29)
                check = true;
            else
                check = false;
        }
        else
        {
            if (fecha.dia  >= 1 && fecha.dia  <= 28)
                check = true;
            else
                check = false;
        }
        break;
    default:
        check = false;
    }

    return check;

}

bool esMayorFechas(Fecha a, Fecha b)
{
    bool check = false;

    if (darAnio(a) > darAnio(b))
        check = true;
    else if ((darAnio(a) == darAnio(b)) && (darMes(a)  > darMes(b)))
        check = true;
    else if ((darAnio(a) == darAnio(b)) && (darMes(a) == darMes(b)) && (darDia(a) > darDia(b)))
        check = true;

    return check;
}

bool sonIgualesFechas(Fecha a, Fecha b)
{

    if((darAnio(a) == darAnio(b)) && (darMes(a) == darMes(b)) && (darDia(a) == darDia(b)) )
    {
        return true;
    }
    return false;
}

// Copia una fecha en otra fecha
void copFecha(Fecha &fec1, Fecha fec2)
{
    fec1.dia = darDia(fec2);
    fec1.mes = darMes(fec2);
    fec1.anio = darAnio(fec2);
}

// ---------- AB STRUCT ------------

// ---------- ARCHIVO STRUCT FECHA --------------

// Escribe en el archivo los datos de fecha.
// Precondición: El archivo viene abierto para escritura.
void Bajar_Fecha(Fecha fec, FILE * f ){
    fwrite(&fec.dia, sizeof(int), 1, f);
    fwrite(&fec.mes, sizeof(int), 1, f);
    fwrite(&fec.anio, sizeof(int), 1, f);
}

// Lee desde el archivo los datos de la fecha.
// Precondición: El archivo viene abierto para lectura.
void Levantar_Fecha(Fecha &fec, FILE * f ){
    fread(&fec.dia, sizeof(int), 1, f);
    fread(&fec.mes, sizeof(int), 1, f);
    fread(&fec.anio, sizeof(int), 1, f);
}

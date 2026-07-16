#include "curso.h"



int DevolverNumero(Curso c)
{
    return c.numero;
}

Fecha DevolverFechaFin(Curso c)
{
    return c.fechaFin;
}

int DevolverCalificacion(Curso c)
{
    return c.calificacion;
}

void DesplegarNumero(Curso c)
{
    printf("%d",c.numero);
}

void DesplegarFechaFin(Curso c)
{
    mostrarFecha(c.fechaFin);
}

void DesplegarCalificacion(Curso c)
{
    printf("%d", c.calificacion);
}

Curso CargarCurso(int nro, Fecha ffin, int cal)
{
    Curso c;
    c.numero = nro;
    copFecha(c.fechaFin, ffin);
    c.calificacion = cal;
    return c;
}

void IngresarCurso(Curso &c, int nroAsig)
{
    c.numero = nroAsig;
    printf("\nIngrese la fecha de finalizacion del curso...");
    cargarFecha(c.fechaFin);
    printf("\nIngrese la calificacion...");
    scanf("%d",&c.calificacion);
}

bool CursoAprobado(Curso c){
    bool aprobado = true;
    if(c.calificacion<6)
        aprobado = false;
    return aprobado;
}

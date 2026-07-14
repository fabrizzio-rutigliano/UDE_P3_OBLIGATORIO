#include "menu.h"

//Muestra el menu principal
void desplegarMenuPrincipal(int &opcion){
    printf("\n***Menu de Principal***\n");
    printf("Ingrese una opcion:\n");
    printf("1 - Registrar nueva asignatura\n");
    printf("2 - Agregar previatura\n");
    printf("3 - Inscribir nuevo alumno\n");
    printf("4 - Registrar curso en escolaridad\n");
    printf("5 - Listar asignaturas\n");
    printf("6 - Listar previaturas\n");
    printf("7 - Listar alumno por cédula\n");
    printf("8 - Listar escolaridad alumno\n");
    printf("9 - Salir del programa\n");

    scanf("%d", &opcion);
}

/*// submenu que solicita CI
void desplegarMenuSolicitaCi()
{
    printf("\nIngrese la CI: ");
}

// Precondicion: fecha valida
// submenu que pide fecha
void desplegarMenuFinalizadosFecha()
{
    printf("\nIngrese la fecha\n------------------------\n\n ");
}

// submenu que pide apellido
void desplegarMenuApellido()
{
    printf("\nIngrese el apellido: ");
}

// Muestra un valor entero en pantalla
void desplegarInt(int a)
{
    printf("\n%d\n", a);
}

// Muestra los valores  menores, mayores e iguales para la consulta por apellidos
void desplegarMayMenIg(int men, int may, int ig)
{
    printf("\nMenores: %d", men);
    printf("\nMayores: %d", may);
    printf("\nIguales: %d\n", ig);
}

// Muestra no existencia de alumno con cedula ci
void desplegarNoExisteAlumno(long int ci)
{
    printf("\nNo existe en el sistema un alumno con la cedula %ld\n", ci);
}

// Muestra la cantidad de alumnos nacidos nacidos
void desplegarCantAlumnosNacidosEnFecha(int cant)
{
    printf("\nCantidad de alumnos nacidos en la fecha seleccionada es %d\n", cant);
}

// Muestra la cantidad de registros finalizados
void desplegarCantRegistrosFinalizados(int cant)
{
    printf("\nCantidad de registros finalizados en la fecha seleccionada es %d\n", cant);
}

// Muestra la no existencia de taller popular
void desplegarNoExistenciaTallerPopular()
{
    printf("\nNo existe ningun taller popular\n");
}

// Muestra si encontro un archivo de alumnos
void desplegarArchAluEncontrado()
{
    printf("\nArchivo de alumnos encontrado. Cargando archivo...\n");
}

// Muestra si encontro un archivo de registro
void desplegarArchRegEncontrado()
{
    printf("\nArchivo de registros encontrado. Cargando archivo...\n");
}
// Muestra que aún no hay registros en alumnos
void desplegarNoExisteArbolAlumno()
{
    printf("\nNo existen alumnos registrados. Por favor, registre un alumno para usar la consulta.\n");
}

// Muestra que la fecha ingresada es invalida
void desplegarAdvertenciaFecha(){
    printf("\nFecha invalida. Reintente \n");
}

// Muestra que la fecha ingresada es menor a la ultima ingresada en la lista
void desplegarAdvertenciaFechaList(){
    printf("\nDebe ingresar una fecha mayor o igual al ultimo registro. \n");
}
 */
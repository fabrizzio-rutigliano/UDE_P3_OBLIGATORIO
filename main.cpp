#include "menu.h"
//#include "testEscolaridad.h"
//#include "testAsignatura.h"
//#include "testAsignaturas.h"
//#include "testAlumno.h"
//#include "testAlumnos.h"
//#include "testCurricula.h"

/*

Fecha String arreglar boolean, y limpiar no utilizables (Gus)9 Done!

Alumno  GP
Alumnos GP
Asignatura Gus Done!
Asignaturas Gus Done!
Curricula Fabri
Constantes GP
Menu Gus

Crear alumno -> Crear de escolaridad
*/

int main() {

    int opcion, ci;
    Asignaturas asigns;
    Alumnos als;
    Alumno a;
    Curso cur;
    Curricula curricula;



    Crear(asigns);
    
    //crear alumnos
    Make(als);

    //Inicializar matriz de adyacencia para curricula
    Crear(curricula);
    
    //testEscolaridad();
    //testEscolaridad();
    //testAlumno();
    //testAlumnos();
    //ejecutarTestAsignatura();
    //ejecutarTestAsignaturas();

    do
    {
        desplegarMenuPrincipal(opcion);
        switch (opcion)
        {
        case 1:
            printf("\nSelecciono registrar nueva asignatura\n");
            AgregarAsignaturaEnAsignaturas(asigns);
            break;
        case 2:
            printf("\nSelecciono agregar previatura\n");
                int prev, requiere, topeActual;
                topeActual = TopeActualAsignaturas(asigns);
                IngresarPreviatura(prev, requiere); // Solo permite avanzar si logra insertar nros validos
                if (!GeneraCiclo(curricula, prev, requiere, topeActual)){
                    InsertarArista(curricula, prev, requiere);
                } else {ErrorGeneraCiclo();}
            break;
        case 3:
            printf("Selecciono inscribir nuevo alumno");
            //GP en curso
            a = CargarAlumno();
            if(Member(als, a.ci))
                Insert(als, a);
            else
                ErrorExisteAlumno();
            break;
        case 4:
            printf("Selecciono registrar curso en escolaridad");
            //GP
            printf("\ningrese la CI del alumno al que desea cargar el curso... ");
            scanf("%d",&ci);
            if (!Member(als, ci))
                ErrorNoExisteAlumno();
            else
            {
                a = Find(als, ci);
                IngresarCurso(cur);
                if (ExisteEnEscolaridad(DarEscolaridad(a), cur.numero))
                    ErrorCursoYaExiste();
                else if (!EsVaciaEscolaridad(DarEscolaridad(a)) && !esMayorFechas(cur.fechaFin, DevolverFechaFin(DarUltimoEscolaridad(DarEscolaridad(a)))))
                    ErrorFechaCursoAnteriorAlUltimo();
                else
                {
                    InsBackEscolaridad(a.escolaridad, cur);
                    Modify(als, a);
                }
            }
            break;
        case 5:
            printf("Selecciono listar asignaturas");
            if(esVacia(asigns) == true)
                printf("Las asignaturas estan vacias\n");
            else
                listarAsignaturas(asigns);
            break;
        case 6:
            printf("\nSelecciono listar previaturas\n");
            // Fabri
            int nroAsig, topeActual;
            topeActual = TopeActualAsignaturas(asigns);
            int resultado[MAX_ASIG]; // Arreglo auxiliar para guardar las previas
            int topeResultado = 0;
            IngresarNroAsignatura(nroAsig); // Solo permite avanzar si logra insertar nros validos
            ListarTodasLasPrevias(curricula, nroAsig, topeActual, resultado, topeResultado);
            for(int i=0; i< topeResultado; i++){
                printf("\nNro: &d - Asignatura: ", resultado[i]);
                DesplegarNombre(asigns.arre[resultado[i]]);
                printf("\n");
            }
            break;
        case 7:
            printf("Selecciono listar alumno por cédula");//Gus
            break;
        case 8:
            printf("Selecciono listar escolaridad alumno");
            //GP
            break;
        case 9:
            break;
        default:
            printf("Opcion incorrecta!\n");
            break;
        }

    }
    while(opcion!=9);

    //destruir Asignaturas
    destruirAsignaturas(asigns);

    //destruir alumnos


   

    return 0;
}
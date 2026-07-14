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

    int opcion, ci, topeActual;
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
        topeActual = 0;
        desplegarMenuPrincipal(opcion);
        switch (opcion)
        {
        case 1:
            printf("\nSelecciono registrar nueva asignatura\n");
            AgregarAsignaturaEnAsignaturas(asigns);
            break;
        case 2:{
            printf("\nSelecciono agregar previatura\n");
                int prev = 0; 
                int requiere = 0;
                topeActual = TopeActualAsignaturas(asigns);
                IngresarPreviatura(asigns, prev, requiere); // Solo permite avanzar si logra insertar nros validos
                if (!GeneraCiclo(curricula, prev, requiere, topeActual)){
                    InsertarArista(curricula, prev, requiere);
                } else {ErrorGeneraCiclo();}
            break;
        }
        case 3:
            printf("\nSelecciono inscribir nuevo alumno\n");
            //GP en curso
            a = CargarAlumno();
            if(Member(als, a.ci))
                ErrorExisteAlumno();
            else
            {
                Insert(als, a);
                printf("\nEl alumno fue cargado con exito\n");
            }
            break;
        case 4:
            printf("\nSelecciono registrar curso en escolaridad\n");
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
            printf("\nSelecciono listar asignaturas\n");
            if(esVacia(asigns) == true)
                printf("Las asignaturas estan vacias\n");
            else
                listarAsignaturas(asigns);
            break;
        case 6: {
            printf("\nSelecciono listar previaturas\n");
            // Fabri
            int nroAsig = 0;
            topeActual = TopeActualAsignaturas(asigns);
            int resultado[MAX_ASIG]; // Arreglo auxiliar para guardar las previas
            int topeResultado = 0;
            IngresarNroAsignatura(asigns, nroAsig); // Solo permite avanzar si logra insertar nros validos
            ListarTodasLasPrevias(curricula, nroAsig, topeActual, resultado, topeResultado);
            for(int i=0; i< topeResultado; i++){
                printf("\nNro: &d - Asignatura: %d", resultado[i]);
                DesplegarNombre(asigns.arre[resultado[i]]);
                printf("\n");
            }
            break;
        }
        case 7:
            printf("\nSelecciono listar alumno por cédula\n");//Gus
            printf("\ningrese la CI del alumno al que desea listar... ");
            scanf("%d",&ci);
            if (!Member(als, ci))
                ErrorNoExisteAlumno();
            else
            {
                a = Find(als, ci);
                DesplegarAlumno(a);
                printf("\n");
            }
            break;
        case 8: //GP
            printf("\nSelecciono listar escolaridad alumno\n");
            printf("\nIngrese la CI del alumno a listar la escolaridad...");
            scanf("%d",&ci);
            if(!Member(als, ci))
                ErrorNoExisteAlumno();
            else if(EsVaciaEscolaridad(DarEscolaridad(Find(als, ci))))
                ErrorEscolaridadVacia();
            else
                DesplegarEscolaridad(DarEscolaridad(Find(als, ci)));
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
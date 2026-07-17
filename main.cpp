#include "menu.h"

int main() {

    int opcion, ci, topeActual, nroAsig, j;
    Asignaturas asigns;
    Asignatura asig;
    Alumnos als;
    Alumno a;
    Curso cur;
    Curricula curricula;
    bool PreviasAprobadas;

    Crear(asigns);

    //crear alumnos
    Make(als);

    //Inicializar matriz de adyacencia para curricula
    Crear(curricula);

    do
    {
        topeActual = 0;
        nroAsig = 0;
        desplegarMenuPrincipal(opcion);
        switch (opcion)
        {
        case 1:
            printf("\nSelecciono registrar nueva asignatura\n");
            if(TopeActualAsignaturas(asigns) == MAX_ASIG){
                ErrorAsignaturasMaximas();
            }else{
                IngresarAsignatura(asig);
                InsBack(asig, asigns);}
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
            printf("\ningrese la CI del alumno al que desea cargar el curso... ");
            scanf("%d",&ci);
            if (!Member(als, ci))
                ErrorNoExisteAlumno();
            else
            {
                PreviasAprobadas = true;
                a = Find(als, ci);
                IngresarNroAsignatura(asigns, nroAsig);
                IngresarCurso(cur, nroAsig);
                topeActual = TopeActualAsignaturas(asigns);
                for (j = 0; j < topeActual && PreviasAprobadas; j++)
                {
                    if (PerteneceArista(curricula, j, cur.numero) && !ExisteAprobadoEnEscolaridad(DarEscolaridad(a), j))
                        PreviasAprobadas = false;
                }
                if (ExisteAprobadoEnEscolaridad(DarEscolaridad(a), cur.numero))
                    ErrorCursoYaExiste();
                else if (!EsVaciaEscolaridad(DarEscolaridad(a)) && esMayorFechas(DevolverFechaFin(DarUltimoEscolaridad(DarEscolaridad(a))), cur.fechaFin))
                    ErrorFechaCursoAnteriorAlUltimo();
                else if(!PreviasAprobadas)
                    ErrorPrevias();
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
            topeActual = TopeActualAsignaturas(asigns);
            int resultado[MAX_ASIG]; // Arreglo auxiliar para guardar las previas
            int topeResultado = 0;
            IngresarNroAsignatura(asigns, nroAsig); // Solo permite avanzar si logra insertar nros validos
            ListarTodasLasPrevias(curricula, nroAsig, topeActual, resultado, topeResultado);
            for(int i=0; i< topeResultado; i++){
                printf("\nNro: %d - Asignatura: ", resultado[i]);
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
        case 8:
            printf("\nSelecciono listar escolaridad alumno\n");
            printf("\nIngrese la CI del alumno a listar la escolaridad...");
            scanf("%d",&ci);
            if(!Member(als, ci))
                ErrorNoExisteAlumno();
            else if(EsVaciaEscolaridad(DarEscolaridad(Find(als, ci))))
                ErrorEscolaridadVacia();
            else
                DesplegarEscolaridad(DarEscolaridad(Find(als, ci)), asigns);
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
    DestruirAlumnos(als);
    return 0;
}

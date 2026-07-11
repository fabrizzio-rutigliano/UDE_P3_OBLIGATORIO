# Programación III

## Trabajo Obligatorio

**Curso 2026**  
**Licenciatura e Ingeniería en Informática**  
**Mínimo de aprobación: 50 puntos**

> Este material es de uso exclusivo para los cursos impartidos por Universidad de la Empresa.

- Los grupos deberán tener exactamente tres (3) integrantes. En caso de que la cantidad total de estudiantes no sea múltiplo de 3, se admitirá excepcionalmente algún grupo de dos (2) integrantes.

- **Fecha de entrega: viernes 17 de julio de 2026 hasta las 23:59 hs.** Se debe entregar:

  - Un documento en PDF conteniendo:
    - Modelado en términos de un grafo de aquel aspecto del problema que lo requiera.
    - Análisis de tipos abstractos de datos para el problema, justificando la elección.
    - Encabezados de las primitivas y otras operaciones de cada uno de los T.A.D anteriores a utilizar en la implementación, incluyendo toda precondición que sea necesaria.
    - Elección de estructuras de datos para los T.A.D anteriores, justificando la elección y escritura en C++ de los tipos correspondientes (`typedef`).
    - Diagrama de módulos para el sistema, con sus correspondientes inclusiones.

  - Un archivo ZIP conteniendo todos los módulos implementados (archivos `.h` y `.cpp`). Se deben excluir los archivos compilados (`.o`) y el archivo ejecutable (`.exe`).

- Ambas partes de la entrega deberán estar debidamente identificadas con los nombres y las cédulas de los integrantes del grupo y serán enviadas por mail a la dirección de correo electrónico indicada por el docente.

- En la última clase previa a la entrega (martes 14/07 en Punta del Este, miércoles 15/07 en Montevideo, viernes 17/07 en Colonia) se tomará una defensa oral del obligatorio a cada grupo. La misma consistirá en una serie de preguntas del trabajo, pudiendo abarcar tanto aspectos de diseño como de implementación, deberá ser realizada por todos los integrantes del grupo. El desempeño de cada integrante en la defensa influirá en la nota final del trabajo.

## Objetivo

- Puesta en práctica de diversos conceptos vistos durante el curso.

## Planteo del problema

Se trata de una academia de moda que dicta una carrera de diseño de indumentaria. La carrera tiene una cantidad máxima de 30 asignaturas (ya que algunas de ellas son optativas y no todos los alumnos cursan siempre las 30). De cada una se registra número de asignatura, nombre, cantidad de horas y si es optativa o no. Los números de asignatura son consecutivos y se asignan por orden de registro en el sistema. La primera asignatura registrada es la 0, la siguiente es la 1, y así sucesivamente.

La carrera posee un régimen de previaturas estrictas entre asignaturas. Esto significa que, para poder cursar una asignatura es necesario haber aprobado antes todas sus previas. Por ejemplo, “Diseño textil 2” tiene como previa “Diseño textil 1” y a su vez “Diseño textil 1” tiene como previas “Introducción al diseño” y “Conceptos básicos de indumentaria”. El estudiante debe haber cursado y aprobado todas ellas para poder cursar “Diseño textil 2”. Debido al prestigio de la academia, el régimen de previaturas es estricto y se sabe que la cantidad de previaturas es elevada.

También interesa registrar los datos de los alumnos de la academia. De cada uno se registra cédula, nombre, apellido, teléfono y los cursos de su escolaridad. Se sabe que en la academia se inscriben aproximadamente 100 alumnos, aunque este número no es exacto.

A su vez, de cada curso de la escolaridad del alumno se registra número y nombre de la asignatura cursada, fecha de finalización y la calificación final obtenida por el alumno (número entero entre 0 y 12). Cada curso se registra en la escolaridad del alumno una vez que ha finalizado y se cuenta con la calificación final. Interesa que los cursos queden almacenados en la escolaridad en forma cronológica por fecha de finalización. No existen instancias de examen para esta carrera, los cursos solo se pueden aprobar durante su realización. La calificación mínima de aprobación es 6. En caso de que el estudiante obtenga menos de 6, deberá recursar nuevamente más adelante. No hay límite para la cantidad de veces que el alumno puede recursar una misma asignatura hasta aprobarla finalmente.

En este obligatorio se va a desarrollar un primer prototipo del programa que permitirá registrar las asignaturas y sus previaturas, así como gestionar los datos de los alumnos y sus escolaridades, no interesando contemplar otros aspectos (como inasistencias, grupos de alumnos, horarios de clase, etc.). Los requerimientos que se desea resolver en este primer prototipo son los siguientes:

1. **Registrar una nueva asignatura.** Se le asignará en forma automática el número siguiente al de la última asignatura registrada hasta el momento. Por ejemplo, si la última asignatura registrada tenía el número 3, la nueva asignatura tendrá el número 4. Si es la primera asignatura, se le asignará el número 0. En caso de que ya se hayan registrado las 30 asignaturas, el registro no será llevado a cabo y se emitirá un mensaje de error apropiado.

2. **Agregar una previatura directa.** Dados los números de dos asignaturas, agregar una previatura directa entre ellas, cuidando que no se forme un ciclo de previaturas en el sistema. En caso de formarse un ciclo, o que (al menos una de) las asignaturas con dichos números no esté(n) registrada(s), no se agregará la previatura y se emitirá un mensaje de error apropiado.

3. **Inscribir un nuevo alumno.** Inscribir un nuevo alumno en la academia, chequeando previamente que no exista otro alumno con la misma cédula. En caso de existir, la inscripción no se realizará y se emitirá un mensaje de error apropiado.

4. **Registrar un curso en la escolaridad.** Dados la cédula de un alumno, un número de asignatura, la fecha de finalización y la calificación obtenida, registrar el correspondiente curso en su escolaridad. Se debe verificar que tanto el alumno con esa cédula como la asignatura con ese número estén registrados, que el alumno no haya aprobado la asignatura anteriormente, que tenga aprobadas todas las previas inmediatas de la asignatura (recordar que la nota mínima de aprobación es 6) y que la fecha de finalización sea igual o posterior a la fecha del último curso registrado hasta el momento en la escolaridad del alumno. En caso de no cumplirse cualquiera de estas condiciones, el registro no será realizado y se emitirá un mensaje de error apropiado.

5. **Listar las asignaturas.** Listar por pantalla los datos de todas las asignaturas registradas en el sistema (número, nombre, cantidad de horas y si es optativa o no), ordenadas por número de asignatura de menor a mayor.

6. **Listar todas las previas de una asignatura.** Dado el número de una asignatura, listar por pantalla número y nombre de cada una de sus asignaturas previas (no solamente de las previas inmediatas, sino de todas sus previas). Por ejemplo, todas las previas de “Diseño textil 2” son “Diseño textil 1”, “Introducción al diseño” y “Conceptos básicos de indumentaria”. Las previas pueden ser listadas en cualquier orden. En caso de que la asignatura con ese número no esté registrada, se emitirá un mensaje de error apropiado.

7. **Listar los datos y el resumen académico de un alumno.** Dada la cédula de un alumno, listar por pantalla sus datos básicos (nombre, apellido y teléfono) junto con la cantidad total de cursos que tiene registrados hasta el momento en su escolaridad y la cantidad de cursos que tiene aprobados. En caso de que el alumno con esa cédula no esté registrado, se emitirá un mensaje de error apropiado.

8. **Listar la escolaridad de un alumno.** Dada la cédula de un alumno, listar su escolaridad por pantalla, ordenada cronológicamente por fecha de finalización de sus cursos, empezando por el más antiguo y terminando por el más reciente. De cada curso se listará el número y el nombre de la asignatura cursada, la fecha de finalización y la calificación obtenida, mostrando además un mensaje que indique si está aprobada o no (recordar que la nota mínima de aprobación es 6). En caso de que el alumno con esa cédula no esté registrado, se emitirá un mensaje de error apropiado.

## Se pide

### a) Modelado mediante un grafo

Modelar el problema de representar las previaturas mediante un grafo, explicando qué representan vértices y aristas e indicando qué propiedad(es) debe cumplir dicho grafo.

### b) Análisis de Tipos Abstractos de Datos

Realizar el análisis de Tipos Abstractos de Datos para la realidad propuesta, incluyendo el grafo anterior en el análisis, justificando.

### c) Elección de estructuras de datos

Elegir las estructuras de datos más adecuadas para los T.A.D anteriores, justificando la elección y escribir en C++ los tipos de datos correspondientes.

### d) Esquema de módulos

Dibujar el esquema de módulos para los T.A.D elegidos, mostrando las inclusiones entre ellos.

### e) Implementación

Implementar el sistema en C++, respetando abstracción y modularización. Para interactuar con un T.A.D definido en otro módulo se deben utilizar sus primitivas y otras operaciones necesarias de dicho módulo, sin acceder directamente a su estructura de datos.

## Observaciones

- Por tratarse de un primer prototipo, en este obligatorio no se pide respaldar en archivos la información manejada en memoria. Tampoco se pide eliminar de la memoria la información manejada (se borrará automáticamente cuando el sistema finalice su ejecución).

- En caso de que más de un T.A.D sea utilizable para representar un mismo concepto, elegir aquel que resulte más adecuado, justificando apropiadamente.

- En caso de que más de una estructura de datos sea utilizable para implementar un mismo T.A.D, elegir aquella que resulte más adecuada, justificando apropiadamente.

- Implemente un módulo aparte para cada T.A.D. En cada módulo, incluya las operaciones primitivas del T.A.D junto con cualquier otra operación adicional que pueda necesitar. Realice un análisis detallado de todas las operaciones necesarias previo a implementar.

- Al implementar recuerde trabajar ordenadamente, partiendo de los módulos más simples y continuando con los más complejos, realizando programas de prueba para cada módulo.

- Los encabezados de las primitivas y otras operaciones incluidas en el documento deben coincidir exactamente con aquellas que luego sean implementadas en los distintos módulos de la aplicación. En particular, el nombre de cada primitiva debe coincidir con el nombre provisto para ella en el material teórico del curso.

- Para facilitar la gestión del código fuente y realizar manejo de versiones, se sugiere crear un repositorio en GitHub durante la realización del trabajo (ver manual correspondiente en la página del curso en Moodle).
#include "String.h"

void strCrear(String &s)
{
    s = new char[1];
    s[0] = '\0';
}

void strDestruir(String &s)
{
    delete[] s;
    s = NULL;
}

int strLar(String s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void strCop(String &s1, String s2)
{
    int i = 0;
    int largo = strLar(s2) + 1;
    delete[] s1;
    s1 = new char[largo];
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void strScan(String &s)
{
    String aux = new char[MAX];
    int i = 0;
    char c;
    scanf(" %c", &c);
    while (c != '\n' && i < MAX - 1)
    {
        aux[i] = c;
        i++;
        scanf("%c", &c);
    }
    aux[i] = '\0';
    strCop(s, aux);
    strDestruir(aux);
}

void strPrint(String s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        printf("%c", s[i]);
        i++;
    }
}

bool strEq(String s1, String s2)
{
    int i = 0;
    bool iguales = true;
    while (iguales && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
            iguales = false;
        i++;
    }
    if ((s1[i] != '\0') || (s2[i] != '\0'))
        iguales = false;
    return iguales;
}

// ---------- ARCHIVO String --------------------------------------
// Escribe en el archivo los caracteres del String s (incluido '\0')
// Precondición: El archivo viene abierto para escritura.

void Bajar_String (String s, FILE * f){
    int i=0;
    while (s[i] != '\0')
    {
        fwrite (&s[i], sizeof(char), 1, f);
        i++;
    }
    // escribo el '\0'
    fwrite (&s[i], sizeof(char), 1, f);
}

// Lee desde el archivo los caracteres del String s.
// Precondición: El archivo viene abierto para lectura.
void Levantar_String (String &s, FILE * f){
    int i=0;
    String aux;
    aux = new char[MAX];
    fread (&aux[i], sizeof(char), 1, f);
    while (!feof(f) && (aux[i] != '\0'))
    {
        i++;
        fread (&aux[i], sizeof(char), 1, f);
    }
    if (feof(f))
        aux[i] = '\0';
    strCop (s, aux);
    delete [] aux;
}

// ---------- Funciones / Procedimientos Específicos ------------

//Valida si el string s es vacio
bool strEsVacio(String s){
    bool result = false;
    if (strLar(s) == 0 && s[0] == '\0'){
        result = true;
    }
    return result;
}

//Transforma un String a un entero
//Precondicion el String es un entero
int strStringToInt(String s)
{
    int i = 0;
    int result = 0;
    bool negativo = false;

    if (s[0] == '-'){
        negativo = true;
        i = 1;
    }

    while (s[i] != '\0'){
        result = result * 10 + (s[i] - '0');
        i++;
    }

    if (negativo == true)
        result = -result;

    return result;
}


//Transforma un String en un char
//Precondicion: S es variable, operador o parentesis
char strStrToChar(String s){
    return s[0];
}

// Auxiliar para evaluar si es numerico.
bool strEsDigito(char c) {
    
    bool check = false;
    if (c >= '0' && c <= '9')
        check = true;
    
    return check;
}

// Auxiliar para evaluar caracter.
bool strEsLetra(char c) {
    bool check = false;
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        check = true;

    return check;
}

// Auxiliar para evaluar espacio en blanco.
bool strEsEspacioBlanco(char c) {
    bool check = false;
    if (c == ' ') //|| c == '\t' || c == '\n'
        check = true;
    return check;
}

// Devuelve si s1 representa a un entero
bool strEsEntero(String s1) {
    
    bool check = true;
    int i = 0;

    // Si es NULL no es entero
    if (s1 == NULL)
        check = false;
    // Si viene salto de str tampoco
    if (check && s1[0] == '\0')
        check = false;
    // Evaluamos si es negativo
    if (check && (s1[i] == '-')) {
        i++;

        // Si luego del signo viene termino str no es válido.
        if (s1[i] == '\0')
            check = false;
        // Dejamos el i posicionado en el segundo caracter.
    }

    // Todos los restantes deben ser dígitos
    while (check && s1[i] != '\0') {
        if (strEsDigito(s1[i]) == false)
            check = false;
        i++;
    }

    return check;
}

// Devuelve si s1 representa a un entero positivo
// PARA REVISAR: Positivo = Natural, o mayor estricto a 0??
bool strEsEnteroPositivo(String s1){
    bool check = true;
    int i = 0;
    

    // si es NULL no es válido
    if (s1 == NULL)
        check = false;
    // Si viene salto de str tampoco
    if (check && s1[0] == '\0')
        check = false;

    // Todos deben ser dígitos
    while (check && s1[i] != '\0') {
        if (strEsDigito(s1[i]) == false)
            check = false;
        i++;
    }
    
    return check;
};

// Devuelve si s1 representa a una cadena de caracteres alfabeticas
bool strEsAlfabetico(String s1){
    bool check = true;
    int i = 0;

    if (s1 == NULL)
        check = false;

    if (check && s1[0] == '\0')
        check = false;

    while (check && s1[i] != '\0') {
        if (strEsLetra(s1[i]) == false)
            check = false;
        i++;
    }

    return check;
};

// Elimina los espacios en blanco al principio del string.
void strEliminarEspaciosInicio( String sin, String &sout){
    
    int i = 0;
    int j = 0;
    String aux = new char[MAX];

    if ((sin != NULL)) {
        while (sin[i] != '\0' && strEsEspacioBlanco(sin[i]) == true)
            i++;

        while (sin[i] != '\0' && j < MAX - 1) {
            aux[j] = sin[i];
            j++;
            i++;
        }
        aux[j] = '\0';

        strCop(sout, aux);
        
    }
    
    delete[] aux;
};

// Devuelve si s1 es una cadena de espacios
bool strEsCadenaEnBlanco(String s1){
    int i = 0;
    bool enBlanco = true;

    if(strEsVacio(s1)){
        enBlanco = false;
    }

    while (s1[i] != '\0' && enBlanco){
        if(!strEsEspacioBlanco(s1[i])){
            enBlanco = false;
        }
        i++;
    }
    return enBlanco;
}

/* Devuelve sOut con la primera palabra de sIn, 
    y devuelve sResto con lo que está después de la palabra inicial.*/
void strDividir(String sin, String &sout, String &sresto){
    
    int i = 0;
    int j = 0;
    int k = 0;

    if (sin != NULL) {
        // Saltear espacios blancos iniciales
        while (sin[i] != '\0' && strEsEspacioBlanco(sin[i]) == true)
            i++;
        
        // primera palabra
        String o = new char[MAX];
        while (sin[i] != '\0' && strEsEspacioBlanco(sin[i]) == false && j < MAX - 1) {
            o[j] = sin[i];
            j++;
            i++;
        }
        o[j] = '\0';

        // resto (lo que sigue a partir de i)
        String r = new char[MAX];
        while (sin[i] != '\0' && k < MAX - 1) {
            r[k] = sin[i];
            k++;
            i++;
        }
        r[k] = '\0';
        if(strEsCadenaEnBlanco(r)){
            r[0] = '\0';
        }

        strCop(sout, o);
        strCop(sresto, r);

        delete[] o;
        delete[] r;
    }
};

// Valida si s1 es la variable X
bool strEsVariable(String s1){
    bool check = true;
    // Que no sea nulo
    if (s1 == NULL)
        check = false;
    // Evalua que sea variable X
    if (check && (s1[0] != 'X' && s1[0] != 'x'))
        check = false;
    // Y que termine inmediatamente luego de la variable
    if (check && s1[1] != '\0')
        check = false;

    return check;
};

// Valida si s1 es un operador (+,-,*,/)
bool strEsOperador(String s1){
    bool check = true;
    // Que no sea nulo
    if (s1 == NULL)
        check = false;
    // Debe ser un solo caracter
    if (check && s1[1] != '\0')
        check = false;
    // Evalua que sea un simbolo valido
    if (check && (s1[0] != '+' && s1[0] != '-' && s1[0] != '*' && s1[0] != '/'))
        check = false;

    return check;
};

bool comandoEsValido(String str){
    
    bool check = false;

    String simple;
    strCrear(simple);
    char auxSimple[] = "simple";
    strCop(simple, auxSimple);

    String compuesta;
    strCrear(compuesta);
    char auxComp[] = "compuesta";
    strCop(compuesta, auxComp);

    String mostrar;
    strCrear(mostrar);
    char auxMostrar[] = "mostrar";
    strCop(mostrar, auxMostrar);
    
    String calcular;
    strCrear(calcular);
    char auxCalc[] = "calcular";
    strCop(calcular, auxCalc);
    
    String iguales;
    strCrear(iguales);
    char auxIguales[] = "iguales";
    strCop(iguales, auxIguales);

    String guardar;
    strCrear(guardar);
    char auxGuardar[] = "guardar";
    strCop(guardar, auxGuardar);

    String recuperar;
    strCrear(recuperar);
    char auxRecuperar[] = "recuperar";
    strCop(recuperar, auxRecuperar);

    String salir;
    strCrear(salir);
    char auxSalir[] = "salir";
    strCop(salir, auxSalir);

    if (str != NULL) {

        if (strEq(str, simple) == true)
            check = true;
        else if (strEq(str, compuesta) == true)
            check = true;
        else if (strEq(str, calcular) == true)
            check = true;
        else if (strEq(str, iguales) == true)
            check = true;
        else if (strEq(str, mostrar) == true)
            check = true;
        else if (strEq(str, guardar) == true)
            check = true;
        else if (strEq(str, recuperar) == true)
            check = true;
        else if (strEq(str, salir) == true)
            check = true;
    }

    strDestruir(simple);
    strDestruir(compuesta);
    strDestruir(calcular);
    strDestruir(mostrar);
    strDestruir(iguales);
    strDestruir(guardar);
    strDestruir(recuperar);
    strDestruir(salir);

    return check;
};
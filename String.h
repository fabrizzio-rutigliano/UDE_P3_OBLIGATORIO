#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <stdio.h>

const int MAX = 80;
typedef char * String;

//===================================================================================================================

// Crea un string vacío
void strCrear(String &s);

// Libera la memoria usada por el string
void strDestruir(String &s);

// Devuelve el largo del string s */
int strLar(String s);

// Copia el contenido del string s2 en s1
void strCop(String &s1, String s2);

// Lee el string s desde teclado
void strScan(String &s);

// Imprime el string s por pantalla
void strPrint(String s);

// Determina si los strings s1 y s2 son iguales
bool strEq(String s1, String s2);

// ---------- ARCHIVO String ------------
// Escribe en el archivo los caracteres del string s (incluido '\0')
// Precondición: El archivo viene abierto para escritura.

void Bajar_String (String s, FILE * f);

// Lee desde el archivo los caracteres del string s.
// Precondición: El archivo viene abierto para lectura.
void Levantar_String (String &s, FILE * f);

// ---------- Funciones / Procedimientos Específicos ------------

//Valida si el string s es vacio
bool strEsVacio(String s);

//Transforma un String a un entero
//Precondicion el String es un entero
int strStringToInt(String s);

//Transforma un String en un char
//Precondicion: S es variable, operador o parentesis
char strStrToChar(String s);

// Auxiliar para evaluar si es numerico.
bool strEsDigito(char c);

// Auxiliar para evaluar caracter.
bool strEsLetra(char c);

// Auxiliar para evaluar espacio en blanco.
bool strEsEspacioBlanco(char c);

// Devuelve si s1 representa a un entero
bool strEsEntero(String s1);

// Devuelve si s1 representa a un entero positivo
bool strEsEnteroPositivo(String s1);

// Devuelve si s1 representa a una cadena de caracteres alfabeticas
bool strEsAlfabetico(String s1);

// Elimina los espacios en blanco al principio del string.
void strEliminarEspaciosInicio(String sin, String &sout);

// Devuelve si s1 es una cadena de espacios
bool strEsCadenaEnBlanco(String s1);

// Devuelve sOut con la primera palabra de sIn, y devuelve sResto con lo que está después de la palabra inicial.
void strDividir(String sin, String &sout, String &sresto);

// Valida si s1 es la variable X
bool strEsVariable(String s1);

// Valida si s1 es un operador (+,-,*,/)
bool strEsOperador(String s1);

/* Evalua si el string es un accion inicial de comando válida
Precondicion: No contiene espacios iniciales*/
bool comandoEsValido(String str);

#endif // STRING_H_INCLUDED

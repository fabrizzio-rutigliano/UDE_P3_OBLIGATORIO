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

// ---------- Funciones / Procedimientos Específicos ------------

//Valida si el string s es vacio
bool strEsVacio(String s);

#endif // STRING_H_INCLUDED

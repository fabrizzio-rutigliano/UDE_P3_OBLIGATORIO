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

// ---------- Funciones / Procedimientos Específicos ------------

//Valida si el string s es vacio
bool strEsVacio(String s){
    bool result = false;
    if (strLar(s) == 0 && s[0] == '\0'){
        result = true;
    }
    return result;
}
#include <stdlib.h>
#include<stdio.h>
#include<stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
int characterCount ;
int printInteger;
char integerString[10];
char *pPrintString;
va_list vaList;
unsigned int charToPrint;
va_start (vaList, pszFormat);

while(*format)
{
if(*format == '%')
{
format++;
switch(*format)
{
case 'c':
charToPrint= va_arg(vaList,int );
putchar(charToPrint);
format++;
characterCount++;
break;

case 's':
pPrintString = va_arg(vaList,char *);
fputs(pPrintString,stdout);
format++;
characterCount += strlen(pPrintString);
break;
    
case '%':
putchar('%');
format++;
characterCount++;


case '\0':                           
break;

default:
//putchar('%');
putchar(*format);
format++;
characterCount += 2;
}
}
else
{
putchar(*format);
format++;
characterCount++;
}
} 
va_end(vaList);
return (characterCount); 
}

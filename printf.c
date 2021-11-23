#include <stdio.h>
#include<stdarg.h>
#include "main.h"
#include<unistd.h>
int _printf(const char *format, ...)
{
int characterCount ;
/*
  int printInteger;
*/
/*
char integerString[10];
*/
char *pPrintString;
va_list vaList;
unsigned int charToPrint;
va_start (vaList, format);

while(*format)
{
if(*format == '%')
{
format++;
switch(*format)
{
case 'c':
charToPrint= va_arg(vaList,int );
_putchar(charToPrint);
format++;
characterCount++;
break;

case 's':
pPrintString = va_arg(vaList,char *);
fputs(pPrintString,stdout);
format++;
characterCount += countstr(pPrintString);
break;
    
case '%':
_putchar('%');
format++;
characterCount++;


case '\0':                           
break;

default:
_putchar('%');
_putchar(*format);
format++;
characterCount += 2;
}
}
else
{
_putchar(*format);
format++;
characterCount++;
}
} 
va_end(vaList);
return (characterCount); 
}

int countstr(char *ptr)
{
 int counter = 0;
 while(*ptr != '\0')
 {
 ptr++;
 counter++;
 }
 return (counter+1);
}
 
int _putchar(char c)
{
  return (write(1,&c,1));
}

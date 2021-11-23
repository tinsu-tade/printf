#include <stdio.h>
#include "main.h"
#include<stdarg.h>
#include<unistd.h>
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
  /* int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    */
    /* _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);*/
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    /* _printf("Address:[%p]\n", addr);
       printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
     _printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);*/
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}
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

/**
 *#ifndef PRINT_F
#define PRINT_F

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>


 * struct convert - defines a structure for symbols and functions
 *
 * @sym: The operator
 * @f: The function associated
 *struct convert
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convert conver_t;

*Main functions*
int parser(const char *format, conver_t f_list[], va_list arg_list);
int _printf(const char *format, ...);
int _write_char(char);
int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);
int print_integer(va_list);
int print_number(va_list);
int print_binary(va_list);
int print_reversed(va_list arg);
*int rot13(va_list);*
int unsigned_integer(va_list);
int print_octal(va_list list);
int print_hex(va_list list);
int print_heX(va_list list);

Helper functions
unsigned int base_len(unsigned int, int);
char *rev_string(char *);
void write_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
int print_unsgined_number(unsigned int);


#endif
*/

#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/**
 * * struct types_arguments - Struct op
 * *
 * * @t: The operator
 * * @f: The function associated
 * */
typedef struct types_arguments
{
		char t;
			int (*f)(va_list va);
} types;
int _putchar(char c);
int _strlen(char *s);
int print_number(va_list va);
int binary(va_list va);
int print_unsigned(va_list va);
int hexa(va_list va);
int hexa_upper(va_list va);
int octal(va_list va);
int print_rot(va_list va);
char *malloc_str(char *str);
char *rot13(char *p);
int print_rev(va_list va);
int hexa_special(unsigned int c);
int stringhexa(va_list va);
int pointer(va_list va);
int hexa_pointer(unsigned long int c);
int _printf(const char *format, ...);
int t_char(va_list va);
int t_string(va_list va);
int print_number(va_list va);

/* function to handle other specifiers */                                                                    

int get_flags(const char *format, int *i);                                                                   

int get_width(const char *format, int *i, va_list list);                                                     

int get_precision(const char *format, int *i, va_list list);                                                
int get_size(const char *format, int *i); 

#endif

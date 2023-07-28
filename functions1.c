#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned – To be printing an unsigned number
 * @types: Arguments list a
 * @buffer: Print is handled by buffer array 
 * @flags:  To calculate flags that are active
 * @width: obtain width
 * @precision: Precision specification
 * @size: The size specifier
 * Return: The number of characters printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 10) + '0';
		num /= 10;
	}

	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal – adopts octal notation to prints an unsigned number
 * @types: Arguments list a
 * @buffer: Print is handled by buffer array 
 * @flags:  To calculate flags that are active
 * @width: obtain width
 * @precision: Precision specification
 * @size: The size specifier
 * Return: The number of characters printed.
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[a--] = '0';

	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal – uses hexadecimal notation to prints an unsigned number
 * @types: Arguments list a
 * @buffer: Print is handled by buffer array 
 * @flags:  To calculate flags that are active
 * @width: obtain width
 * @precision: Precision specification
 * @size: The size specifier
 * Return: The number of characters printed.
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper – Printing an unsigned number in the form upper hexadecimal notation
 * @types: Arguments list a
 * @buffer: Print is handled by buffer array 
 * @flags:  To calculate flags that are active
 * @width: obtain width
 * @precision: Precision specification
 * @size: The size specifier
 * Return: The number of characters printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Printing a hexadecimal number in the form lower or upper
 * @types: arguments list a
 * @map_to: mapping the number to using array of values
 * @buffer: Print is handled by buffer array 
 * @flags:  To calculate flags that are active
 * @flag_ch: To calculate flags that are active
 * @width: obtain width
 * @precision: Precision specification
 * @size: The size specifier
 * @size: The size specification
 * Return: The number of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[a--] = flag_ch;
		buffer[a--] = '0';
	}

	a++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

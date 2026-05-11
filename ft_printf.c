/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pride-ol <pride-ol@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/04 10:31:08 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/05/11 17:53:50 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(va_list args, char format)
{
	unsigned long	address;

	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (format == '%')
		return (ft_putchar('%'));
	if (format == 'p')
	{
		address = (unsigned long)va_arg(args, void *);
		if (!address)
			return (ft_putstr("(nil)"));
		return (ft_putstr("0x") + ft_puthex(address, "0123456789abcdef"));
	}
	if (format == 'u')
		return (ft_unsigned_putnbr(va_arg(args, unsigned int)));
	if (format == 'x')
		return (ft_puthex(va_arg(args, unsigned int), "0123456789abcdef"));
	if (format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			length += check_format(args, format[i + 1]);
			i++;
		}
		else
			length += ft_putchar(format[i]);
		i++;
	}
	return (length);
}

/*#include <stdio.h>
#include <limits.h>

int main(void)
{
    int mine;
    int original; 
   
    printf("1. Char (%%c):\n");
    mine = ft_printf("  Mine: [%c]\n", 'G');
    original = printf("  Orig: [%c]\n", 'G');
    printf("  Return -> Mine: %d | Orig: %d\n\n", mine, original);
   
    printf("2. String (%%s):\n");
    mine = ft_printf("  Mine: [%s]\n", "Priscila 42");
    original = printf("  Orig: [%s]\n", "Priscila 42");
    printf("  Return -> Mine: %d | Orig: %d\n\n", mine, original);

	char *s2 = NULL;
	mine = ft_printf("  Mine: [%s]\n", s2);
    original = printf("  Orig: [%s]\n", s2);
    printf("  Return -> Mine: %d | Orig: %d\n\n", mine, original);
   
    printf("3. Pointer (%%p):\n");
    void *ptr = &mine;
	void *nil_prt = NULL;
    mine = ft_printf("  Mine: [%p]\n", ptr);
    original = printf("  Orig: [%p]\n", ptr);
    printf("  Return -> Mine: %d | Orig: %d\n\n", mine, original);

	mine = ft_printf("  Mine: [%p]\n", nil_prt);
    original = printf("  Orig: [%p]\n", nil_prt);
    printf("  Return -> Mine: %d | Orig: %d\n\n", mine, original);
   
    printf("4. Int (%%d e %%i):\n");
    mine = ft_printf("  Mine: [%d] [%i]\n", INT_MIN, 42);
    original = printf("  Orig: [%d] [%i]\n", INT_MIN, 42);
    printf("  Return -> Mine: %d | Orig: %d\n\n", mine, original);
   
    printf("5. Unsigned (%%u):\n");
    mine = ft_printf("  Mine: [%u]\n", 4294967295U);
    original = printf("  Orig: [%u]\n", 4294967295U);
    printf("  Return -> Mine: %d | Orig: %d\n\n", mine, original);
   
    printf("6. Hexa Lower (%%x):\n");
    mine = ft_printf("  Mine: [%x]\n", 255);
    original = printf("  Orig: [%x]\n", 255);
    printf("  Return -> Mine: %d | Orig: %d\n\n", mine, original);
   
    printf("7. Hexa Upper (%%X):\n");
    mine = ft_printf("  Mine: [%X]\n", 255);
    original = printf("  Orig: [%X]\n", 255);
    printf("  Return -> Mine: %d | Orig: %d\n\n", mine, original);
  
    printf("8. Percentage (%%%%):\n");
    mine = ft_printf("  Mine: [%%]\n");
    original = printf("  Orig: [%%]\n");
    printf("  Return -> Mine: %d | Orig: %d\n\n", mine, original);
    return (0);
}*/

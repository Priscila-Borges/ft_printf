/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pride-ol <pride-ol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/11 22:15:38 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/05/12 22:44:11 by pride-ol      ########   odam.nl         */
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

	if (!format)
		return (0);
	i = 0;
	length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			length += check_format(args, format[i + 1]);
			i++;
		}
		else if (format[i] != '%')
			length += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (length);
}

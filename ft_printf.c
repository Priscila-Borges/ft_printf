/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pride-ol <pride-ol@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/04 10:31:08 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/05/10 22:47:47 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(va_list args, const char format)
{
	int		length;
	char	*str
	
	length = 0;
	if (format == 'c')
	{
		ft_putchar_fd(va_arg(arg, int), 1);
		length = 1;
	}		
	else if (format == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			str = (null);
		ft_putstr_fd(str, 1);
		length = ft_strlen(str);
	}		
	else if (format == 'd' || format == 'i')
	{
		ft_putnbr_fd(va_arg(args, int), 1);
	}
	else if (format == '%')
	{
		ft_putchar_fd('%', 1);
		length = 1;
	}		
	return (length);
}

int ft_printf(const char *str, ...)
{
	va_list args;
	int		i;
	int		length;
	
	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += check_format(args, str[i +1 ]);
			i++;
		}
		else
			length += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (length);	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pride-ol <pride-ol@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/11 13:14:31 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/05/11 16:27:15 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	length;

	length = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		length += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		length += ft_putnbr(n / 10);
	length += ft_putchar((n % 10) + '0');
	return (length);
}

int	ft_unsigned_putnbr(unsigned int n)
{
	int	length;

	length = 0;
	if (n >= 10)
		length += ft_unsigned_putnbr(n / 10);
	length += ft_putchar((n % 10) + '0');
	return (length);
}

int	ft_puthex(unsigned long n, char *base)
{
	int	length;

	length = 0;
	if (n >= 16)
		length += ft_puthex((n / 16), base);
	length += ft_putchar(base[n % 16]);
	return (length);
}

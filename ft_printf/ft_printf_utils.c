/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 07:02:30 by mazhari           #+#    #+#             */
/*   Updated: 2021/12/03 15:10:48 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *str, int *len)
{
	if (str)
	{
		while (*str)
			ft_putchar(*str++, len);
	}
	else
		ft_putstr("(null)", len);
}

void	ft_putnbr(int n, int *len)
{
	unsigned int	i;

	if (n < 0)
	{
		ft_putchar('-', len);
		i = -n;
	}
	else
		i = n;
	if (i <= 9)
	{
		ft_putchar(i + '0', len);
	}
	else
	{
		ft_putnbr(i / 10, len);
		ft_putnbr(i % 10, len);
	}
}

void	ft_putunsigned(unsigned int n, int *len)
{
	if (n <= 9)
	{
		ft_putchar(n + '0', len);
	}
	else
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
}

void	ft_puthexa(const char format, unsigned long n, int *len)
{
	char	*hex;

	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n < 16)
		ft_putchar(hex[n], len);
	else
	{
		ft_puthexa(format, n / 16, len);
		ft_puthexa(format, n % 16, len);
	}
}

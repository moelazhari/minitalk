/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:04:56 by mazhari           #+#    #+#             */
/*   Updated: 2022/02/14 17:43:56 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long n, int *len)
{
	ft_putnbr(n, len);
}

void	ft_print1(const char format, va_list ptr, int *len)
{	
	if (format == 'c')
		ft_putchar(va_arg(ptr, int), len);
	if (format == 's')
		ft_putstr(va_arg(ptr, char *), len);
	if (format == 'p')
		ft_putptr(va_arg(ptr, unsigned long), len);
	if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(ptr, int), len);
	if (format == 'u')
		ft_putunsigned(va_arg(ptr, int), len);
	if (format == 'x' || format == 'X')
		ft_puthexa(format, va_arg(ptr, unsigned int), len);
	if (format == '%')
		ft_putchar(format, len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		len;
	int		i;

	va_start(ptr, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i], &len);
		else
			ft_print1(format[++i], ptr, &len);
		i++;
	}
	va_end(ptr);
	return (len);
}
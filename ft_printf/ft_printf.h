/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:11:10 by mazhari           #+#    #+#             */
/*   Updated: 2021/12/03 15:13:47 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(int c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putptr(unsigned long n, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putunsigned(unsigned int n, int *len);
void	ft_puthexa(const char format, unsigned long n, int *len);

#endif

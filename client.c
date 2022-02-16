/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:13:38 by mazhari           #+#    #+#             */
/*   Updated: 2022/02/16 19:20:50 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"

static void check_digit(char *s)
{
	int i;
	
	i = -1;
	while (s[++i])
	{
		if (s[i] < '0' || s[i] > '9')
		{
			ft_printf("pid must be a number\n");
			exit (1);
		}
	}
}

static int	ft_atoi(const char *str)
{
	int	rus;
	int	i;

	i = 0;
	rus = 0;

	while (str[i] >= '0' && str[i] <= '9')
	{
		rus = (rus * 10) + ((int)str[i] - '0');
		i++;
	}	
	return (rus);
}

void send_signal(int pid, char *msg)
{
	int	i;
	int	bit;
	
	i = -1;
	while (msg[++i])
	{
		bit = 8;
		while (bit--)
		{
			if ((msg[i] >> bit) & 1)
			{
				if (kill(pid, SIGUSR1) == -1)
				{
					ft_printf("pid not found\n");
					exit(1);
				}
			}
			else
				if (kill(pid, SIGUSR2) == -1)
				{
					ft_printf("pid not found\n");
					exit(1);
				}
			usleep(700);
		}
	}
}

int main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{	
		ft_printf("./client [pid] [message]\n");
		return (0);
	}
	check_digit(av[1]);
	pid = ft_atoi(av[1]);
	send_signal(pid, av[2]);
	return (0);
}

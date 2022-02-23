/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:13:38 by mazhari           #+#    #+#             */
/*   Updated: 2022/02/22 16:09:12 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "../ft_printf/ft_printf.h"

static int	ft_atoi(const char *s)
{
	int	rus;
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] < '0' || s[i] > '9')
		{
			ft_printf("pid must be a positive number\n");
			exit (1);
		}
	}
	i = 0;
	rus = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		rus = (rus * 10) + ((int)s[i] - '0');
		i++;
	}	
	return (rus);
}

void	send_signal(int pid, int sing)
{
	if (sing == SIGUSR1)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_printf("pid not found\n");
			exit(1);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf("pid not found\n");
			exit(1);
		}
	}
}

void	send_char(int pid, char *msg)
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
				send_signal(pid, SIGUSR1);
			else
				send_signal(pid, SIGUSR2);
			usleep(800);
		}
	}
	bit = 8;
	while (bit)
	{
		send_signal(pid, SIGUSR2);
		usleep(800);
		bit--;
	}
}

void	sighandler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("\nmessage received\n\n");
}

int	main(int ac, char **av)
{
	int	pid;

	signal(SIGUSR1, sighandler);
	if (ac != 3)
	{	
		ft_printf("./client [pid] [message]\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	send_char(pid, av[2]);
	return (0);
}

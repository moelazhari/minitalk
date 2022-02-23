/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:22:37 by mazhari           #+#    #+#             */
/*   Updated: 2022/02/22 16:09:45 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "../ft_printf/ft_printf.h"

static void	sighandler(int sig, siginfo_t *info, void *str)
{
	static int	c = 0;
	static int	bit = 0;
	static int	client = 0;

	(void)str;
	if (client != info->si_pid)
	{
		c = 0;
		bit = 0;
		client = info->si_pid;
	}
	c = (c << 1) | (sig == SIGUSR1);
	bit++;
	if (bit == 8)
	{
		if (c == 0)
			kill(info->si_pid, SIGUSR1);
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	signal;
	int					pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	signal.sa_sigaction = &sighandler;
	while (1)
	{
		sigaction(SIGUSR1, &signal, NULL);
		sigaction(SIGUSR2, &signal, NULL);
		pause();
	}
	return (0);
}

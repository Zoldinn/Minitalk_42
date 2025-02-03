/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:18:02 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/03 16:38:40 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_received_ack;

void	ack_handler(int signum, siginfo_t *info, void *context)
{
	(void) context;
	(void) info;
	if (signum == SIGUSR1)
		g_received_ack = 1;
	else if (signum == SIGUSR2)
		ft_printf("finished\n");
}

void	wait_sig(void)
{
	while (!g_received_ack)
	{
	}
	g_received_ack = 0;
}

void	send_sig(int pid, char *str)
{
	int	bit;
	int	i;

	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			bit = (*str >> i) & 1;
			if (bit)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			--i;
			wait_sig();
		}
		str++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR2);
		wait_sig();
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		write(2, "\e[31mError, format : ./client <PID> \"msg\"\n\e[0m", 46);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	if (kill(pid, 0) == -1)
	{
		write(2, "\e[31mError, wrong PID\n\e[0m", 26);
		exit(EXIT_FAILURE);
	}
	if (!*av[2])
		exit(EXIT_SUCCESS);
	set_sigaction(ack_handler, 3);
	send_sig(pid, av[2]);
	exit(EXIT_SUCCESS);
}

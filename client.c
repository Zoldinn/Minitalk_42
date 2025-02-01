/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:18:02 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/31 17:23:03 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	received_ack;

void	ack_handler(int signum)
{
	if (signum == SIGUSR1)
		received_ack = 1;
	else if (signum == SIGUSR2)
		ft_printf("finished\n");
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
			{
				// ft_printf("SIGUSR1 (1) send\n");
				kill(pid, SIGUSR1); // 1
			}
			else
			{
				// ft_printf("SIGUSR2 (0) send\n");
				kill(pid, SIGUSR2); // 0
			}
			--i;
			while (!received_ack)
			{
			}
			received_ack = 0;

		}
		str++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR2);
		while (!received_ack)
		{
		}
		received_ack = 0;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write(2, "\e[31mError, format : ./client <Server PID> \"message\"\n\e[0m", 57);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, ack_handler);
	signal(SIGUSR2, ack_handler);
	send_sig(ft_atoi(av[1]), av[2]);
	exit(EXIT_SUCCESS);
}

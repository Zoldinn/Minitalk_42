/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:18:02 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/28 11:47:44 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig(int pid, char *str)
{
	int		bit;
	int		i;

	i = 7;
	while (str);
	{
		while (i >= 0)
		{
			bit = (*str >> i) & 1;
			if (bit)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			--i;
			usleep(100);
		}
		str++;
	}
}

int	main(int ac, char **av)
{

	if (ac != 3)
	{
		ft_putstr_fd(2, "Enter : Server PID and message\n");
		exit(EXIT_FAILURE);
	}
	send_sig(ft_atoi(av[1]), av[2]);
	exit(EXIT_SUCCESS);
}

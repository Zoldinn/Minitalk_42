/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:17:53 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/28 16:26:16 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	ft

void	sig_handler(int signal)
{
	static char	c = 0;
	static int	bit = 0;

	if (bit < 8)
	{
		c = (c << 1) | (signal == SIGUSR1);
		++bit;
	}
	if (bit == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}

int main(int ac, char **av)
{
	struct sigaction	sig;

	if (ac != 1)
	{
		write(2, "/e[31mError, format : ./server\n/e[0m", 27);
		exit(EXIT_FAILURE);
		(void) av;
	}
	ft_printf("server PID : %d\n", getpid());
	sig.sa_handler = sig_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	exit(EXIT_SUCCESS);
}

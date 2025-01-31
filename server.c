/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:17:53 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/31 17:23:06 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*str = NULL;

void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit = 0;

	(void) context;
	if (bit < 8)
	{
		c = (c << 1) | (signal == SIGUSR1);
		++bit;
		// ft_printf("Bit received: %d (signal: %s)\n", bit, signal == SIGUSR1 ? "SIGUSR1" : "SIGUSR2");
	}
	if (bit == 8)
	{
		if (c == 0 && str)
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
			kill(info->si_pid, SIGUSR2);
		}
		else
		{
			str = ft_addchar(str, c);
			if (!str)
			{
				cleanup(str);
				return ;
			}
		}
		c = 0;
		bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int main(int ac, char **av)
{
	if (ac != 1)
	{
		write(2, "\e[31mError, format : ./server\n\e[0m", 34);
		exit(EXIT_FAILURE);
		(void) av;
	}
	ft_printf("server PID : %d\n", getpid());
	set_sigaction(&sig_handler, 3);
	while (1)
		pause();
	free(str);
	exit(EXIT_SUCCESS);
}

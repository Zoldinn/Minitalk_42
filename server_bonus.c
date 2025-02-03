/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:17:53 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/03 16:10:01 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*g_str = NULL;

void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit = 0;

	(void) context;
	c = (c << 1) | (signal == SIGUSR1);
	bit++;
	if (bit == 8)
	{
		if (c == 0 && g_str)
		{
			ft_printf("%s\n", g_str);
			free(g_str);
			g_str = NULL;
			kill(info->si_pid, SIGUSR2);
		}
		else
		{
			g_str = ft_addchar(g_str, c);
			if (!g_str)
				return ;
		}
		c = 0;
		bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int ac, char **av)
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
	free(g_str);
	exit(EXIT_SUCCESS);
}

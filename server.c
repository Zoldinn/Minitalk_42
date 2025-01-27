/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:17:53 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/27 17:11:32 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	get_sig(int signal)
{
	if (signal == SIGUSR1)
		return (0);
	else if (signal == SIGUSR2)
		return (1);
	return (-1);
}



int main(void)
{
	ft_printf("server PID : %d\n", getpid());
	exit(EXIT_SUCCESS)
}
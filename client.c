/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:18:02 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/27 18:17:03 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_putstr_fd(2, "Enter : Server PID and message\n");
		exit(EXIT_FAILURE);
	}
	
	exit(EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:17:53 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/28 11:51:49 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(void)
{
	ft_printf("server PID : %d\n", getpid());
	while (1)
		pause();
	exit(EXIT_SUCCESS)
}
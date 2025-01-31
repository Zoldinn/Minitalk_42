/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:33:31 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/31 15:42:09 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *nptr);
int		ft_strlen(char *str);
char	*ft_addchar(char *str, char c);
void	cleanup(char *str);
void	set_sigaction(void (*handler)(int, siginfo_t*, void*), int sigusr);

#endif
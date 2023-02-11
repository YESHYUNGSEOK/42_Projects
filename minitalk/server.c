/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:45:06 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/01/09 14:56:01 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_sig(int sig)
{
	static int	bit;
	static char	byte;

	if (sig == SIGUSR1)
		byte |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &byte, 1);
		bit = 0;
		byte = 0;
	}
}

int	main(int ac, char **av)
{
	int	server_pid;

	(void)av;
	if (ac == 1)
	{
		server_pid = getpid();
		ft_putstr_fd("server pid: ", 1);
		ft_putnbr_fd(server_pid, 1);
		ft_putstr_fd("\n", 1);
		signal(SIGUSR1, get_sig);
		signal(SIGUSR2, get_sig);
		while (1)
			pause();
	}
	else
		return (1);
	return (0);
}

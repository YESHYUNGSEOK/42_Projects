/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:03:47 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/01/09 14:50:52 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig(char c, int server_pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & 1) == 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		c >>= 1;
		bit++;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int		server_pid;
	int		i;
	char	c;

	if (ac == 3)
	{
		server_pid = ft_atoi(av[1]);
		i = -1;
		while (av[2][++i])
		{
			c = av[2][i];
			send_sig(c, server_pid);
			usleep(100);
		}
		send_sig('\n', server_pid);
		usleep(100);
	}
	else
		return (1);
	return (0);
}

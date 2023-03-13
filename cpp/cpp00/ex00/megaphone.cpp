/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:20:35 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/03/13 13:26:36 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (++i < ac)
		{
			j = -1;
			while (av[i][++j])
				av[i][j] = toupper(av[i][j]);
			if (i == ac - 1)
				std::cout << av[i] << std::endl;
			else
				std::cout << av[i];
		}
	}
	return (0);
}

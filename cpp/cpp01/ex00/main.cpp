/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:49:36 by hyungseok         #+#    #+#             */
/*   Updated: 2023/12/14 15:39:15 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main(void)
{
	Zombie* zombie = newZombie("heapZombie");
	zombie->announce();
	randomChump("stackZombie");
	delete zombie;
	return (0);
}
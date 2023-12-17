/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:49:36 by hyungseok         #+#    #+#             */
/*   Updated: 2023/12/16 20:16:20 by hyungseok        ###   ########.fr       */
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
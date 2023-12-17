/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:49:36 by hyungseok         #+#    #+#             */
/*   Updated: 2023/12/16 20:27:39 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *zombies = zombieHorde(10, "zombie");
    Zombie zombie;
    for (int i = 0; i < 10; i++)
        zombies[i].announce();

    zombie.announce();
    delete[] zombies;        

    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:49:36 by hyungseok         #+#    #+#             */
/*   Updated: 2023/12/12 19:15:49 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *zombies = zombieHorde(10, "cadet");

    for (int i = 0; i < 10; i++)
        zombies[i].announce();

    delete[] zombies;        

    return (0);
}
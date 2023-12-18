/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:10:05 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/18 16:17:00 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

int main()
{
    FragTrap A("A");
    FragTrap B("B");
    
    A.attack("B");
    B.takeDamage(30);
    B.beRepaired(30);
    A.highFivesGuys();

    return (0);
}
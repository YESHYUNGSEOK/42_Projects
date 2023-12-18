/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:10:05 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/18 16:18:21 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

int main()
{
    ScavTrap a("A");
    ScavTrap b("B");

    a.attack("B");
    b.takeDamage(20);

    b.attack("A");
    a.takeDamage(20);

    a.beRepaired(20);
    
    a.guardGate();
    b.guardGate();
	
    return (0);
}
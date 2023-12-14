/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:10:05 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/14 14:40:14 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

int main()
{
    ScavTrap a("jusohn");
    ScavTrap b("soul");
    ScavTrap c("song_pd");

    a.attack("soul");
    b.takeDamage(20);

    b.attack("jusohn");
    a.takeDamage(20);

    a.beRepaired(50);
    
    a.attack("soul");
    b.takeDamage(20);
    
    b.attack("jusohn");
    a.takeDamage(20);
    
    a.attack("soul");
    b.takeDamage(20);
    
    b.attack("jusohn");
    a.takeDamage(20);
    
    a.attack("soul");
    b.takeDamage(20);
    
    b.attack("jusohn");
    a.takeDamage(20);
    
    a.attack("soul");
    b.takeDamage(20);
    
    b.attack("jusohn");
    a.takeDamage(20);
    
    a.attack("soul");
    b.takeDamage(20);
    
    b.attack("jusohn");
    a.takeDamage(20);
    
    a.attack("soul");
    b.takeDamage(20);
    
    b.attack("jusohn");
    a.takeDamage(20);
    
    a.beRepaired(50);
    
    a.attack("soul");
    b.takeDamage(20);

    b.attack("jusohn");
    a.takeDamage(20);
    
    a.guardGate();
    b.guardGate();
    c.guardGate();
	
    return (0);
}
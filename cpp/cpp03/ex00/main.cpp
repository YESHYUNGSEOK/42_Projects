/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:10:05 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/14 14:04:23 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

int main()
{
	ClapTrap a("A");
	ClapTrap b("B");
	
	a.attack("B");
	b.takeDamage(-1);
	b.beRepaired(3);
	b.attack("A");
	a.takeDamage(10);
	a.beRepaired(10);
	
	return (0);
}
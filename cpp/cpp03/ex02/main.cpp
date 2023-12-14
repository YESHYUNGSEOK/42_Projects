/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:10:05 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/14 14:51:55 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

int main()
{
    FragTrap jusohnTrap("jusohn");
    FragTrap copycat(jusohnTrap);
    FragTrap tmpTrap;
    tmpTrap = copycat;

    jusohnTrap.attack("song_pd");
    jusohnTrap.takeDamage(10);
    
    jusohnTrap.beRepaired(10);

    jusohnTrap.highFivesGuys();
    copycat.highFivesGuys();
    tmpTrap.highFivesGuys();
    return (0);
}
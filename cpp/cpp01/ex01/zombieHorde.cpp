/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:49:14 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/17 14:49:15 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
  std::stringstream stringStream;
  Zombie *zombies = new Zombie[N];

  for (int i = 0; i < N; i++) {
    stringStream.str(std::string());
    stringStream << i + 1;
    zombies[i].setName(name + "_" + stringStream.str());
  }
  return zombies;
}

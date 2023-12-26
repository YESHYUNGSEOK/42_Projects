/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:32:08 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/26 10:15:59 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	meta->makeSound();
	i->makeSound();
	j->makeSound();

	delete meta;
	delete i;
	delete j;


	const WrongAnimal* k = new WrongAnimal();
	const WrongAnimal* z = new WrongCat();

	k->makeSound();
	z->makeSound();

	delete k;
	delete z;
	
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:32:08 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/26 10:22:50 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Dog.hpp"
# include "Cat.hpp"

int main(void)
{
	Dog *dog = new Dog();
	Cat *cat = new Cat();
	std::string str;
	
	for (int i = 0; i < 10; i++)
		dog->getBrain().setIdea(i, "Dog's idea");
	for (int i = 0; i < 10; i++)
		cat->getBrain().setIdea(i, "Cat's idea");

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			str = cat->getBrain().getIdeas(i);
		else
			str = dog->getBrain().getIdeas(i);
		std::cout << str << std::endl;
	}

	delete dog;
	delete cat;
	
	return(0);
}
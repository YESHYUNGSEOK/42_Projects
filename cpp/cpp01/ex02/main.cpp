/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:16:54 by hyungseok         #+#    #+#             */
/*   Updated: 2023/12/16 20:36:40 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *brainPtr = &brain;
	std::string &brainRef = brain;

	std::cout << "address of brain: " << &brain << std::endl;
	std::cout << "address of brainPtr: " << brainPtr << std::endl;
	std::cout << "address of brainRef: " << &brainRef << std::endl;

	std::cout << "value of brain: " << brain << std::endl;
	std::cout << "value of brainPtr: " << *brainPtr << std::endl;
	std::cout << "value of brainRef: " << brainRef << std::endl;
	
	return (0);
}
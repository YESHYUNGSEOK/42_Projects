/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:33:24 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/13 11:13:44 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	while (!std::cin.eof())
	{
		std::cout << "Please enter phonebook command (ADD, SEARCH, EXIT)" << std::endl;
		std::getline(std::cin, command);
        if (command == "EXIT" || std::cin.eof())
		{
			std::cin.clear();
			std::clearerr(stdin);
            break ;
		}
		else if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.showContactList();
		else
			std::cout << "Invalid command" << std::endl;
	}
	
	return (0);
}
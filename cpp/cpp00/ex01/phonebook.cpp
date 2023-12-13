/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:16:43 by hyungseok         #+#    #+#             */
/*   Updated: 2023/12/13 11:12:21 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"
# include <iomanip>

# define MAX_INDEX 8

PhoneBook::PhoneBook()
{
	this->index = 0;
	this->contactCount = 0;
	std::cout << "PhoneBook is opened" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook is closed" << std::endl;
}

std::string PhoneBook::getNonEmptyInput(std::string requiredInput)
{
	std::string input;
	
	do {
		std::cout << requiredInput;
		std::getline(std::cin, input);
		if (std::cin.eof())
    	{
			std::cout << std::endl;
			std::cin.clear();
			std::clearerr(stdin);
			continue;
    	}
	} while (input.empty());
	
	return input;
}

void PhoneBook::addContact()
{
	std::string command;
	
	if (this->index >= MAX_INDEX)
		this->index = 0;
    
    this->contact[this->index].setFirstName(this->getNonEmptyInput("first name: "));
    this->contact[this->index].setLastName(this->getNonEmptyInput("last name: "));
    this->contact[this->index].setNickname(this->getNonEmptyInput("nickname: "));
    this->contact[this->index].setPhoneNumber(this->getNonEmptyInput("phone number: "));
    this->contact[this->index].setDarkestSecret(this->getNonEmptyInput("darkest secret: "));
	
	this->index++;
	if (this->contactCount < MAX_INDEX)
		this->contactCount++;
}

void PhoneBook::showContactList()
{
	std::string index;
	
	if (this->contactCount == 0)
    {
        std::cout << "phonebook is empty" << std::endl;
        return ;
    }
	
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < this->contactCount; i++)
	{
		std::cout << std::setw(10) << i << "|";
		if (this->contact[i].getFirstName().length() > 10)
			std::cout << std::setw(10) << this->contact[i].getFirstName().substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << this->contact[i].getFirstName() << "|";
		if (this->contact[i].getLastName().length() > 10)
			std::cout << std::setw(10) << this->contact[i].getLastName().substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << this->contact[i].getLastName() << "|";
		if (this->contact[i].getNickname().length() > 10)
			std::cout << std::setw(10) << this->contact[i].getNickname().substr(0, 9) + "." << std::endl;
		else
			std::cout << std::setw(10) << this->contact[i].getNickname() << std::endl;
	}
	
	std::cout << "Please enter phonebook index" << std::endl;
	std::getline(std::cin, index);
	if (std::cin.eof())
    {
		std::cout << std::endl;
		std::cin.clear();
		std::clearerr(stdin);
		return;
    }
	if (index.length() != 1)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	this->showContact(index[0] - '0');
}

void PhoneBook::showContact(int index)
{
    if (index < 0 || index >= this->contactCount)
    {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    std::cout << "first name: " << this->contact[index].getFirstName() << std::endl;
    std::cout << "last name: " << this->contact[index].getLastName() << std::endl;
    std::cout << "nickname: " << this->contact[index].getNickname() << std::endl;
    std::cout << "phone number: " << this->contact[index].getPhoneNumber() << std::endl;
    std::cout << "darkest secret: " << this->contact[index].getDarkestSecret() << std::endl;
}
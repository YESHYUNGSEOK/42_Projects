/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:36:57 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/03/14 19:10:49 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstring>

class Contact {
 private:
  std::string FirstName;
  std::string LastName;
  std::string Nickname;
  std::string PhoneNumber;
  std::string DarkSecret;

 public:
  void create(void) {
	std::cout << "First name : ";
	std::getline(std::cin, FirstName);
	std::cout << "Last name : ";
	std::getline(std::cin, LastName);
	std::cout << "Nickname : ";
	std::getline(std::cin, Nickname);
	std::cout << "Phone number : ";
	std::getline(std::cin, PhoneNumber);
	std::cout << "Dark secret : ";
	std::getline(std::cin, DarkSecret);
  }
  void show(void) {
	if (FirstName.size() > 10)
	{
		for (int i = 0; i < 9; i++)
			std::cout << FirstName[i];
		std::cout << '.' << "|";
	}
	else
		std::cout << std::setw(10) << std::right << FirstName << "|";
	if (LastName.size() > 10)
	{
		for (int i = 0; i < 9; i++)
			std::cout << LastName[i];
		std::cout << '.' << "|";
	}
	else
		std::cout << std::setw(10) << std::right << LastName << "|";
	if (Nickname.size() > 10)
	{
		for (int i = 0; i < 9; i++)
			std::cout << Nickname[i];
		std::cout << '.' << std::endl;
	}
	else
		std::cout << std::setw(10) << std::right << Nickname << std::endl;
  }
  void show_specific() {
	std::cout << "First name : " << FirstName << std::endl;
	std::cout << "Last name : " << LastName << std::endl;
	std::cout << "Nickname : " << Nickname << std::endl;
	std::cout << "Phone number : " << PhoneNumber << std::endl;
	std::cout << "Dark secret : " << DarkSecret << std::endl;
  }
};

class PhoneBook {
 private:
  Contact contact[8];

 public:
  void add(int idx, Contact contact_) {
	contact[idx] = contact_;
  }
  void show(int cnt) {
	std::string	idx;
	int			idx_;

	if (cnt > 8)
		cnt = 8;
	if (cnt)
	{
		std::cout << std::setw(10) << std::right << "Index" << "|";
		std::cout << std::setw(10) << std::right << "First name" << "|";
		std::cout << std::setw(10) << std::right << "Last name" << "|";
		std::cout << std::setw(10) << std::right << "Nickname" << std::endl;
		for (int i = 0; i < cnt; i++)
		{
			std::cout << std::setw(10) << std::right << i + 1 << "|";
			contact[i].show();
		}
		std::cout << "Please input an index : ";
		std::getline(std::cin, idx);
		if (idx.size() == 1 && idx[0] >= '1' && idx[0] <= '8' && idx[0] <= cnt + '0')
		{
			idx_ = std::stoi(idx) - 1;
			contact[idx_].show_specific();
		}
		else
			std::cout << "Inappropriate index." << std::endl;
	}
	else
		std::cout << "Phonebook's not been updated." << std::endl;
  }
};

#endif
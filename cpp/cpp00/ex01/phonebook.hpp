/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:36:57 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/12 13:26:58 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	private:
		Contact contact[8];
		int		index;
		int		contactCount;
		
		std::string getNonEmptyInput(std::string requiredInput);
	public:
		PhoneBook();
		~PhoneBook();
		void addContact();
		void showContactList();
		void showContact(int index);
};

#endif
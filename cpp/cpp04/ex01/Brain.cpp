/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:30:12 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/18 18:29:50 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain] Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "";
}

Brain::~Brain()
{
	std::cout << "[Brain] Destructor called" << std::endl;
}

Brain::Brain(const Brain &source)
{
	std::cout << "[Brain] Copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = source.ideas[i];
}

Brain	&Brain::operator=(const Brain &source)
{
	std::cout << "[Brain] Assignment operator called" << std::endl;
	if (this == &source)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = source.ideas[i];
	return (*this);
}

void Brain::setIdea(int i, std::string idea)
{
	if (i < 0 || i >= 100)
		return ;
	this->ideas[i] = idea;
}

std::string Brain::getIdeas(int i) const
{
	if (i < 0 || i >= 100)
		return ("");
	return (this->ideas[i]);
}
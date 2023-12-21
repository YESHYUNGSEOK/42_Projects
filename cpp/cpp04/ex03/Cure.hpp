/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:23:46 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/20 11:34:06 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include <iostream>

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure & source);
		~Cure();
		Cure & operator = (const Cure & source);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:12:20 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/20 10:12:43 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* inventory[4];
		int count;
	public:
		MateriaSource();
		MateriaSource(const MateriaSource & source);
		~MateriaSource();
		MateriaSource & operator = (const MateriaSource & source);

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif
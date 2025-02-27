/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:25:52 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/27 12:56:36 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*_memory[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &source);
	~MateriaSource();
	MateriaSource & operator=(const MateriaSource &source);

	void learnMateria(AMateria* materia);
	AMateria* createMateria(std::string const & type);
};

#endif

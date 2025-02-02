/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:19:30 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/02 16:34:04 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"


MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		_memory[i] = nullptr;
	}
}

MateriaSource::~MateriaSource() {}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i] == nullptr)
		{
			_memory[i] = materia->clone();
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i] != nullptr && _memory[i]->getType() == type)
		{
			return (_memory[i]->clone());
		}
	}
	std::cout << "createMateria(): couldnt" << std::endl;
	return (0);
}

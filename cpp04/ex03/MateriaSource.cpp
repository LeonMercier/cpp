/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:19:30 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/20 15:57:09 by lemercie         ###   ########.fr       */
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

MateriaSource::MateriaSource(const MateriaSource &source)
{
	for (int i = 0; i < 4; i++)
	{
		if (source._memory[i] != nullptr)
		{
			_memory[i] = source._memory[i]->clone();
		}
		else
		{
			_memory[i] = nullptr;
		}
	}
}

// learnMateria() calls clone() which uses new. Therefore all materias learned
// are on the heap
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i] != nullptr)
		{
			delete _memory[i];
		}
	}
}

MateriaSource & MateriaSource::operator=(const MateriaSource &source)
{
	if (this == &source)
	{
		return (*this);
	}
	for (int i = 0; i < 4; i++)
	{
		if (source._memory[i] != nullptr)
		{
			_memory[i] = source._memory[i]->clone();
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (materia == nullptr)
	{
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i] == nullptr)
		{
			_memory[i] = materia->clone();
			return ;
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

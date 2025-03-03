/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:57:34 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/03 17:27:39 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Default name")
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = nullptr;
	}
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = nullptr;
	}
}

// Why would we delete stuff during a copy? Probably the assignement means
// copy assignement
Character::Character(const Character &source) : _name(source._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (source._inventory[i] != nullptr)
		{
			_inventory[i] = source._inventory[i]->clone();
		}
		else
		{
			_inventory[i] = nullptr;
		}
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != nullptr)
		{
			delete _inventory[i];
		}
	}
}

Character & Character::operator=(const Character &source)
{
	if (this != &source)
	{
		_name = source._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i] != nullptr)
			{
				delete _inventory[i];
			}
			if (source._inventory[i] != nullptr)
			{
				_inventory[i] = source._inventory[i]->clone();
			}
			else
			{
				_inventory[i] = nullptr;
			}
		}
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == nullptr)
		{
			_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (_inventory[idx] != nullptr)
	{
		_inventory[idx] = nullptr;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (_inventory[idx] != nullptr)
	{
		_inventory[idx]->use(target);
	}
}

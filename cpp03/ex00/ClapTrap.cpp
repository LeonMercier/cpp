/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:03:31 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/28 12:14:16 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
	_name("default name"),
	_hitpts(10),
	_energypts(10),
	_attackdmg(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
	_name(name),
	_hitpts(10),
	_energypts(10),
	_attackdmg(0)
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source) :
	_name(source._name),
	_hitpts(source._hitpts),
	_energypts(source._energypts),
	_attackdmg(source._attackdmg)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &source)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &source)
	{
		_name = source._name;
		_hitpts = source._hitpts;
		_energypts = source._energypts;
		_attackdmg = source._attackdmg;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitpts == 0)
	{
		std::cout << "ClapTrap " << _name << " has no hitpoints left"
			<< std::endl;
		return ;
	}
	if (_energypts == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy left"
			<< std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target <<
		", causing " << _attackdmg << " points of damage!" << std::endl;
	_energypts--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount == 0)
	{
		return ;
	}
	if (_hitpts == 0)
	{
		std::cout << "ClapTrap " << _name << " is already KO" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount 
		<< " points of damage!" << std::endl;
	if (amount >= _hitpts)
	{
		_hitpts = 0;
		std::cout << "ClapTrap " << _name << " is KO" << std::endl;
	}
	else
	{
		_hitpts -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitpts == 0)
	{
		std::cout << "ClapTrap " << _name << " has no hitpoints left"
			<< std::endl;
		return ;
	}
	if (_energypts == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy left"
			<< std::endl;
		return ;
	}
	if (_hitpts > 0 && _energypts > 0 && amount > 0)
	{
		std::cout << "ClapTrap " << _name << " repairs itself by " << amount
			<< " hitpoints!" << std::endl;
		_hitpts += amount;
		_energypts--;
	}
}

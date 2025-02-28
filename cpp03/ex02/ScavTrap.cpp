/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:18:03 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/28 12:19:19 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default name", 100, 50, 20)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &source) : ClapTrap(source)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &source)
{
	std::cout << "ScavTrap copy assignement operator called" << std::endl;
	if (this != &source)
	{
		this->ClapTrap::operator=(source);
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitpts == 0)
	{
		std::cout << "ScavTrap " << _name << " has no hitpoints left"
			<< std::endl;
		return ;
	}
	if (_energypts == 0)
	{
		std::cout << "ScavTrap " << _name << " has no energy left"
			<< std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target <<
		", causing " << _attackdmg << " points of damage!" << std::endl;
	_energypts--;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name
		<< " is now in Gate keeper mode" << std::endl;
}

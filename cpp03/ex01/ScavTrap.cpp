/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:18:03 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/29 15:00:18 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap constructor called" << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap &source) : ClapTrap(source)
{}

ScavTrap &ScavTrap::operator=(const ScavTrap &source)
{
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

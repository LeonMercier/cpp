/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:28:12 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/30 16:40:38 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// It does not seem possible to inherit the data members as the spirit of the 
// assignement would suggest
DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(name),
	FragTrap(name),
	_name(name)
{
	std::cout << "DiamondTrap constructor called" <<std::endl;
	_hitpts = 100;
	_energypts = 50;
	_attackdmg = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &source) :
	ClapTrap(source),
	ScavTrap(source),
	FragTrap(source),
	_name(source._name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap		&DiamondTrap::operator=(const DiamondTrap &source)
{
	std::cout << "DiamondTrap copy assignement operator called" << std::endl;
	if (this != &source)
	{
		_name = source._name;
		this->ScavTrap::operator=(source);
		this->FragTrap::operator=(source);
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am " << _name << " and also " << ClapTrap::_name
		<< std::endl;
}

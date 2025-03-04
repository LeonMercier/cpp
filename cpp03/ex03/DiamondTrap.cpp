/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:28:12 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/04 10:49:07 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :
	ClapTrap("default_name_clap_name"),
	_name("default_name")
{
	std::cout << "DiamondTrap constructor called" <<std::endl;
	_hitpts = FragTrap::INIT_HITPTS;
	_energypts = ScavTrap::INIT_ENERGYPTS;
	_attackdmg = FragTrap::INIT_ATTCKDMG;
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"),
	_name(name)
{
	std::cout << "DiamondTrap constructor called" <<std::endl;
	_hitpts = FragTrap::INIT_HITPTS;
	_energypts = ScavTrap::INIT_ENERGYPTS;
	_attackdmg = FragTrap::INIT_ATTCKDMG;
}

DiamondTrap::DiamondTrap(const DiamondTrap &source) :
	ClapTrap(source),
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
		this->ClapTrap::operator=(source);
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

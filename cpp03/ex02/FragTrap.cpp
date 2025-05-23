/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:59:33 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/04 10:27:43 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() :
	ClapTrap("default name", INIT_HITPTS, INIT_ENERGYPTS, INIT_ATTCKDMG)
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) :
	ClapTrap(name, INIT_HITPTS, INIT_ENERGYPTS, INIT_ATTCKDMG)
{
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &source) : ClapTrap(source)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &source)
{
	std::cout << "FragTrap copy assignement operator called" << std::endl;
	if (this != &source)
	{
		this->ClapTrap::operator=(source);
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void		FragTrap::highFivesGuys(void)
{
	std::cout << _name << ": I'd like a high five guys please" << std::endl;
}

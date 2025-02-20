/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:41:38 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/20 14:20:07 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice & source) : AMateria(source)
{}

Ice::~Ice() {}

Ice & Ice::operator=(const Ice & source)
{
	if (this != &source)
	{
		AMateria::operator=(source);
	}
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" 
		<< std::endl;
}

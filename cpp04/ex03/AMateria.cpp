/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:37:31 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/25 15:34:44 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {}
AMateria::AMateria(const AMateria &source) : _type(source._type){}
AMateria::~AMateria(){}

AMateria & AMateria::operator=(const AMateria &source)
{
	if (this != &source)
	{
		_type = source._type;
	}
	return (*this);
}

std::string const & AMateria::getType() const
{
	// std::string *asd = new std::string("asd");
	// return (*asd);
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "default action at " << target.getName() << std::endl;
}

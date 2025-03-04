/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:37:31 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/27 12:45:13 by lemercie         ###   ########.fr       */
/*   Updated: 2025/02/20 14:15:45 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default materia") {}
AMateria::AMateria(std::string const & type) : _type(type) {}
AMateria::AMateria(const AMateria &source) : _type(source._type){}
AMateria::~AMateria(){}

AMateria & AMateria::operator=(const AMateria &source)
{
	(void) source;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "default action at " << target.getName() << std::endl;
}

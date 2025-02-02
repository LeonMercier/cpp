/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:37:31 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/02 16:55:49 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {}

// AMateria::~AMateria(){}

std::string const & AMateria::getType() const
{
	// std::string *asd = new std::string("asd");
	// return (*asd);
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	(void) target;
}

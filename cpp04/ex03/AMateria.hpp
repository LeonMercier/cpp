/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:59:19 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/20 14:14:45 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

// class ICharacter;
class AMateria
{
protected:
	std::string	_type;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria &source);
	~AMateria();
	AMateria & operator=(const AMateria &source);
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
#endif

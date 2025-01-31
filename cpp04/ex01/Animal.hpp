/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:14:21 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/31 15:45:18 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <string>
# include <iostream>
# include "Brain.hpp"

class	Animal {
protected:
	std::string	type;
	Brain	*brain;
public:
	Animal();
	Animal(const Animal &source);
	Animal	&operator=(const Animal &source);
	virtual ~Animal();
	virtual void	makeSound(void) const;
	std::string		getType(void) const;
};
#endif

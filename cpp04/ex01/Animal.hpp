/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:14:21 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/27 11:52:38 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <string>
# include <iostream>

class	Animal {
protected:
	std::string	type;
public:
	Animal();
	Animal(const Animal &source);
	Animal	&operator=(const Animal &source);
	virtual ~Animal();
	virtual void	makeSound(void) const;
	virtual std::string		getType(void) const;
};
#endif

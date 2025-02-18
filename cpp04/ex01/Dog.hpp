/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:14:21 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/18 17:48:11 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

# include <string>
# include <iostream>
#include "Animal.hpp"

class	Dog : public Animal {
private:
	std::string	type;
	Brain	*brain;
public:
	Dog();
	Dog(const Dog &source);
	Dog	&operator=(const Dog &source);
	~Dog();
	void	makeSound(void) const;
	std::string	getType(void) const;
};
#endif

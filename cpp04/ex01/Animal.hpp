/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:14:21 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/17 17:40:52 by lemercie         ###   ########.fr       */
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
	void			putThougth(std::string t, int index);
	std::string		getThougth(int index);
};
#endif

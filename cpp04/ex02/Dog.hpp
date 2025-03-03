/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:14:21 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/03 14:56:35 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal {
private:
	Brain	*brain;
public:
	Dog();
	Dog(const Dog &source);
	Dog	&operator=(const Dog &source);
	~Dog();

	void	makeSound(void) const;
	std::string	getType(void) const;
	void			putIdea(int index, std::string idea);
	std::string		getIdea(int index) const;
};
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:14:21 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/03 14:54:00 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal {
private:
	Brain	*brain;
public:
	Cat();
	Cat(const Cat &source);
	Cat	&operator=(const Cat &source);
	~Cat();

	void	makeSound(void) const;
	std::string		getType(void) const;
	void			putIdea(int index, std::string idea);
	std::string		getIdea(int index) const;
};
#endif

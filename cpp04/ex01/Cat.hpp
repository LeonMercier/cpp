/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:14:21 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/19 15:48:55 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

// TODO: why does this need a type?
class	Cat : public Animal {
private:
	std::string	type;
	Brain	*brain;
public:
	Cat();
	Cat(const Cat &source);
	Cat	&operator=(const Cat &source);
	~Cat();
	void	makeSound(void) const;
	std::string		getType(void) const;
	void			putThougth(std::string t, int index);
	std::string		getThougth(int index);
};
#endif

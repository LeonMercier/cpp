/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:14:21 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/26 11:11:38 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"

class	Cat : public Animal {
public:
	Cat();
	Cat(const Cat &source);
	Cat	&operator=(const Cat &source);
	~Cat();
	void	makeSound(void) const;
	std::string		getType(void) const;
};
#endif

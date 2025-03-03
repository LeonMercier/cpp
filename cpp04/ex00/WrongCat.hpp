/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:14:21 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/03 16:01:16 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

# include <string>
# include <iostream>
# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {
protected:
	std::string	type;
public:
	WrongCat();
	WrongCat(const WrongCat &source);
	WrongCat	&operator=(const WrongCat &source);
	~WrongCat();
	void	makeSound(void) const;
	std::string		getType(void) const;
};
#endif

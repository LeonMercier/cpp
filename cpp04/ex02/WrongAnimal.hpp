/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:14:21 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/31 15:18:28 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class	WrongAnimal {
protected:
	std::string	type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &source);
	WrongAnimal	&operator=(const WrongAnimal &source);
	~WrongAnimal();
	void	makeSound(void) const;
	std::string		getType(void) const;
};
#endif

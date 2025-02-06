/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:26:38 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/06 12:41:08 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// this function returns a pointer to a new object, the object has to be 
// allocated on the heap, otherwise it would be destroyed automatically
// when the function returns and it falls out of scope
Zombie* newZombie( std::string name )
{
	Zombie	*zom = new Zombie(name);
	return (zom);
}

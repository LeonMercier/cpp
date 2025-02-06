/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:28:39 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/06 12:43:52 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// This function does not return the object, therefore it can be allocated on 
// the stack and allowed too fall out of scope and be automatically destroyed.
void randomChump( std::string name )
{
	Zombie	zom(name);
	zom.announce();
}

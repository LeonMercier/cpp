/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:42:00 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/20 10:59:17 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
	Weapon	club = Weapon("crude spiked club");
	// for references it is enough to have the & in the function definition,
		// it is not needed when calling the function
	HumanA bob("Bob", club); 
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	}
	{
		// HumanB uses a pointer to Weapon, because it has a constructor that
		// doesnt initialize a wpn...
	Weapon	club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
	}
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:42:00 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/17 16:47:19 by lemercie         ###   ########.fr       */
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
	bob.Attack();
	club.SetType("some other type of club");
	bob.Attack();
	}
	{
		// HumanB uses a pointer to Weapon, because it has a constructor that
		// doesnt initialize a wpn...
	Weapon	club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.SetWeapon(club);
	jim.Attack();
	club.SetType("some other type of club");
	jim.Attack();
	}
	return 0;
}

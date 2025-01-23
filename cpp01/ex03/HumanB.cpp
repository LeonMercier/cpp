/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:55:14 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/23 17:45:51 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
	_wpn = nullptr;
}

void	HumanB::setWeapon(Weapon &wpn) //here & denotes that its a reference type???
{
	_wpn = &wpn; // here & creates a pointer
}

void	HumanB::attack(void)
{
	std::cout << _name << " attacks with their ";
	if (_wpn == nullptr)
	{
		std::cout << "bare fists " << std::endl;
	}
	else
	{
		std::cout << _wpn->getType() << std::endl;
	}
}

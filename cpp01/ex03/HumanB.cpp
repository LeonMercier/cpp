/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:55:14 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/15 14:32:57 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
}

void	HumanB::setWeapon(Weapon &wpn) //here & denotes that its a reference type???
{
	_wpn = &wpn; // here & creates a pointer
}

void	HumanB::attack(void)
{
	std::cout << _name << " attacks with their ";
	std::cout << _wpn->get_type() << std::endl;
}

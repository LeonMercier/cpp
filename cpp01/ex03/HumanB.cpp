/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:55:14 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/17 16:48:32 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
}

void	HumanB::SetWeapon(Weapon &wpn) //here & denotes that its a reference type???
{
	_wpn = &wpn; // here & creates a pointer
}

void	HumanB::Attack(void)
{
	std::cout << _name << " attacks with their ";
	std::cout << _wpn->GetType() << std::endl;
}

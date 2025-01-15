/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:30:12 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/15 14:29:43 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Because reference type has no assignement constructor
// constructor initializer list has to be used when member is a reference
HumanA::HumanA(std::string name, Weapon &wpn) : _wpn(wpn), _name(name) {}

void HumanA::attack(void)
{
	std::cout << _name << " attacks with their ";
	std::cout << _wpn.get_type() << std::endl;
}

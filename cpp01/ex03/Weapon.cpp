/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:19:18 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/17 16:46:55 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string name)
{
	_type = name;
}

const std::string	&Weapon::GetType(void)
{
	const std::string &ret = _type;
	return (ret);
}

void	Weapon::SetType(std::string type)
{
	_type = type;
}

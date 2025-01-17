/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:19:40 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/17 16:46:40 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
private:
	std::string	_type;

public:
	Weapon();
	Weapon(std::string name);
	const std::string	&GetType(void);
	void		SetType(std::string type);
};
#endif

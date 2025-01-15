/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:50:07 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/15 14:12:33 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
private:
	std::string	_name;
	Weapon		*_wpn;
public:
	HumanB(std::string name);
	void	setWeapon(Weapon &wpn);
	void	attack(void);
};
#endif

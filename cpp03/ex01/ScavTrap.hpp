/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:13:36 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/28 14:44:17 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {
public:
	const static unsigned int INIT_HITPTS = 100;
	const static unsigned int INIT_ENERGYPTS = 50;
	const static unsigned int INIT_ATTCKDMG = 20;

	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &source);
	ScavTrap &operator=(const ScavTrap &source);
	~ScavTrap();

	void attack(const std::string& target);
	void	guardGate();
};
#endif


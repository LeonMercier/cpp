/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:13:36 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/30 14:54:59 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap {
private:
	
public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &source);
	ScavTrap &operator=(const ScavTrap &source);
	~ScavTrap();

	void attack(const std::string& target);
	void	guardGate();
};
#endif


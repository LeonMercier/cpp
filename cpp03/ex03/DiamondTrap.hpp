/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:18:07 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/30 14:35:19 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string	_name;
	using FragTrap::_hitpts;
public:
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &source);
	DiamondTrap		&operator=(const DiamondTrap &source);
	~DiamondTrap();

	void	whoAmI();
};
#endif


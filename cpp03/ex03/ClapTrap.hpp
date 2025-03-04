/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:53:53 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/28 13:23:21 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>
# include <string>

class	ClapTrap {
protected:
	std::string	_name;
	unsigned int			_hitpts;
	unsigned int			_energypts;
	unsigned int			_attackdmg;
public:
	const static unsigned int INIT_HITPTS = 10;
	const static unsigned int INIT_ENERGYPTS = 10;
	const static unsigned int INIT_ATTCKDMG = 0;

	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(std::string name, unsigned int hitpts, unsigned int energypts,
		  unsigned int attackdmg);
	ClapTrap(const ClapTrap &source);
	ClapTrap &operator=(const ClapTrap &source);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

};
#endif

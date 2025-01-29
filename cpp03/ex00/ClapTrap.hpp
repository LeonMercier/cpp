/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:53:53 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/29 12:03:14 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>
# include <string>

class	ClapTrap {
private:
	std::string	_name;
	int			_hitpts;
	int			_energypts;
	int			_attackdmg;
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &source);
	ClapTrap &operator=(const ClapTrap &source);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

};
#endif

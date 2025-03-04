/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:52:45 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/04 10:25:15 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	const static unsigned int INIT_HITPTS = 100;
	const static unsigned int INIT_ENERGYPTS = 100;
	const static unsigned int INIT_ATTCKDMG = 30;

	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &source);
	FragTrap	&operator=(const FragTrap &source);
	~FragTrap();

	void		highFivesGuys(void);
};


#endif

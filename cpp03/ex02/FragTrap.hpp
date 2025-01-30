/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:52:45 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/30 11:59:05 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
private:
public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &source);
	FragTrap	&operator=(const FragTrap &source);
	~FragTrap();

	void		highFivesGuys(void);
};


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:16:48 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/15 14:34:32 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie
{
private:
	std::string	_name;
public:
	Zombie(void);
	Zombie(std::string name);
	void	announce(void);
	void	set_name(std::string name);
	~Zombie(void);
};
#endif

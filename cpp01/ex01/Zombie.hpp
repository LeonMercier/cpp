/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:16:48 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/06 13:06:40 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie
{
private:
	std::string	name;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie(void);

	void	announce(void);
	void	setName(std::string name);
};
#endif

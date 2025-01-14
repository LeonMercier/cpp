/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:16:48 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/14 17:10:42 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

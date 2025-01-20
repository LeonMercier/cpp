/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:22:47 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/20 10:52:18 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int	main(void)
{
	Zombie	*zombies = zombieHorde(10, "Bob");
	for (int i = 0; i < 10; i++)
	{
		zombies[i].announce();
	}
	delete[] zombies;
}

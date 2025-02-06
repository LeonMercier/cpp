/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:22:47 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/06 13:08:24 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

// tests
int	main(void)
{
	std::cout << "Test 1: " << std::endl;
	Zombie	*zombies = zombieHorde(10, "Bob");
	if (zombies != nullptr)
	{
		for (int i = 0; i < 10; i++)
		{
			zombies[i].announce();
		}
		delete[] zombies;
	}
	
	std::cout << "Test 2: " << std::endl;
	Zombie	*zombies2 = zombieHorde(0, "Bob");
	if (zombies2 != nullptr)
	{
		zombies2->announce();
		delete[] zombies2;
	}	
	
	std::cout << "Test 3: " << std::endl;
	Zombie	*zombies3 = zombieHorde(100, "Jork");
	if (zombies3 != nullptr)
	{
		for (int i = 0; i < 100; i++)
		{
			zombies3[i].announce();
		}
		delete[] zombies3;
	}
	
	std::cout << "Test 4: " << std::endl;
	Zombie	*zombies4 = zombieHorde(-1, "Bob");
	if (zombies4 != nullptr)
	{
		zombies4->announce();
		delete[] zombies4;
	}
	
}

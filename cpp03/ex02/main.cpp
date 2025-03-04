/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:23:54 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/04 10:28:43 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ScavTrap	kronk("Kronk");
	kronk.attack("Krink");
	kronk.takeDamage(5);
	kronk.attack("Krink");
	kronk.beRepaired(1);
	kronk.takeDamage(10);
	kronk.attack("Krink");
	kronk.beRepaired(10);

	ScavTrap	jor("Jornathan");
	jor.attack("Kronk");
	jor.guardGate();
	for (int i = 0; i < 11; i++)
	{
		jor.beRepaired(5);
	}
	jor.attack("Kronk");
	jor.guardGate();

	jor = kronk;
	jor.attack("somethin");

	FragTrap	ger("Germina");
	ger.highFivesGuys();
	FragTrap	ber("Bernardo");
	ber.highFivesGuys();
	ber = ger;
	ber.highFivesGuys();

	// energy points
	FragTrap	bobo("Bobo");
	for (int i = 0; i < 101; i++)
	{
		bobo.attack("a swarm of bees");
	}

	// hitpoints
	FragTrap	yoyo("Yoyo");
	yoyo.takeDamage(99);
	yoyo.takeDamage(1);
	yoyo.takeDamage(1);

}

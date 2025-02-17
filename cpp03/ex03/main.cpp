/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:23:54 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/17 15:33:13 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	/* ScavTrap	kronk("Kronk");
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
	for (int i = 0; i < 10; i++)
	{
		ger.takeDamage(10);
	} */

	DiamondTrap	bla("Blarney");
	bla.highFivesGuys();
	bla.whoAmI();
	for (int i = 0; i < 1; i++)
	{
		bla.takeDamage(10);
	}

	DiamondTrap	blo("Bloberto");
	blo.whoAmI();
//	blo = bla;
	blo.whoAmI();
	blo.attack("a small fly");
}

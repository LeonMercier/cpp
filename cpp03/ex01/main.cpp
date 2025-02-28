/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:23:54 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/28 14:50:32 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	cla("Clappy");
	cla.takeDamage(10);
	cla.attack("someone");

	ScavTrap	kronk("Kronk");
	kronk.attack("Krink");
	kronk.takeDamage(5);
	kronk.attack("Krink");
	kronk.beRepaired(1);
	kronk.takeDamage(10);
	kronk.attack("Krink");
	kronk.beRepaired(10);
	kronk.takeDamage(95);
	kronk.attack("Krink");

	ScavTrap	jor("Jornathan");
	jor.beRepaired(3);
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
}

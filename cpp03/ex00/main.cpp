/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:23:54 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/29 13:40:19 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	kronk("Kronk");
	kronk.attack("Krink");
	kronk.takeDamage(5);
	kronk.attack("Krink");
	kronk.beRepaired(1);
	kronk.takeDamage(10);
	kronk.attack("Krink");
	kronk.beRepaired(10);

	ClapTrap	jor("Jornathan");
	jor.attack("Kronk");
	for (int i = 0; i < 11; i++)
	{
		jor.beRepaired(5);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:22:47 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/17 14:27:10 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* new_zombie( std::string name );
void random_chump( std::string name );

int	main(void)
{
	Zombie	*liz = new_zombie("Liz");
	random_chump("Bob");
	delete liz;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:29:09 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/20 17:13:12 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	getLevelIndex(Harl hrl, std::string str)
{
	for (int i = 0; i < 4; i++)
	{
		if (str == hrl.lvl_names[i])
		{
			return (i);
		}
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: please give one argument" << std::endl;
		return (1);
	}

	Harl harlie;
	switch (getLevelIndex(harlie, argv[1]))
	{
		case 0:
		{
			harlie.complain("DEBUG");
				[[fallthrough]];
		}
		case 1:
		{
			harlie.complain("INFO");
				[[fallthrough]];
		}
		case 2:
		{
			harlie.complain("WARNING");
				[[fallthrough]];
		}
		case 3:
		{
			harlie.complain("ERROR");
			break ;
		}
		default:
		{
			std::cout << "[ Probably complaining about insignificant problems ]";
			std::cout << std::endl;
		}
	}
}

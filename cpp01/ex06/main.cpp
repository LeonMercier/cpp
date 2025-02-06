/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:23:11 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/06 16:01:25 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: please give one argument" << std::endl;
		return (1);
	}

	int	level;
	try
	{
		level = std::stoi(argv[1]);
	}
	catch (...)
	{
		level = -1;
	}

	Harl harlie;
	switch (level)
	{
		case 0:
		{
			std::cout << "[ DEBUG ]" << std::endl;
			harlie.complain("DEBUG");
			std::cout << std::endl;
				[[fallthrough]];
		}
		case 1:
		{
			std::cout << "[ INFO ]" << std::endl;
			harlie.complain("INFO");
			std::cout << std::endl;
				[[fallthrough]];
		}
		case 2:
		{
			std::cout << "[ WARNING ]" << std::endl;
			harlie.complain("WARNING");
			std::cout << std::endl;
				[[fallthrough]];
		}
		case 3:
		{
			std::cout << "[ ERROR ]" << std::endl;
			harlie.complain("ERROR");
			std::cout << std::endl;
			break ;
		}
		default:
		{
			std::cout << "[ Probably complaining about insignificant problems ]";
			std::cout << std::endl;
		}
	}
}

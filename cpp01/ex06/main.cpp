/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:29:09 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/16 15:08:27 by lemercie         ###   ########.fr       */
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

	Harl harlie;
	int	level = -1;
	for (int i = 0; i < 4; i++)
	{
		if (std::stoi(argv[1]) == i)
		{
			level = i;
		}
	}
	switch (level)
	{
		case 0:
		{
			harlie.complain("DEBUG");
			harlie.complain("INFO");
			harlie.complain("WARNING");
			harlie.complain("ERROR");
			break ;
		}
		case 1:
		{
			harlie.complain("INFO");
			harlie.complain("WARNING");
			harlie.complain("ERROR");
			break ;
		}
		case 2:
		{
			harlie.complain("WARNING");
			harlie.complain("ERROR");
			break ;
		}
		case 3:
		{
			harlie.complain("ERROR");
			break ;
		}
		default:
		{
			std::cout << "Error: invalid level" << std::endl;
		}
	}
}

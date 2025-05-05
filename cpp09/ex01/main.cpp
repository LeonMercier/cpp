/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:52:34 by lemercie          #+#    #+#             */
/*   Updated: 2025/05/05 11:57:56 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv) {
	try {
		if (argc != 2) {
			std::cout << "Please give exactly one argument" << std::endl;
			return 1;
		}
		RPN(argv[1]);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	} catch (...) {
		std::cerr << "Error: unknown exception" << std::endl;
	}
}

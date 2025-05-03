/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:06:55 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/30 12:17:11 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {
	try {
		if (argc >= 2) {
			btc(argv[1]);
		} else {
			std::cout << "Error: could not open file" << std::endl;
			return 1;
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	} catch (...) {
		std::cerr << "Error: unhandled exception" << std::endl;
	}

}

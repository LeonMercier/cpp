/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:34:23 by lemercie          #+#    #+#             */
/*   Updated: 2025/05/08 16:54:09 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	try {
		if (argc != 2) {
			std::cout << "Please give exactly one argument" << std::endl;
			return 1;
		}
		init(argv[1]);
	} catch (std::exception &e) {
		if (strcmp(e.what(), "stoul") == 0) {
			std::cerr << "Error: could not convert input to integer" << std::endl;
		} else {
			std::cerr << e.what() << std::endl;
		}
	} catch (...) {
		std::cerr << "Error: unknown exception" << std::endl;
	}
}

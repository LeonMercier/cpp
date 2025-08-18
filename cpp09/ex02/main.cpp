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
		if (argc < 2) {
			std::cout << "Please give at least one argument" << std::endl;
			return 1;
		}
		PMergeMe<std::vector<unsigned int>> vector_run;
		PMergeMe<std::deque<unsigned int>> deque_run;
		vector_run.init(argc - 1, argv + 1);
		deque_run.init(argc - 1, argv + 1);
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

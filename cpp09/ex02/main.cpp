/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:34:23 by lemercie          #+#    #+#             */
/*   Updated: 2025/08/18 17:26:12 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	try {
		if (argc < 2) {
			std::cout << "Please give at least one argument" << std::endl;
			return 1;
		}

		// vector
		auto start_time = std::chrono::high_resolution_clock::now();
		PMergeMe<std::vector<unsigned int>> vector_run;
		vector_run.init(argc - 1, argv + 1, true);
		auto end_time = std::chrono::high_resolution_clock::now();
		auto duration_us = std::chrono::duration_cast<
			std::chrono::microseconds>(end_time - start_time);

		std::cout << "Time to process a range of ";
		std::cout << vector_run.orig.size() << " elements";
		std::cout << " with std::vector: " << duration_us.count() << " us";
		std::cout << std::endl;


		// deque
		start_time = std::chrono::high_resolution_clock::now();
		PMergeMe<std::deque<unsigned int>> deque_run;
		deque_run.init(argc - 1, argv + 1, false);
		end_time = std::chrono::high_resolution_clock::now();
		duration_us = std::chrono::duration_cast<
			std::chrono::microseconds>(end_time - start_time);

		std::cout << "Time to process a range of ";
		std::cout << deque_run.orig.size() << " elements";
		std::cout << " with std::deque: " << duration_us.count() << " us";
		std::cout << std::endl;

	} catch (std::exception &e) {
		if (strcmp(e.what(), "stoul") == 0) {
			std::cerr << "Error: could not convert input to integer";
			std::cerr << std::endl;
		} else {
			std::cerr << e.what() << std::endl;
		}
	} catch (...) {
		std::cerr << "Error: unknown exception" << std::endl;
	}
}

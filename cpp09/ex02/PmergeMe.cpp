/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:40:49 by lemercie          #+#    #+#             */
/*   Updated: 2025/05/08 17:06:53 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void miSort(std::vector<unsigned int> &vec) {
	(void) vec;
}

void init(std::string input) {
	std::istringstream iss(input);
	std::vector<unsigned int> vec;
	unsigned long tmp;

	while (iss >> tmp) {
		if (tmp >= std::numeric_limits<unsigned int>::max()) {
			throw (std::runtime_error("value out of range"));
		}
		unsigned int val = tmp;
		vec.insert(vec.end(), val);
	}
	for (auto iter = vec.begin(); iter != vec.end(); iter++) {
		std::cout << *iter << "#";
	}
	std::cout << std::endl;
	// we could treat duplicates as errors if we wanted...
	miSort(vec);

}

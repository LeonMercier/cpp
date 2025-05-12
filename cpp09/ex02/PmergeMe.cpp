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

static void swapPairs(std::vector<unsigned int> &vec,
					  std::vector<unsigned int>::iterator iter_a,
					  std::vector<unsigned int>::iterator iter_b,
					  unsigned int pairsize) {
	vec.insert(iter_a, iter_b, iter_b + (pairsize - 1));
	vec.erase(iter_b, iter_b + (pairsize - 1));
}

static void sortPairs(std::vector<unsigned int> &vec, unsigned int pairsize) {
	auto last_a = vec.begin() + (pairsize - 1);
	auto last_b = last_a + pairsize;
	while (last_a != vec.end() && last_b != vec.end()) {
		if (*last_a > *last_b)
		{
			swapPairs(vec, last_a, last_b, pairsize);
		}
		last_a += pairsize;
		last_b += pairsize;
	}
}

// comparison of pairs compares the last elements
static void miSort(std::vector<unsigned int> &vec, unsigned int reclvl, unsigned int pairsize) {
	if (pairsize > vec.size() / 2) {
		return ;
	}
	std::vector<std::pair<std::vector<unsigned int>::iterator, std::vector<unsigned int>::iterator>> pairs;
	auto iter_a = vec.begin();
	auto iter_b = iter_a + (pairsize - 1);
	while (iter_a != vec.end() && iter_b != vec.end()) {
		pairs.push_back(std::make_pair(iter_a, iter_b));
		if (reclvl == 0) {
			if (*iter_a > *iter_b) {
				std::swap(iter_a, iter_b);
			}
		} else {
			// TODO: unpaired elements
			sortPairs(vec, pairsize);
		}
		iter_a += pairsize;
		iter_b += pairsize;
	}
	miSort(vec, reclvl + 1, pairsize * 2);	
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
	miSort(vec, 0, 2);

}

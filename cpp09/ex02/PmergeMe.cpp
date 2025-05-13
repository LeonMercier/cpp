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

static void printVec(std::vector<unsigned int> &vec) {
	for (auto iter = vec.begin(); iter != vec.end(); iter++) {
		std::cout << *iter << ", ";
	}
	std::cout << std::endl;
}

// TODO: if reallocation of vec takes place, old iterators become invalid
// rotate() is weird
 
/* template< class ForwardIt >
    void rotate( ForwardIt first, ForwardIt n_first, ForwardIt last );

    std::rotate swaps the elements in the range [first, last) in such a way that the element n_first becomes the first element of the new range and n_first - 1 becomes the last element. */
static void swapPairs(
	std::vector<unsigned int> &vec,
	std::vector<std::pair<std::vector<unsigned int>::iterator, std::vector<unsigned int>::iterator>>::iterator pair_a,
	std::vector<std::pair<std::vector<unsigned int>::iterator, std::vector<unsigned int>::iterator>>::iterator pair_b,
	unsigned int pairsize) {
	std::cout << "Swapping: " << *pair_a->first << "-->" << *pair_a->second << " with " << *pair_b->first << "-->" << *pair_b->second << std::endl;
	(void) pairsize;

	std::cout << "SwapPairs before: ";
	printVec(vec);
	std::rotate(pair_a->first, pair_b->first, pair_b->second +1);
	std::cout << "SwapPairs  after: ";
	printVec(vec);
}

// comparison of pairs compares the last elements
static void sortPairs(
	std::vector<unsigned int> &vec,
	std::vector<std::pair<std::vector<unsigned int>::iterator, std::vector<unsigned int>::iterator>> pairs,
	unsigned int pairsize) {

	std::cout << "sortpairs: ";
	printVec(vec);
	std::cout << std::endl;

	auto pair_a = pairs.begin();
	auto pair_b = pair_a + 1;
	while (pair_a != pairs.end() && pair_b != pairs.end()) {
			std::cout << *(pair_a->second) << ">" <<*(pair_b->second) << std::endl;
		if (*(pair_a->second) > *(pair_b->second))
		{
			// std::cout << *(pair_a->second) << ">" <<*(pair_b->second) << std::endl;

			swapPairs(vec, pair_a, pair_b, pairsize);
		}
		if (std::distance(pair_b, pairs.end()) > 2) {
			pair_a += 2;
			pair_b += 2;
		} else {
			break ;
		}
	}
	std::cout << std::endl;
}

// TODO: unpaired elements
static void miSort(std::vector<unsigned int> &vec, unsigned int reclvl, unsigned int pairsize) {

	printVec(vec);

	if (pairsize > vec.size() / 2) {
		return ;
	}

	std::cout << "miSort(): reclvl: " << reclvl << std::endl;

	std::vector<std::pair<std::vector<unsigned int>::iterator, std::vector<unsigned int>::iterator>> pairs;
	auto first = vec.begin();
	auto last = first + (pairsize - 1);
	while (first != vec.end() && last != vec.end()) {
		pairs.push_back(std::make_pair(first, last));
		if (reclvl == 1) {
			if (*first > *last) {
				std::iter_swap(first, last);
			}
		}
		if (std::distance(last, vec.end()) > pairsize) {
			first += pairsize;
			last += pairsize;
		} else {
			break ;
		}
	}
	sortPairs(vec, pairs, pairsize);
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
	miSort(vec, 1, 2);
}

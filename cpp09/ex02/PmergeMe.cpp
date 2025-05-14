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

static void printVec(std::vector<unsigned int> &vec, std::vector<unsigned int>::iterator iter) {
	for (auto it = iter; it != vec.end(); it++) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
}

// TODO: if reallocation of vec takes place, old iterators become invalid
/*
 rotate() is weird:
 template< class ForwardIt >
    void rotate( ForwardIt first, ForwardIt n_first, ForwardIt last );

    std::rotate swaps the elements in the range [first, last) in such a way
	that the element n_first becomes the first element of the new range and
	n_first - 1 becomes the last element.
*/
static void swapPairs(
	std::vector<unsigned int> &vec,
	std::vector<pairIter>::iterator pair_a,
	std::vector<pairIter>::iterator pair_b) {
	std::cout << "Swapping: " << *pair_a->first << "-->" << *pair_a->second << 
		" with " << *pair_b->first << "-->" << *pair_b->second << std::endl;

	std::cout << "SwapPairs before: ";
	printVec(vec, vec.begin());
	std::rotate(pair_a->first, pair_b->first, pair_b->second +1);
	std::cout << "SwapPairs  after: ";
	printVec(vec, vec.begin());
}

// comparison of pairs compares the last elements
static void sortPairs(std::vector<unsigned int> &vec,
					  std::vector<pairIter> elems) {

	std::cout << "sortpairs: ";
	printVec(vec, vec.begin());
	std::cout << std::endl;

	auto pair_a = elems.begin();
	auto pair_b = pair_a + 1;
	while (pair_a != elems.end() && pair_b != elems.end()) {
		if (*(pair_a->second) > *(pair_b->second))
		{
			std::cout << *(pair_a->second) << ">" << *(pair_b->second) <<
				std::endl;
			swapPairs(vec, pair_a, pair_b);
		}
		if (std::distance(pair_b, elems.end()) > 2) {
			pair_a += 2;
			pair_b += 2;
		} else {
			break ;
		}
	}
	std::cout << std::endl;
}

// TODO: unpaired elements
// TODO: make a typedef for the ugly std::pair thing
static void miSort(std::vector<unsigned int> &vec, unsigned int reclvl,
				   unsigned int elemsize) {

	std::cout << "starting miSort(): reclvl: " << reclvl << " with vector: " <<
		std::endl;
	printVec(vec, vec.begin());
	std::cout << std::endl;

	if (elemsize > vec.size() / 2) {
		return ;
	}

	// just holds iterators to the actual vector where the numbers are
	std::vector<pairIter> elems;

	// first and last are the first and last numbers of an element
	// on the first recursion level, they point to the same number
	auto first = vec.begin();
	auto last = first + (elemsize - 1);
	while (first != vec.end() && last != vec.end()) {
		elems.push_back(std::make_pair(first, last));
		if (std::distance(last, vec.end()) > elemsize) {
			first += elemsize;
			last += elemsize;
		} else {
			std::cout << "elements: " << elems.size() << std::endl;
			std::cout << "elems after \"last\": " << std::endl;
			printVec(vec, last + 1);
			break ;
		}
	}
	sortPairs(vec, elems);
	miSort(vec, reclvl + 1, elemsize * 2);
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
	miSort(vec, 1, 1);
}

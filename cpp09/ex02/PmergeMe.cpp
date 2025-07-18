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

/*
 rotate() is weird:
 template< class ForwardIt >
    void rotate( ForwardIt first, ForwardIt n_first, ForwardIt last );

    std::rotate swaps the elements in the range [first, last) in such a way
	that the element n_first becomes the first element of the new range and
	n_first - 1 becomes the last element.
*/
static void swapPairs(
	// std::vector<unsigned int> &vec,
	std::vector<pairIter>::iterator pair_a,
	std::vector<pairIter>::iterator pair_b) {
	// std::cout << "Swapping: " << *pair_a->first << "-->" << *pair_a->second << 
		// " with " << *pair_b->first << "-->" << *pair_b->second << std::endl;

	// std::cout << "SwapPairs before: ";
	// printVec(vec, vec.begin());
	std::rotate(pair_a->first, pair_b->first, pair_b->second +1);
	// std::cout << "SwapPairs  after: ";
	// printVec(vec, vec.begin());
}

// comparison of pairs compares the last elements
// sorts pairs of elements, not pairs of numbers, hence always advancing 
// by += 2
static void sortPairs(std::vector<pairIter> elems) {

	// std::cout << "sortpairs: ";
	// printVec(vec, vec.begin());
	// std::cout << std::endl;

	auto pair_a = elems.begin();
	auto pair_b = pair_a + 1;
	while (pair_a != elems.end() && pair_b != elems.end()) {
		if (*(pair_a->second) > *(pair_b->second))
		{
			// std::cout << *(pair_a->second) << ">" << *(pair_b->second) <<
				// std::endl;
			swapPairs(pair_a, pair_b);
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

static void printElems(std::vector<pairIter> elems) {
	for (auto iter = elems.begin(); iter != elems.end(); iter++) {
		for (auto elem_iter = iter->first; elem_iter <= iter->second;
				elem_iter++)
		{
			std::cout << *elem_iter << ", ";
		}
		std::cout << std::endl;
	}
}

// TODO: unpaired elements
static void miSort(std::vector<unsigned int> &vec, unsigned int reclvl,
				   unsigned int elemsize) {

	std::cout << "starting miSort(): reclvl: " << reclvl << " with vector: " <<
		std::endl;
	// printVec(vec, vec.begin());
	// std::cout << std::endl;

	// terminate recursion
	if (elemsize > vec.size() / 2) {
		std::cout << "Reached end of recursion" << std::endl;
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
			// std::cout << "elements: " << elems.size() << std::endl;
			std::cout << "lonely nums: " << std::endl;
			printVec(vec, last + 1);
			break ;
		}
	}
	std::cout << "elems: " << std::endl;
	printElems(elems);
	sortPairs(elems);
	std::cout << "sorted elems: " << std::endl;
	printElems(elems);

	// recursive call
	miSort(vec, reclvl + 1, elemsize * 2);

	// returning from recursion
	
}

// The size of vec does not change after init(), therefore iterators should 
// remain valid
void init(int count, char **strs) {
	std::vector<unsigned int> vec;
	
	for (int i = 0; i < count; i++) {
		std::istringstream iss(*strs);
		unsigned long tmp;
		while (iss >> tmp) {
			if (tmp >= std::numeric_limits<unsigned int>::max()) {
				throw (std::runtime_error("value out of range"));
			}
			unsigned int val = tmp;
			vec.insert(vec.end(), val);
		}
		strs++;
	}
	
	// for (auto iter = vec.begin(); iter != vec.end(); iter++) {
	// 	std::cout << *iter << "#";
	// }
	// std::cout << std::endl;
	miSort(vec, 1, 1);
}

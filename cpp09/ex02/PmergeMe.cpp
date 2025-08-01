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
#include <vector>

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
void PMergeMe::swapPairs(
	std::pair<int, int> pair_a,
	std::pair<int, int> pair_b) {
	// std::cout << "Swapping: " << *pair_a->first << "-->" << *pair_a->second << 
		// " with " << *pair_b->first << "-->" << *pair_b->second << std::endl;

	// std::cout << "SwapPairs before: ";
	// printVec(vec, vec.begin());
	std::rotate(orig.begin() + pair_a.first, orig.begin() + pair_b.first,
			 orig.begin() + pair_b.second + 1);
	// std::cout << "SwapPairs  after: ";
	// printVec(vec, vec.begin());
}

// comparison of pairs compares the last elements
// sorts pairs of elements, not pairs of numbers, hence always advancing 
// by += 2
void PMergeMe::sortPairs(std::vector<std::pair<int, int>> &elems) {
	auto pair_a = elems.begin();
	auto pair_b = pair_a + 1;
	while (pair_a != elems.end() && pair_b != elems.end()) {
		if (orig.at(pair_a->second) > orig.at(pair_b->second))
		{
			swapPairs(*pair_a, *pair_b);
		}
		if (std::distance(pair_b, elems.end()) > 2) {
			pair_a += 2;
			pair_b += 2;
		} else {
			break ;
		}
	}
}

void PMergeMe::printElems(std::vector<std::pair<int, int>> elems) {
	for (auto iter = elems.begin(); iter != elems.end(); iter++) {
		for (int elem_iter = iter->first; elem_iter <= iter->second;
				elem_iter++)
		{
			std::cout << orig.at(elem_iter) << ", ";
		}
		std::cout << std::endl;
	}
}

void PMergeMe::makeMain(std::vector<std::pair<int, int>> &elems) {
	if (elems.size() < 4) {
		return ;
	}
	std::cout << "before makemain:" << std::endl;
	printElems(elems);
	printVec(orig, orig.begin());
	std::vector<int> as_to_move;
	auto tail = elems.begin() + 2;
	for (size_t i = 3; i < elems.size(); i += 2) {
		std::cout << "i: " << i << std::endl;
		if (i + 1 < elems.size()) {
			std::rotate(
				orig.begin() + tail->first,
				orig.begin() + elems.at(i).first,
				orig.begin() + elems.at(i + 1).first);
		} else {
			std::rotate(
				orig.begin() + tail->first,
				orig.begin() + elems.at(i).first,
				orig.end());
		}
	}
	std::cout << "after makemain:" << std::endl;
	printElems(elems);
	printVec(orig, orig.begin());
}


// TODO: unpaired elements
// elems is specific to each recursion level, therefore a local variable
void PMergeMe::miSort(unsigned int reclvl, unsigned int elemsize) {

	std::cout << "\nstarting miSort(): reclvl: " << reclvl << " with vector: " <<
		std::endl;
	// printVec(vec, vec.begin());
	// std::cout << std::endl;

	// terminate recursion
	if (elemsize > orig.size() / 2) {
		std::cout << "Reached end of recursion" << std::endl;
		return ;
	}

	// just holds iterators to the actual vector where the numbers are
	std::vector<std::pair<int, int>> elems;

	// first and last are the first and last numbers of an element
	// on the first recursion level, they point to the same number
	size_t first = 0;
	size_t last = first + (elemsize - 1);
	while (last < orig.size()) {
		elems.push_back(std::make_pair(first, last));
		if (orig.size() - last > elemsize) {
			first += elemsize;
			last += elemsize;
		} else {
			// std::cout << "elements: " << elems.size() << std::endl;
			std::cout << "lonely nums: " << std::endl;
			// begin_unpaired = last + 1;
			// printVec(orig, begin_unpaired);
			break ;
		}
	}
	std::cout << "elems: " << std::endl;
	printElems(elems);
	sortPairs(elems);
	std::cout << "sorted elems: " << std::endl;
	printElems(elems);
	std::cout << "ORIG: "  << std::endl;
	printVec(orig, orig.begin());

	// recursive call
	miSort(reclvl + 1, elemsize * 2);
	if ( elems.size() == 2) {
		std::cout << "Penultimate recursion level" << std::endl;
		return ;
	}
	std::cout << "reclvl: " << reclvl << " elemsize: " << elemsize;
	std::cout << " number of elems: " << elems.size() << std::endl;
	makeMain(elems);
	std::cout << "ORIG: "  << std::endl;
	printVec(orig, orig.begin());
	// insertPend(main, elems);


	// returning from recursion
	
}

// The size of vec does not change after init(), therefore iterators should 
// remain valid
void PMergeMe::init(int count, char **strs) {
	
	for (int i = 0; i < count; i++) {
		std::istringstream iss(*strs);
		unsigned long tmp;
		while (iss >> tmp) {
			if (tmp >= std::numeric_limits<unsigned int>::max()) {
				throw (std::runtime_error("value out of range"));
			}
			unsigned int val = tmp;
			orig.insert(orig.end(), val);
		}
		strs++;
	}
	
	// for (auto iter = vec.begin(); iter != vec.end(); iter++) {
	// 	std::cout << *iter << "#";
	// }
	// std::cout << std::endl;
	
// test for rotate()
/* 	
	printVec(orig, orig.begin());
	auto a = orig.begin() + 3;
	auto b = orig.begin() + 9;
	auto c = orig.begin() + 11;
	std::rotate(a, b, c);
	printVec(orig, orig.begin());
 */
	miSort(1, 1);
}

bool	PMergeMe::bigger(unsigned int a, unsigned int b) {
	comparisons++;
	return (a > b);
}

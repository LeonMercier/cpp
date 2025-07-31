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
static void sortPairs(std::vector<pairIter> &elems) {

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

// first two elements, then every other element
//
// TODO: this currently doesnt modify orig, and elems is specific to only the 
// current recursion level
static void makeMain(std::vector<pairIter> &main, std::vector<pairIter> &elems) {
	main.push_back(elems.front());
	elems.erase(elems.begin());

	for (size_t i = 0; i < elems.size(); i += 2) 
	{
		// TODO: probaly will just have to be a rotate of elems and forget 
		// about main
		main.push_back(elems.at(i));
	}

	// remove the move element from elems => elems is now pend
	for (auto it = main.begin(); it != main.end(); ++it) {
		auto found = std::find(elems.begin(), elems.end(), *it);
		if (found != elems.end()) {
			elems.erase(found);
		}
	}
}

// static void insertPend(std::vector<pairIter> &main, std::vector<pairIter> &elems) {
//
// }

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
	std::vector<pairIter>	elems;
	auto					begin_unpaired = orig.end();

	// first and last are the first and last numbers of an element
	// on the first recursion level, they point to the same number
	auto first = orig.begin();
	auto last = first + (elemsize - 1);
	while (first != orig.end() && last != orig.end()) {
		elems.push_back(std::make_pair(first, last));
		if (std::distance(last, orig.end()) > elemsize) {
			first += elemsize;
			last += elemsize;
		} else {
			// std::cout << "elements: " << elems.size() << std::endl;
			std::cout << "lonely nums: " << std::endl;
			begin_unpaired = last + 1;
			printVec(orig, begin_unpaired);
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
	std::vector<pairIter> main;
	makeMain(main, elems);
	std::cout << "main: " << std::endl;
	printElems(main);
	std::cout << "pend: " << std::endl;
	printElems(elems);
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
	miSort(1, 1);
}

bool	PMergeMe::bigger(unsigned int a, unsigned int b) {
	comparisons++;
	return (a > b);
}

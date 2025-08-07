/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:36:32 by lemercie          #+#    #+#             */
/*   Updated: 2025/05/08 17:03:21 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <sstream>
#include <cstring> // strcmp()
#include <limits>
#include <vector>
#include <algorithm> // rotate()

// TODO: 
// for final product: 
// 		- keep track of amount of comparisons
// 		- canonical orthodox form


// a pair of iterators to vector<unsigned int>'s
// typedef typename std::pair<
// 	std::vector<unsigned int>::iterator,
// 	std::vector<unsigned int>::iterator> pairIter;


// TODO: split class into its own file
// holds value so that we can do comparison overload
class Elem {
public:
	std::pair<int, int> indices;
	char				chain;
	size_t				chain_index;
	unsigned int		value;
	int					&comparisons;
	Elem(int first, int last, unsigned int value, int &comparisons) :
		indices({first, last}), value(value), comparisons(comparisons) {

	}
	bool operator<(const Elem &rhs) {
	// lhs.comparisons and rhs.comparisons should refer to the same underlying
		comparisons++;
		return value < rhs.value;
	}
};

class PMergeMe {
public: 
	int comparisons = 0;
	std::vector<unsigned int> orig;
	std::vector<std::pair<int, int>>::iterator first_of_pend;

	void init(int count, char **strs);
	void miSort(unsigned int reclvl, unsigned int elemsize);
	bool bigger(unsigned int a, unsigned int b);
	void makeMain(std::vector<std::pair<int, int>> &elems);
	// void insertPend(
	// 	std::vector<std::pair<int, int>> &elems,
	// 	unsigned int reclvl,
	// 	unsigned int elemsize,
	// 	std::vector<pairIter> a_iters,
	// 	std::vector<pairIter> b_iters);
	void sortPairs(std::vector<std::pair<int, int>> &elems);
	void sortPairs2(std::vector<Elem> &elems);
	void swapPairs(
		std::pair<int, int> pair_a,
		std::pair<int, int> pair_b);
	void swapPairs2(Elem &pair_a, Elem &pair_b);
	void printElems(std::vector<std::pair<int, int>> elems);
	void printElems2(std::vector<Elem> &elems);
	void	moveElem(std::vector<std::pair<int, int>> &elems,
			   std::vector<std::pair<int,int>>::iterator put_after,
			   std::vector<std::pair<int,int>>::iterator to_move);
	void	writeOrig(std::vector<Elem> &elems);
	// void	moveElem(pairIter put_after, pairIter to_move);
	// pairIter binarySearch(
	// 	std::vector<std::pair<int, int>> &elems,
	// 	pairIter bound, pairIter to_move);
};


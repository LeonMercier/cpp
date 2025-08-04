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
// 		keep track of amount of comparisons


// a pair of iterators to vector<unsigned int>'s
// typedef typename std::pair<
// 	std::vector<unsigned int>::iterator,
// 	std::vector<unsigned int>::iterator> pairIter;

class PMergeMe {
public: 
	int comparisons = 0;
	std::vector<unsigned int> orig;
	std::vector<std::pair<int, int>>::iterator first_of_pend;

	void init(int count, char **strs);
	void miSort(unsigned int reclvl, unsigned int elemsize);
	bool bigger(unsigned int a, unsigned int b);
	void makeMain(std::vector<std::pair<int, int>> &elems);
	void insertPend(std::vector<std::pair<int, int>> &elems,
						  unsigned int reclvl, unsigned int elemsize);
	void sortPairs(std::vector<std::pair<int, int>> &elems);
	void swapPairs(
		std::pair<int, int> pair_a,
		std::pair<int, int> pair_b);
	void printElems(std::vector<std::pair<int, int>> elems);
	void	moveElem(std::vector<std::pair<int, int>> &elems,
			   std::vector<std::pair<int,int>>::iterator put_after,
			   std::vector<std::pair<int,int>>::iterator to_move);
};


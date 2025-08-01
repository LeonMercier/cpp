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
typedef typename std::pair<
	std::vector<unsigned int>::iterator,
	std::vector<unsigned int>::iterator> pairIter;

class PMergeMe {
public: 
	int comparisons = 0;
	std::vector<unsigned int> orig;

	void init(int count, char **strs);
	void miSort(unsigned int reclvl, unsigned int elemsize);
	bool bigger(unsigned int a, unsigned int b);
	void makeMain(std::vector<std::pair<int, int>> &elems);
};


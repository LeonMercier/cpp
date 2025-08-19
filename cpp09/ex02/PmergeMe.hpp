/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:36:32 by lemercie          #+#    #+#             */
/*   Updated: 2025/08/18 17:31:33 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <sstream>
#include <cstring> // strcmp()
#include <limits>
#include <vector>
#include <deque>
#include <algorithm> // rotate()
#include <cmath> // for allowedComps()
#include <chrono>

#include "Elem.hpp"

constexpr bool PRINTS = true; // print container contents
constexpr bool COMPS = false; // print amount of comparisons

// non class functions
template <typename Container>
void printVec(Container &vec, typename Container::iterator iter)
{
	if (PRINTS) {
		for (auto it = iter; it != vec.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
}

void	sortPairs(std::vector<Elem<unsigned int>> &a_chain,
			   std::vector<Elem<unsigned int>> &b_chain,
			   std::vector<Elem<unsigned int>> &elems);
size_t	calcAllowedComps(size_t nums);
void	calcJnums(size_t orig_size, std::vector<unsigned int> &jnums);
std::vector<Elem<unsigned int>>::iterator findFromPend(
	size_t i, std::vector<Elem<unsigned int>> &pend);
std::vector<Elem<unsigned int>>::const_iterator binarySearch(
	std::vector<Elem<unsigned int>> &main, Elem<unsigned int> &to_insert);


template <class Container>
class PMergeMe {
public: 
	int comparisons = 0;
	Container orig;
	std::vector<unsigned int> jnums;

	PMergeMe<Container>() = default;
	PMergeMe<Container>(const PMergeMe<Container> &source) = default;
	PMergeMe<Container> &operator=(const PMergeMe<Container>&source) = default;
	~PMergeMe<Container>() = default;

	void	init(int count, char **strs, bool print);
	void	miSort(unsigned int reclvl, unsigned int elemsize);
	void	swapPairs(Elem<unsigned int> &pair_a, Elem<unsigned int> &pair_b);
	void	printElems(std::vector<Elem<unsigned int>> &elems);
	void	writeOrig(std::vector<Elem<unsigned int>> &elems,
				size_t first_unpaired);
	void	writeOrigFromTwoChains(std::vector<Elem<unsigned int>> &a_chain,
							 std::vector<Elem<unsigned int>> &b_chain,
							 size_t first_unpaired);
	void	regenElemValues(std::vector<Elem<unsigned int>> &elems);
	void	makeMain(std::vector<Elem<unsigned int>> &elems);
	void	insertPendToMain(std::vector<Elem<unsigned int>> &main,
					   std::vector<Elem<unsigned int>> &pend);
};

template <class Container>
void PMergeMe<Container>::init(int count, char **strs, bool print) {
	
	for (int i = 0; i < count; i++) {
		std::istringstream iss(*strs);
		std::string token;
		unsigned long val = 0;
		while (iss >> token) {
			val = std::stoul(token); // no such thing as std::stou()
			if (val > std::numeric_limits<unsigned int>::max() ||
				val < std::numeric_limits<unsigned int>::min()) {
				throw (std::runtime_error("value out of range"));
			}
			orig.insert(orig.end(), static_cast<unsigned int>(val));
		}
		strs++;
	}
	if (orig.size() == 0) {
		return ;
	}

	if (print) {
		std::cout << "Before:\t";
		printVec(orig, orig.begin());
	}
	// TESTING
	auto test = orig;

	calcJnums(orig.size(), jnums);

	miSort(1, 1);

	if (print) {
		std::cout << "After:\t";
		printVec(orig, orig.begin());
	}

	// TESTING
	if (COMPS) {
		std::sort(test.begin(), test.end());
		int allowed_comps = calcAllowedComps(orig.size());
		if (orig == test) {
			std::cout << "init(): SUCCESSful sort: ";
			std::cout << comparisons << " comps";
			std::cout << " of " << allowed_comps << " allowed ";
			if (comparisons <= allowed_comps) {
				std::cout << "OK";
			} else {
				std::cout << "FAIL";
			}
			std::cout << std::endl;			
		} else {
			std::cout << "init(): FAILed sort" << std::endl;
		}
	}
}

// elems is specific to each recursion level, therefore a local variable
template <class Container>
void PMergeMe<Container>::miSort(unsigned int reclvl, unsigned int elemsize) {
	// terminate recursion
	if (elemsize > orig.size() / 2) {
		return ;
	}

	// elems just holds indices of the actual vector where the numbers are
	// this will be useful across recursion levels
	std::vector<Elem<unsigned int>>	elems;
	int					first_unpaired = orig.size();

	// first and last are the first and last numbers of an element
	// on the first recursion level, they point to the same number
	size_t first = 0;
	size_t last = first + (elemsize - 1);

	// if the while condition evaluates false, then all elements are paired,
	// if break is reached then there are unpaired elements
	while (last < orig.size()) {
		elems.push_back(Elem<unsigned int>(
			first, last, orig.at(last), &comparisons));
		if (orig.size() - last > elemsize) {
			first += elemsize;
			last += elemsize;
		} else {
			first_unpaired = last + 1;
			break ;
		}
	}

	std::vector<Elem<unsigned int>> a_chain;
	std::vector<Elem<unsigned int>> b_chain;

	sortPairs(a_chain, b_chain, elems);

	// reflect changes in main before recursing
	writeOrigFromTwoChains(a_chain, b_chain, first_unpaired);

	// at this point 'elems' can be seen as holding indices to first, second, 
	// third element and so on

	// recursive call
	miSort(reclvl + 1, elemsize * 2);
	if (elems.size() == 2) { // only two elems, nothing to do with them
		return ;
	}
	regenElemValues(elems);

	makeMain(elems);

	writeOrig(elems, first_unpaired);
}

// could be made to only move numbers inside the original vector to be more in
// the spirit of the exercise, where the items could be very large
// probably doable with std::rotate()
template <class Container>
void	PMergeMe<Container>::writeOrigFromTwoChains(
	std::vector<Elem<unsigned int>> &a_chain,
	std::vector<Elem<unsigned int>> &b_chain,
	size_t first_unpaired)
{
	Container new_orig;
	auto iter_a = a_chain.begin();
	auto iter_b = b_chain.begin();

	while (true) {
		if (iter_b != b_chain.end()) {
			for (int i = iter_b->indices.first; i <= iter_b->indices.second;
				++i)
			{	
				new_orig.push_back(orig.at(i));
			}
			iter_b++;
		}
		if (iter_a != a_chain.end()) {
			for (int i = iter_a->indices.first; i <= iter_a->indices.second;
				++i)
			{
				new_orig.push_back(orig.at(i));
			}
			iter_a++;
		}
		if (iter_a == a_chain.end() && iter_b == b_chain.end()) {
			break ;
		}
	}

	for (size_t i = first_unpaired; i < orig.size(); ++i) {
		new_orig.push_back(orig.at(i));
	}
	orig = new_orig;
}

// could be made to only move numbers inside the original vector to be more in
// the spirit of the exercise, where the items could be very large
// probably doable with std::rotate()
template <class Container>
void	PMergeMe<Container>::writeOrig(std::vector<Elem<unsigned int>> &elems,
									size_t first_unpaired)
{
	Container new_orig;

	for (auto it = elems.begin(); it != elems.end(); ++it) {
		for (int i = it->indices.first; i <= it->indices.second; ++i) {
			new_orig.push_back(orig.at(i));
		}
	}
	for (size_t i = first_unpaired; i < orig.size(); ++i) {
		new_orig.push_back(orig.at(i));
	}
	orig = new_orig;
}

template <class Container>
void	PMergeMe<Container>::regenElemValues(
	std::vector<Elem<unsigned int>> &elems)
{
	for (auto it = elems.begin(); it != elems.end(); ++it) {
		it->value = orig.at(it->indices.second);
	}
}

// here we can sort all Elems into main and pend, then insert from pend
// to main and only after that, in miSort(), write orig
// non participating numbers will chill at the same index at the end all the
// time
template <class Container>
void PMergeMe<Container>::makeMain(std::vector<Elem<unsigned int>> &elems) {
	if (elems.size() <= 2) {
		if (elems.size() >= 1) {
			elems.at(0).chain= 'b';
			elems.at(0).chain_index = 1;
		}
		if (elems.size() == 2) {
			elems.at(1).chain = 'a';
			elems.at(1).chain_index = 1;
		}
		return ;
	}

	std::vector<Elem<unsigned int>> main;
	std::vector<Elem<unsigned int>> pend;

	// main starts as b1 and all of 'a's; that is: first elem, second elem, 
	// then every other elem
	main.push_back(elems.at(0));
	main.back().chain = 'b';
	main.back().chain_index = 1;
	main.push_back(elems.at(1));
	main.back().chain = 'a';
	main.back().chain_index = 1;

	size_t index_b = 2;
	size_t index_a = 2;
	for (size_t i = 2; i < elems.size(); ++i) {
		if (i % 2 == 0) {
			pend.push_back(elems.at(i));
			pend.back().chain = 'b';
			pend.back().chain_index = index_b++;
		} else {
			main.push_back(elems.at(i));
			main.back().chain = 'a';
			main.back().chain_index = index_a++;
		}
	}
	insertPendToMain(main, pend);
	elems = main;
}

template <class Container>
void PMergeMe<Container>::insertPendToMain(
	std::vector<Elem<unsigned int>> &main,
	std::vector<Elem<unsigned int>> &pend)
{
	if (pend.size() == 0) {
		return ;
	}
	for (auto cur_jnum = jnums.begin() + 3; cur_jnum != jnums.end();
		++cur_jnum)
	{
		auto prev_jnum = cur_jnum -1;
		for (size_t i = *cur_jnum; i >= *prev_jnum; --i) {
			auto to_insert = findFromPend(i, pend);
			if (to_insert != pend.end()) {
				auto insert_before = binarySearch(main, *to_insert);
				main.insert(insert_before, *to_insert);
				pend.erase(to_insert);
				if (pend.size() == 0) {
					return ;
				}
			} else {
				break ;
			}
		}
	}

	// stuff remaining in pend after Jacostahl insertion
	if (pend.size() > 0) {
		// iterate in reverse 
		for (auto to_insert = pend.rbegin(); to_insert != pend.rend();
			++to_insert)
		{
			auto insert_before = binarySearch(main, *to_insert);
			main.insert(insert_before, *to_insert);
		}
	}
}

// debugging only
template <class Container>
void PMergeMe<Container>::printElems(std::vector<Elem<unsigned int>> &elems) {
	for (auto iter = elems.begin(); iter != elems.end(); iter++) {
		for (int elem_iter = iter->indices.first;
			elem_iter <= iter->indices.second; elem_iter++)
		{
			try {
				std::cout << orig.at(elem_iter) << ", ";
			} catch (...) {
				std::cout << "printElems(): no element at: " << elem_iter << std::endl;
			}
		}
		std::cout << std::endl;
	}
}



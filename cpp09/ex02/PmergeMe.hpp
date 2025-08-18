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

// TODO: 
// for final product: 
// 		- canonical orthodox form

constexpr bool PRINTS = true;
constexpr bool COMPS = false;

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

// TODO: give error on non integer argument
template <class Container>
void PMergeMe<Container>::init(int count, char **strs, bool print) {
	
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
	if (orig.size() == 0) {
		return ;
	}

	if (print) {
		std::cout << "Before:\t";
		printVec(orig, orig.begin());
	}
	// TESTING
	// std::vector<unsigned int> test = orig;
	auto test = orig;

	calcJnums(orig.size(), jnums);

	// printVec(jnums, jnums.begin());
	// printVec(jnums, jnums.begin());
	
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

template <class Container>
// elems is specific to each recursion level, therefore a local variable
void PMergeMe<Container>::miSort(unsigned int reclvl, unsigned int elemsize) {

	// std::cout << "\nstarting miSort(): reclvl: " << reclvl;
	// std::cout << " with vector: ";
	// printVec(vec, vec.begin());
	// std::cout << std::endl;

	// terminate recursion
	if (elemsize > orig.size() / 2) {
		// std::cout << "Reached end of recursion" << std::endl;
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
		elems.push_back(Elem<unsigned int>(first, last, orig.at(last), &comparisons));
		if (orig.size() - last > elemsize) {
			first += elemsize;
			last += elemsize;
		} else {
			first_unpaired = last + 1;
			break ;
		}
	}
	// std::cout << "elems after creation: " << std::endl;
	// printElems(elems);
	// std::cout << "last: " << last << std::endl;
	// std::cout << "unpaired: " << first_unpaired << std::endl;

	std::vector<Elem<unsigned int>> a_chain;
	std::vector<Elem<unsigned int>> b_chain;

	// std::cout << "miSort(), reclvl: " << reclvl << " before sortPairs() ";
	// std::cout << comparisons << " comps" << std::endl;
	sortPairs(a_chain, b_chain, elems);
	// std::cout << "miSort(), reclvl: " << reclvl << " after sortPairs() ";
	// std::cout << comparisons << " comps" << std::endl;

	// std::cout << "sorted elems: " << std::endl;
	// printElems(elems);

	// std::cout << "ORIG before write: "  << std::endl;
	// printVec(orig, orig.begin());

	// reflect changes in main before recursing
	writeOrigFromTwoChains(a_chain, b_chain, first_unpaired);
	// std::cout << "ORIG after write: "  << std::endl;
	// printVec(orig, orig.begin());

	// at this point 'elems' can be seen as holding indices to first, second, 
	// third element and so on

	// recursive call
	miSort(reclvl + 1, elemsize * 2);
	// std::cout << "\n#####\n";
	if (elems.size() == 2) {
		// std::cout << "Penultimate recursion level" << std::endl;
		return ;
	}
	regenElemValues(elems);
	// std::cout << "after recursion" << std::endl;
	// std::cout << "first indices " << elems.begin()->indices.first << "-";
	// std::cout << elems.begin()->indices.second << std::endl;
	// printElems(elems);
	// std::cout << "miSort(), reclvl: " << reclvl << " before makeMain() ";
	// std::cout << comparisons << " comps" << std::endl;
	makeMain(elems);
	// std::cout << "miSort(), reclvl: " << reclvl << " after makeMain() ";
	// std::cout << comparisons << " comps" << std::endl;
	writeOrig(elems, first_unpaired);
	// std::cout << "ORIG: "  << std::endl;
	// printVec(orig, orig.begin());
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

	// std::cout << "writeOrigTo: " << a_chain.size() << "+" << b_chain.size() << std::endl;
	// std::cout << "first unpaired: " << first_unpaired << std::endl;
	// return ;
	// std::vector<unsigned int> new_orig;
	Container new_orig;
	auto iter_a = a_chain.begin();
	auto iter_b = b_chain.begin();
	while (true) {
		if (iter_b != b_chain.end()) {
			for (int i = iter_b->indices.first; i <= iter_b->indices.second;
				++i)
			{	
				// std::cout << "WO(): push index: " << i << std::endl;
				new_orig.push_back(orig.at(i));
			}
			iter_b++;
		}
		if (iter_a != a_chain.end()) {
			for (int i = iter_a->indices.first; i <= iter_a->indices.second;
				++i)
			{
				// std::cout << "WO(): push index: " << i << std::endl;
				new_orig.push_back(orig.at(i));
			}
			iter_a++;
		}
		if (iter_a == a_chain.end() && iter_b == b_chain.end()) {
			break ;
		}
	}

	// std::cout << "NEW ORIG before unpaired: " << std::endl;
	// printVec(new_orig, new_orig.begin());
	// std::cout << "SIZE before unpaired: " << new_orig.size() << std::endl;
	for (size_t i = first_unpaired; i < orig.size(); ++i) {
		// std::cout << "writeOrigTwo(): pushing unpaired: ";
		// std::cout << "index: " << i << ", value: " << orig.at(i) << std::endl;
		new_orig.push_back(orig.at(i));
	}
	orig = new_orig;
	// std::cout << "SIZE after unpaired: " << orig.size() << std::endl;
}

// could be made to only move numbers inside the original vector to be more in
// the spirit of the exercise, where the items could be very large
// probably doable with std::rotate()
template <class Container>
void	PMergeMe<Container>::writeOrig(std::vector<Elem<unsigned int>> &elems, size_t first_unpaired) {
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
void	PMergeMe<Container>::regenElemValues(std::vector<Elem<unsigned int>> &elems) {
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
			// std::cout << "makeMain(): push: " << "b-" << i << " to pend" << std::endl;
			pend.push_back(elems.at(i));
			pend.back().chain = 'b';
			pend.back().chain_index = index_b++;
		} else {
			// std::cout << "makeMain(): push: " << "a-" << i << " to main" << std::endl;
			main.push_back(elems.at(i));
			main.back().chain = 'a';
			main.back().chain_index = index_a++;
		}
	}
	insertPendToMain(main, pend);
	elems = main;
}

template <class Container>
void PMergeMe<Container>::insertPendToMain(std::vector<Elem<unsigned int>> &main, std::vector<Elem<unsigned int>> &pend) {
	// std::cout << "insertPendtoMain(): before" << std::endl;
	// printElems(main);
	// std::cout << "-----" << std::endl;
	// printElems(pend);
	
	// std::cout << "insertPendToMain(): early: " << pend[0].value << std::endl;
	if (pend.size() == 0) {
		// std::cout << "early return" << std::endl;
		return ;
	}
	for (auto cur_jnum = jnums.begin() + 3; cur_jnum != jnums.end(); ++cur_jnum) {
		// std::cout << "loop" << std::endl;
		auto prev_jnum = cur_jnum -1;
		for (size_t i = *cur_jnum; i >= *prev_jnum; --i) {
			// std::cout << "loop2" << std::endl;
			auto to_insert = findFromPend(i, pend);
			if (to_insert != pend.end()) {
				// std::cout << "insertPendToMain(): " << to_insert->value << std::endl;
				// int old_comps = comparisons;
				auto insert_before = binarySearch(main, *to_insert);
				// std::cout << "insertPendToMain() used " << comparisons - old_comps << " comps" << std::endl;
				// std::cout << "insertPendToMain(): " << to_insert->value << " before " << insert_before->value << std::endl;
				main.insert(insert_before, *to_insert);
				pend.erase(to_insert);
				if (pend.size() == 0) {
					// std::cout << "early return" << std::endl;
					return ;
				}
			} else {
				// std::cout << "findFromPend(): fail" << std::endl;
				break ;
			}
		}
	}

	// stuff remaining in pend after Jacostahl insertion
	// std::cout << "terminal" << std::endl;
	// std::cout << "insertPendToMain() remaining in pend after jthal: " << pend.size() << std::endl;
	if (pend.size() > 0) {
		// iterate in reverse 
		for (auto to_insert = pend.rbegin(); to_insert != pend.rend(); ++to_insert) {
		// for (auto to_insert = pend.begin(); to_insert != pend.end(); ++to_insert) {
			// int old_comps = comparisons;
			auto insert_before = binarySearch(main, *to_insert);
			// std::cout << "insertPendToMain() used " << comparisons - old_comps << " comps after Jthal" << std::endl;
			// std::cout << "insertPendToMain(): " << to_insert->value << " before " << insert_before->value << std::endl;
			main.insert(insert_before, *to_insert);
		}
	}
	// std::cout << "insertPendtoMain(): after" << std::endl;
	// printElems(main);
	// std::cout << "-----" << std::endl;
	// printElems(pend);
}

template <class Container>
void PMergeMe<Container>::printElems(std::vector<Elem<unsigned int>> &elems) {
	// std::cout << "printElems()" << std::endl;
	for (auto iter = elems.begin(); iter != elems.end(); iter++) {
		for (int elem_iter = iter->indices.first;
			elem_iter <= iter->indices.second; elem_iter++)
		{
			// std::cout << elem_iter << "-";
			try {
				std::cout << orig.at(elem_iter) << ", ";
			} catch (...) {
				std::cout << "printElems(): no element at: " << elem_iter << std::endl;
			}
		}
		std::cout << std::endl;
	}
}



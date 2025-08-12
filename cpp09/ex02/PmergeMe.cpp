/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:40:49 by lemercie          #+#    #+#             */
/*   Updated: 2025/08/08 19:55:20 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>


static void printVec(std::vector<unsigned int> &vec,
					 std::vector<unsigned int>::iterator iter)
{
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
void PMergeMe::swapPairs(Elem &pair_a, Elem &pair_b) {
	std::rotate(orig.begin() + pair_a.indices.first,
				orig.begin() + pair_b.indices.first,
				orig.begin() + pair_b.indices.second + 1);
}

// comparison of pairs compares the last elements
// sorts pairs of elements, not pairs of numbers, hence always advancing 
// by += 2
// TODO: maybe write a/b indices here?
/* 
static void sortPairs(std::vector<Elem> &elems) {
	auto pair_a = elems.begin();
	auto pair_b = pair_a + 1;
	while (pair_a != elems.end() && pair_b != elems.end()) {
		if (pair_a->value > pair_b->value)
		{
			std::cout << "swapping: " << pair_a->value << "-" << pair_b->value << std::endl;
			std::iter_swap(pair_a, pair_b);
			// swapPairs2(*pair_a, *pair_b);
		}
		if (std::distance(pair_b, elems.end()) > 2) {
			pair_a += 2;
			pair_b += 2;
		} else {
			break ;
		}
	}
}
 */
void PMergeMe::printElems(std::vector<Elem> &elems) {
	std::cout << "printElems()" << std::endl;
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

// iterators to elems
void	PMergeMe::moveElem(std::vector<std::pair<int, int>> &elems,
						std::vector<std::pair<int,int>>::iterator put_after,
						std::vector<std::pair<int,int>>::iterator to_move)
{
	if (std::next(to_move, 1) == elems.end()) {
		std::rotate(orig.begin() + put_after->first,
			 	orig.begin() + to_move->first,
				orig.end());
	} else {
		std::rotate(orig.begin() + put_after->first,
			 	orig.begin() + to_move->first,
				orig.begin() + (to_move + 1)->first);
	}
}

// iterators to elems
static void	moveElem2(std::vector<Elem> &elems,
						std::vector<Elem>::iterator put_after,
						std::vector<Elem>::iterator to_move)
{
	if (std::next(to_move, 1) == elems.end()) {
		std::rotate(put_after, to_move, elems.end());
	} else {
		std::rotate(put_after, to_move, to_move + 1);
	}
}
/* 
// TODO: do not change main, only shuffle elems, then later apply changes
void PMergeMe::makeMain(std::vector<std::pair<int, int>> &elems) {
	if (elems.size() < 4) {
		return ;
	}
	std::cout << "before makemain:" << std::endl;
	printVec(orig, orig.begin());
	auto tail = elems.begin() + 2;
	for (size_t i = 3; i < elems.size(); i += 2) {
		std::cout << "i: " << i << std::endl;
		std::cout << "moving: " << orig.at(elems.at(i).first) << "-";
		std::cout << orig.at(elems.at(i).second) << std::endl;
		moveElem(elems, tail, elems.begin() + i);
		if (i + 1 < elems.size()) {
			tail++;
		}
	}
	first_of_pend = tail;
	std::cout << "after makemain:" << std::endl;
	printVec(orig, orig.begin());
}
 */
// TODO: here we can sort all Elems into main and pend, then insert from pend
// to main and only after that, write main
// non participating numbers will chill at the same index at the end all the
// time
static void makeMain2(std::vector<Elem> &elems) {
	if (elems.size() < 4) {
		return ;
	}
	auto tail = elems.begin() + 2;
	for (auto it = elems.begin() + 3; it < elems.end(); it += 2) {
		moveElem2(elems, tail, it);
		if (it + 1 < elems.end()) {
			tail++;
		}
	}
	// first_of_pend = tail;
	// std::cout << "after makemain:" << std::endl;
	// printVec(orig, orig.begin());
}

// could be made to only move numbers inside the original vector to be more in
// the spirit of the exercise, where the items could be very large
// probably doable with std::rotate()
void	PMergeMe::writeOrig(std::vector<Elem> &elems, size_t first_unpaired) {
	std::vector<unsigned int> new_orig;
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

// could be made to only move numbers inside the original vector to be more in
// the spirit of the exercise, where the items could be very large
// probably doable with std::rotate()
void	PMergeMe::writeOrigFromTwoChains(
	std::vector<Elem> &a_chain,
	std::vector<Elem> &b_chain,
	size_t first_unpaired)
{

	std::cout << "writeOrigTo" << a_chain.size() << "+" << b_chain.size();
	std::cout << "first unpaired: " << first_unpaired << std::endl;
	std::vector<unsigned int> new_orig;
	auto iter_a = a_chain.begin();
	auto iter_b = b_chain.begin();
	while (true) {
		if (iter_b < b_chain.end()) {
			for (int i = iter_b->indices.first; i <= iter_b->indices.second;
				++i)
			{
				new_orig.push_back(orig.at(i));
			}
		}
		if (iter_a < a_chain.end()) {
			for (int i = iter_a->indices.first; i <= iter_a->indices.second;
				++i)
			{
				new_orig.push_back(orig.at(i));
			}
		}
		if (iter_a < a_chain.end()) {iter_a++;}
		if (iter_b < b_chain.end()) {iter_b++;}
		if (iter_a == a_chain.end() && iter_b == b_chain.end()) {
			break ;
		}
	}

	for (size_t i = first_unpaired; i < orig.size(); ++i) {
		std::cout << "writeOrigTwo(): pushing unpaired" << std::endl;
		new_orig.push_back(orig.at(i));
	}
	orig = new_orig;
	std::cout << "SIZE: " << orig.size() << std::endl;
}

static void sortPairs2(std::vector<Elem> &a_chain, std::vector<Elem> &b_chain,
					   std::vector<Elem> &elems)
{
	auto pair_a = elems.begin();
	auto pair_b = pair_a + 1;
	while (pair_a != elems.end() && pair_b != elems.end()) {
		if (pair_a->value > pair_b->value)
		{
			std::cout << "swapping: " << pair_a->value << "-" << pair_b->value << std::endl;
			Elem new_a(*pair_a);
			Elem new_b(*pair_b);
			// TODO: do we need to chain and chain index in the end?
			a_chain.push_back(new_a);
			b_chain.push_back(new_b);
			// std::iter_swap(pair_a, pair_b);
			// swapPairs2(*pair_a, *pair_b);
		} else {
			Elem new_a(*pair_b);
			Elem new_b(*pair_a);
			// TODO: do we need to chain and chain index in the end?
			a_chain.push_back(new_a);
			b_chain.push_back(new_b);
		}
		if (std::distance(pair_b, elems.end()) > 2) {
			pair_a += 2;
			pair_b += 2;
		} else {
			break ;
		}
	}
}

// TODO: unpaired elements
// elems is specific to each recursion level, therefore a local variable
void PMergeMe::miSort(unsigned int reclvl, unsigned int elemsize) {

	std::cout << "\nstarting miSort(): reclvl: " << reclvl;
	std::cout << " with vector: ";
	// printVec(vec, vec.begin());
	std::cout << std::endl;

	// terminate recursion
	if (elemsize > orig.size() / 2) {
		std::cout << "Reached end of recursion" << std::endl;
		return ;
	}

	// just holds indices of the actual vector where the numbers are
	// this will be useful across recursion levels

	std::vector<Elem> elems;
	int	first_unpaired = orig.size();

	// first and last are the first and last numbers of an element
	// on the first recursion level, they point to the same number
	size_t first = 0;
	size_t last = first + (elemsize - 1);
	while (last < orig.size()) {
		elems.push_back(Elem(first, last, orig.at(last), &comparisons));
		// elems.push_back(std::make_pair(first, last));
		if (orig.size() - last > elemsize) {
			first += elemsize;
			last += elemsize;
		} else {
			// first_unpaired = last + 1;
			// first_unpaired = last;
			break ;
		}
	}
	first_unpaired = last + 1;
	first_unpaired = last;
	std::cout << "elems: " << std::endl;
	printElems(elems);


	// NOTE: we are not regenerating elems after this, so the first Elem will
	// not be index 0 of main
	// only after sortPairs() are a/b indices relevant though
	// maybe combine creation of elems with sortPairs
	//
	std::vector<Elem> a_chain;
	std::vector<Elem> b_chain;
	sortPairs2(a_chain, b_chain, elems);
	// sortPairs(elems);

	// std::cout << "sorted elems: " << std::endl;
	// printElems(elems);

	std::cout << "ORIG: "  << std::endl;
	printVec(orig, orig.begin());

	// reflect changes in main before recursing
	writeOrigFromTwoChains(a_chain, b_chain, first_unpaired);
	// writeOrig(elems, first_unpaired);
	std::cout << "ORIG: "  << std::endl;
	printVec(orig, orig.begin());

	// recursive call
	miSort(reclvl + 1, elemsize * 2);
	std::cout << "\n#####\n";
	if (elems.size() == 2) {
		std::cout << "Penultimate recursion level" << std::endl;
		return ;
	}
	std::cout << "after recursion" << std::endl;
	std::cout << "first indices" << elems.begin()->indices.first << "-";
	std::cout << elems.begin()->indices.second << std::endl;
	printElems(elems);
	makeMain2(elems);
	writeOrig(elems, first_unpaired);
	std::cout << "ORIG: "  << std::endl;
	printVec(orig, orig.begin());


}

// TODO: give error on non integer arguments
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
	if (orig.size() == 0) {
		return ;
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

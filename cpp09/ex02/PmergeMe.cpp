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

void PMergeMe::swapPairs2(Elem &pair_a, Elem &pair_b) {
	std::rotate(orig.begin() + pair_a.indices.first,
				orig.begin() + pair_b.indices.first,
				orig.begin() + pair_b.indices.second + 1);
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

void PMergeMe::sortPairs2(std::vector<Elem> &elems) {
	auto pair_a = elems.begin();
	auto pair_b = pair_a + 1;
	while (pair_a != elems.end() && pair_b != elems.end()) {
		if (pair_a->value > pair_b->value)
		{
			std::swap(pair_a, pair_b);
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

void PMergeMe::printElems2(std::vector<Elem> &elems) {
	for (auto iter = elems.begin(); iter != elems.end(); iter++) {
		for (int elem_iter = iter->indices.first;
			elem_iter <= iter->indices.second; elem_iter++)
		{
			std::cout << orig.at(elem_iter) << ", ";
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

// TODO: do not change main, only shuffle elems, then later apply changes
void PMergeMe::makeMain(std::vector<std::pair<int, int>> &elems) {
	if (elems.size() < 4) {
		return ;
	}
	std::cout << "before makemain:" << std::endl;
	printElems(elems);
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
	printElems(elems);
	printVec(orig, orig.begin());
}

// could be made to only move numbers inside the original vector to be more in
// the spirit of hte exercise, where the items could be very large
// proobably dooable with std::rotate()
void	PMergeMe::writeOrig(std::vector<Elem> &elems) {
	std::vector<unsigned int> new_orig;
	for (auto it = elems.begin(); it != elems.end(); ++it) {
		for (int i = it->indices.first; i <= it->indices.second; ++i) {
			new_orig.push_back(orig.at(i));
		}
	}
	orig = new_orig;
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
	// std::vector<std::pair<int, int>> elems;

	std::vector<Elem> celems;

	// first and last are the first and last numbers of an element
	// on the first recursion level, they point to the same number
	size_t first = 0;
	size_t last = first + (elemsize - 1);
	while (last < orig.size()) {
		celems.push_back(Elem(first, last, orig.at(last), comparisons));
		// elems.push_back(std::make_pair(first, last));
		if (orig.size() - last > elemsize) {
			first += elemsize;
			last += elemsize;
		} else {
			// std::cout << "elements: " << elems.size() << std::endl;
			// std::cout << "lonely nums: " << std::endl;
			// begin_unpaired = last + 1;
			// printVec(orig, begin_unpaired);
			break ;
		}
	}
	std::cout << "elems: " << std::endl;
	// printElems(elems);
	printElems2(celems);
	// sortPairs(elems);
	sortPairs2(celems);
	std::cout << "sorted elems: " << std::endl;
	// printElems(elems);
	printElems2(celems);
	std::cout << "ORIG: "  << std::endl;
	printVec(orig, orig.begin());
	// reflect changes in main before recursing
	writeOrig(celems);
	std::cout << "ORIG: "  << std::endl;
	printVec(orig, orig.begin());

	// recursive call
	miSort(reclvl + 1, elemsize * 2);
	std::cout << "\n#####\n";
	// if ( elems.size() == 2) {
	if (celems.size() == 2) {
		std::cout << "Penultimate recursion level" << std::endl;
		return ;
	}

	// TODO: use t_elem for everything
	// moveElem() will have to update the indices after move

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

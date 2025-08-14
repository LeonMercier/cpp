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
/* 
static void printVec(std::vector<unsigned int> &vec,
					 std::vector<unsigned int>::iterator iter)
{
	for (auto it = iter; it != vec.end(); it++) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
}
 */
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


void PMergeMe::printElems(std::vector<Elem> &elems) {
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
/* 
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
 */
// TODO: here we can sort all Elems into main and pend, then insert from pend
// to main and only after that, write main
// non participating numbers will chill at the same index at the end all the
// time
void PMergeMe::makeMain(std::vector<Elem> &elems) {
	if (elems.size() <= 2) {
		return ;
	}

	std::vector<Elem> main;
	std::vector<Elem> pend;

	// main starts as b1 and all of 'a's; that is: first elem, second elem, 
	// then evey other elem
	main.push_back(elems.at(0));
	main.back().chain = 'b';
	main.back().chain_index = 1;
	main.push_back(elems.at(1));
	main.back().chain = 'a';
	main.back().chain_index = 1;
	for (size_t i = 2; i < elems.size(); ++i) {
		if (i % 2 == 0) {
			pend.push_back(elems.at(i));
			pend.back().chain = 'b';
			pend.back().chain_index = i;
		} else {
			main.push_back(elems.at(i));
			main.back().chain = 'a';
			main.back().chain_index = i;
		}
	}
	// std::cout << "makeMain(): main: " << std::endl;
	// printElems(main);
	// std::cout << "makeMain(): pend: " << std::endl;
	// printElems(pend);
	// std::cout << "after makemain:" << std::endl;
	// printVec(orig, orig.begin());
	insertPendToMain(main, pend);
	elems = main;
}

void PMergeMe::insertPendToMain(std::vector<Elem> &main, std::vector<Elem> &pend) {
	// TODO: do this in order of Jacobsthal numbers
	for (auto it = pend.begin(); it != pend.end(); ++it) {
		auto insert_before = binarySearch(main, *it);
		main.insert(insert_before, *it);
	}
	// std::cout <<"insertPendToMain() after: " << std::endl;
	// printElems(main);
}

std::vector<Elem>::const_iterator PMergeMe::binarySearch(
	std::vector<Elem> &main,
	Elem &to_insert)
{
	// bx is always smaller than ax
	auto insert_before = main.end();
	for (auto it = main.begin(); it != main.end(); ++it) {
		// comparison
		if (it->value > to_insert.value) {
			return it;
		}
		if (it->chain == 'a' && it->chain_index == to_insert.chain_index) {
			return it; // found the bound element
		}
	}
	return insert_before;
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

	// std::cout << "writeOrigTo: " << a_chain.size() << "+" << b_chain.size() << std::endl;
	// std::cout << "first unpaired: " << first_unpaired << std::endl;
	// return ;
	std::vector<unsigned int> new_orig;
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

// comparison of pairs compares the last numbers of each element
static void sortPairs(std::vector<Elem> &a_chain, std::vector<Elem> &b_chain,
					   std::vector<Elem> &elems)
{
	// std::cout << "sortpairs() starting with: " << elems.size() << std::endl;
	for (size_t i = 0; i < elems.size(); i += 2) {
		auto cur = elems.begin() + i;
		auto next = cur + 1;
		
		//odd element
		if (next == elems.end()) {
			b_chain.push_back(*cur);
			break;
		}
		// comparison
		if (cur->value < next->value) {
			b_chain.push_back(*cur);
			a_chain.push_back(*next);
		} else {
			b_chain.push_back(*next);
			a_chain.push_back(*cur);
		}
	}
	// std::cout << "sortPairs() end sizes: " << a_chain.size() << "+" << b_chain.size() << std::endl;
}

// TODO: unpaired elements
// elems is specific to each recursion level, therefore a local variable
void PMergeMe::miSort(unsigned int reclvl, unsigned int elemsize) {

	// std::cout << "\nstarting miSort(): reclvl: " << reclvl;
	// std::cout << " with vector: ";
	// printVec(vec, vec.begin());
	// std::cout << std::endl;

	// terminate recursion
	if (elemsize > orig.size() / 2) {
		// std::cout << "Reached end of recursion" << std::endl;
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

	// if the while condition evaluates false, then all elements are paired,
	// if break is reached then there are unpaired elements
	while (last < orig.size()) {
		elems.push_back(Elem(first, last, orig.at(last), &comparisons));
		// elems.push_back(std::make_pair(first, last));
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


	// NOTE: we are not regenerating elems after this, so the first Elem will
	// not be index 0 of main
	// only after sortPairs() are a/b indices relevant though
	// maybe combine creation of elems with sortPairs
	//
	std::vector<Elem> a_chain;
	std::vector<Elem> b_chain;
	sortPairs(a_chain, b_chain, elems);
	// sortPairs(elems);

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
	makeMain(elems);
	writeOrig(elems, first_unpaired);
	// std::cout << "ORIG: "  << std::endl;
	// printVec(orig, orig.begin());


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

	// TESTING
	std::vector<unsigned int> test = orig;
	std::sort(test.begin(), test.end());
	
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

	// TESTING
	if (orig == test) {
		std::cout << "init(): SUCCESSful sort" << std::endl;
	} else {
		std::cout << "init(): FAILed sort" << std::endl;
	}

}

bool	PMergeMe::bigger(unsigned int a, unsigned int b) {
	comparisons++;
	return (a > b);
}
	
void	PMergeMe::regenElemValues(std::vector<Elem> &elems) {
	for (auto it = elems.begin(); it != elems.end(); ++it) {
		it->value = orig.at(it->indices.second);
	}
}

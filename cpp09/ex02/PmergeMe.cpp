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

constexpr bool PRINTS = false;
constexpr bool COMPS = true;

static void sortPairs(std::vector<Elem> &a_chain, std::vector<Elem> &b_chain,
					   std::vector<Elem> &elems);
static void printVec(std::vector<unsigned int> &vec,
					 std::vector<unsigned int>::iterator iter);

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

	printVec(orig, orig.begin());
	// TESTING
	std::vector<unsigned int> test = orig;

	calcJnums();

	// printVec(jnums, jnums.begin());
	
	miSort(1, 1);

	// TESTING
	if (COMPS) {
		std::sort(test.begin(), test.end());
		if (orig == test) {
			std::cout << "init(): SUCCESSful sort: ";
			std::cout << comparisons << " comps" << std::endl;
		} else {
			std::cout << "init(): FAILed sort" << std::endl;
		}
	}
}

// Jacobstahl numbers are used to select from the pend and pend is always
// smaller than main, therefore we generate only main.size / 2 numbers
// TODO: probably should generate even fewer numbers and check for overflows,
// eg. stop when number is bigger than pend size?
void PMergeMe::calcJnums() {
	unsigned int	to_generate = orig.size() / 2;
	jnums.push_back(0);
	jnums.push_back(1);
	
	for (unsigned int generated = 2; generated <= to_generate; ++generated) {
		jnums.push_back(*(jnums.end() -1) + (2 * *(jnums.end() -2)) );
	}
}

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

	// elems just holds indices of the actual vector where the numbers are
	// this will be useful across recursion levels
	std::vector<Elem>	elems;
	int					first_unpaired = orig.size();

	// first and last are the first and last numbers of an element
	// on the first recursion level, they point to the same number
	size_t first = 0;
	size_t last = first + (elemsize - 1);

	// if the while condition evaluates false, then all elements are paired,
	// if break is reached then there are unpaired elements
	while (last < orig.size()) {
		elems.push_back(Elem(first, last, orig.at(last), &comparisons));
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

	std::vector<Elem> a_chain;
	std::vector<Elem> b_chain;

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

// comparison of pairs compares the last numbers of each element
static void sortPairs(std::vector<Elem> &a_chain, std::vector<Elem> &b_chain,
					   std::vector<Elem> &elems)
{
	// std::cout << "sortpairs() starting with: " << elems.size() << std::endl;
	for (size_t i = 0; i < elems.size(); i += 2) {
		auto cur = elems.begin() + i;
		auto next = cur + 1;
		
		// unpaired element at end
		if (next == elems.end()) {
			b_chain.push_back(*cur);
			break;
		}
		// comparison
		if (*cur < *next) {
			b_chain.push_back(*cur);
			a_chain.push_back(*next);
		} else {
			b_chain.push_back(*next);
			a_chain.push_back(*cur);
		}
	}
	// std::cout << "sortPairs() end sizes: " << a_chain.size() << "+" << b_chain.size() << std::endl;
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

void	PMergeMe::regenElemValues(std::vector<Elem> &elems) {
	for (auto it = elems.begin(); it != elems.end(); ++it) {
		it->value = orig.at(it->indices.second);
	}
}

// here we can sort all Elems into main and pend, then insert from pend
// to main and only after that, in miSort(), write orig
// non participating numbers will chill at the same index at the end all the
// time
void PMergeMe::makeMain(std::vector<Elem> &elems) {
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

	std::vector<Elem> main;
	std::vector<Elem> pend;

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

// compares indices, not values
static std::vector<Elem>::iterator findFromPend(size_t i, std::vector<Elem> &pend)
{
	for (auto it = pend.begin(); it != pend.end(); ++it) {
		if (it->chain_index == i) {
			return it;
		}
	}
	// std::cout << "not found" << std::endl;
	return pend.end();
}

void PMergeMe::insertPendToMain(std::vector<Elem> &main, std::vector<Elem> &pend) {
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
				auto insert_before = binarySearch(main, *to_insert);
				// std::cout << "insertPendToMain(): " << it->value << " before " << insert_before->value << std::endl;
				main.insert(insert_before, *to_insert);
				pend.erase(to_insert);
				if (pend.size() == 0) {
					// std::cout << "early return" << std::endl;
					return ;
				}
			} else {
				break ;
			}
		}
	}

	// stuff remaining in pend after Jacostahl insertion
	// std::cout << "terminal" << std::endl;
	if (pend.size() > 0) {
		for (auto to_insert = pend.begin(); to_insert != pend.end(); ++to_insert) {
			auto insert_before = binarySearch(main, *to_insert);
			// std::cout << "insertPendToMain(): " << to_insert->value << " before " << insert_before->value << std::endl;
			main.insert(insert_before, *to_insert);
		}
	}
	// std::cout << "insertPendtoMain(): after" << std::endl;
	// printElems(main);
	// std::cout << "-----" << std::endl;
	// printElems(pend);
}

std::vector<Elem>::const_iterator PMergeMe::binarySearch(
	std::vector<Elem> &main,
	Elem &to_insert)
{
	// std::cout << "binarySearch(): to_insert: " << to_insert.value << std::endl;
	if (main.size() == 0) {
		return main.end();
	}

	auto upper_bound = main.end();
	// compares indices, not values
	for (auto it = main.begin(); it != main.end(); ++it) {
		// std::cout << "binarySearch(): " << it->chain << "-" << it->chain_index << "==" << to_insert.chain_index << std::endl;
		if (it->chain == 'a' && it->chain_index == to_insert.chain_index) {
			// std::cout << "binarySearch(): found upper bound" << std::endl;
			upper_bound = it;
		}
	}

	int	right = upper_bound - main.begin();
	int	left = 0;
	while (left  < right) {
		size_t mid = left + ((right - left) / 2);
		// comparison
		try {
			if (to_insert < main.at(mid)) {
				right = mid;
			} else {
				left = mid + 1;
			}
		} catch (...) {
			std::cout <<"no element in main at: " << mid << std::endl;
		}
	}
	return main.begin() + left;
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

static void printVec(std::vector<unsigned int> &vec,
					 std::vector<unsigned int>::iterator iter)
{
	if (PRINTS) {
		for (auto it = iter; it != vec.end(); it++) {
			std::cout << *it << ", ";
		}
		std::cout << std::endl;
	}
}

/*
 rotate() is weird:
 template< class ForwardIt >
    void rotate( ForwardIt first, ForwardIt n_first, ForwardIt last );

    std::rotate swaps the elements in the range [first, last) in such a way
	that the element n_first becomes the first element of the new range and
	n_first - 1 becomes the last element.
*/
/* 
void PMergeMe::swapPairs(Elem &pair_a, Elem &pair_b) {
	std::rotate(orig.begin() + pair_a.indices.first,
				orig.begin() + pair_b.indices.first,
				orig.begin() + pair_b.indices.second + 1);
}
 */
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

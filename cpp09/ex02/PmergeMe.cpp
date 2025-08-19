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

// Jacobstahl numbers are used to select from the pend and pend is always
// smaller than main, therefore we generate only main.size / 2 numbers
void calcJnums(size_t orig_size, std::vector<unsigned int> &jnums) {
	jnums.push_back(0);
	jnums.push_back(1);
	
	unsigned int new_num = 0;
	while (new_num < (orig_size / 2 ) + 3) {
		new_num = *(jnums.end() -1) + (2 * *(jnums.end() -2));
		jnums.push_back(new_num);
	}
}

// comparison of pairs compares the last numbers of each element
void sortPairs(std::vector<Elem<unsigned int>> &a_chain, std::vector<Elem<unsigned int>> &b_chain,
					   std::vector<Elem<unsigned int>> &elems)
{
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
}

// compares indices, not values
std::vector<Elem<unsigned int>>::iterator findFromPend(size_t i, std::vector<Elem<unsigned int>> &pend)
{
	for (auto it = pend.begin(); it != pend.end(); ++it) {
		if (it->chain_index == i) {
			return it;
		}
	}
	return pend.end();
}

std::vector<Elem<unsigned int>>::const_iterator binarySearch(
	std::vector<Elem<unsigned int>> &main,
	Elem<unsigned int> &to_insert)
{
	if (main.size() == 0) {
		return main.end();
	}

	auto upper_bound = main.end();
	// compares indices, not values
	for (auto it = main.begin(); it != main.end(); ++it) {
		if (it->chain == 'a' && it->chain_index == to_insert.chain_index) {
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

size_t	calcAllowedComps(size_t nums) {
	size_t comps = 0;
	for (size_t i = 1; i <= nums; ++i) {
		comps += std::ceil(std::log2((3.0 / 4.0) * i));
	}
	return comps;
}

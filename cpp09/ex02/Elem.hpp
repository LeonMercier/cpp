/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Elem.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:20:11 by lemercie          #+#    #+#             */
/*   Updated: 2025/08/18 17:23:27 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <utility> // pair
#include <stddef.h> // size_t

// holds value so that we can do comparison overload
template <typename T>
class Elem {
public:
	std::pair<int, int> indices;
	char				chain;
	size_t				chain_index;
	T					value;
	int					*comparisons;

	Elem() = delete;
	Elem(int first, int last, T value, int *comparisons) :
		indices({first, last}), value(value), comparisons(comparisons) {}
	Elem(const Elem &src) = default;
	Elem &operator=(const Elem &src) = default;
	~Elem() = default;

	bool operator<(const Elem &rhs) {
		(*comparisons)++;
		return value < rhs.value;
	}
	bool operator>(const Elem &rhs) {
		(*comparisons)++;
		return value > rhs.value;
	}
};

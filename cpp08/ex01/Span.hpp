/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:12:03 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/29 17:39:32 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <stdexcept>
#include <limits>
#include <algorithm>

class Span {
public:
	Span(unsigned int size = 0);
	Span(const Span &source);
	Span &operator=(const Span &source);
	~Span();

	void	addNumber(int num);
	int		shortestSpan();
	int		longestSpan();
	
	template <typename T>
	void	superAdd(T start, T end) {
		_vec.insert(_vec.end(), start, end);
	}

private:
	std::vector<int> 			_vec;
	std::vector<int>::size_type _maxsize;
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:27:20 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/29 17:39:35 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int size) : _maxsize(size) {
	_vec.reserve(size);
}

Span::Span(const Span &source) : _vec(source._vec), _maxsize(source._maxsize) {}

Span &Span::operator=(const Span &source) {
	_maxsize = source._maxsize;
	_vec = source._vec;
	return *this;
}

Span::~Span () {}

void	Span::addNumber(int num) {
	if (_vec.size() >= _maxsize) {
		throw (std::runtime_error("cannot add element, container is full"));
	}
	_vec.push_back(num);
}

int	Span::shortestSpan() {
	if (_vec.size() <= 1) {
		throw (std::runtime_error("no span found"));
	}
	std::sort(_vec.begin(), _vec.end());
	int	shortest = std::numeric_limits<int>::max();
	for (auto iter = _vec.begin(); iter < _vec.end() - 1; iter++ ) {
		shortest = std::min(std::abs(*iter - *(iter + 1)), shortest);
	}
	return shortest;
}

int	Span::longestSpan() {
	if (_vec.size() <= 1) {
		throw (std::runtime_error("no span found"));
	}
	std::sort(_vec.begin(), _vec.end());
	return std::abs(*_vec.begin() - *(_vec.end() -1));
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:12:03 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/28 12:45:33 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <stdexcept>
#include <limits>

class Span {
public:
	Span(unsigned int size = 0);
	Span(const Span &source);
	Span &operator=(const Span &source);
	~Span();

	void	addNumber(int num);
	int		shortestSpan();
	int		longestSpan();

	//TODO: add many
	//
private:
	std::vector<int> 			_vec;
	std::vector<int>::size_type _maxsize;
};

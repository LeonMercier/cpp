/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:50:42 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/22 17:31:53 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#include <cstddef>
#include <stdexcept>

template <class T>
class Array {
private:
	T		*_arr;
	size_t	_size;

public:

	Array();
	Array(size_t size); 
	Array(const Array &source);
	Array	&operator=(const Array &source);
	T	&operator[](size_t index);
	~Array();

	size_t	size() const;
};

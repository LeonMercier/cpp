/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:50:42 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/22 16:47:45 by lemercie         ###   ########.fr       */
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

	Array();/*  {
		_arr = nullptr;
		_size = 0;
	} */

	Array(size_t size);/*   : _size(size) {
		_arr = new T[_size];
	} */
 
	Array(const Array &source);/*  : _size(source._size) {
		_arr = new T[source._size];
		for (size_t i = 0; i < _size; i++) {
			_arr[i] = source._arr[i];
		}
	} */

	Array	&operator=(const Array &source);/*  {
		delete [] _arr;
		_arr = new T[source._size];
		for (size_t i = 0; i < _size; i++) {
			_arr[i] = source._arr[i];
		}
	} */

	T	&operator[](size_t index);/*  {
		if (index >= _size) {
			throw (std::logic_error("Array out of bounds"));
		}
		return _arr[index];
	} */

	~Array();/*  {
		delete [] _arr; 
	}
 */
	size_t	size() const;/*  {
		return _size;
	} */
};

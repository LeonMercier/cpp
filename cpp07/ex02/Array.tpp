/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:50:42 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/22 16:39:57 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _arr(nullptr), _size(0) {}

template <typename T>
Array<T>::Array(size_t size) : _size(size) {
	_arr = new T[_size];
}

template <typename T>
Array<T>::Array(const Array &source) : _size(source._size) {
	_arr = new T[source._size];
	for (size_t i = 0; i < _size; i++) {
		_arr[i] = source._arr[i];
	}
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array &source) {
	delete [] _arr;
	_arr = new T[source._size];
	for (size_t i = 0; i < _size; i++) {
		_arr[i] = source._arr[i];
	}
}

template <typename T>
T	&Array<T>::operator[](size_t index) {
	if (index >= _size) {
		throw (std::logic_error("Array out of bounds"));
	}
	return _arr[index];
}

template <typename T>
Array<T>::~Array() {
	delete [] _arr; 
}

template <typename T>
size_t	Array<T>::size() const {
	return _size;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:00:42 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/18 16:04:36 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void	iter(T* arr, int length, void func(T&)) {
	for (int i = 0; i < length; i++) {
		func(arr[i]);
	}
}

template <typename T>
void	iter(T* arr, int length, void func(const T&)) {
	for (int i = 0; i < length; i++) {
		func(arr[i]);
	}
}

template <typename T>
void	testInc(T &param) {
	param++;
}

template <typename T>
void	testPrint(const T &param) {
	std::cout << param << " ";
}

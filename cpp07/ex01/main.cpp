/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:04:57 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/23 14:43:41 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void	testInc(T &param) {
	param++;
}

template <typename T>
void	testPrint(const T &param) {
	std::cout << param << " ";
}

int	main(void) {

	int		int_arr[5] = {1,2,3,4,5};
	char	chr_arr[5] = { 'a', 'b', 'c', 'd', 'e' };
	double	dbl_arr[5] = { 1.2, 2.3, 3.4, 4.5, 5.6 };
	std::string str_arr[5] = { "asd", "fgh", "jkl", "zxc", "vbn" };

	::iter(int_arr, 5, testInc<int>);
	::iter(int_arr, 5, testPrint);
	std::cout << std::endl;

	::iter(chr_arr, 5, testInc<char>);
	::iter(chr_arr, 5, testPrint);
	std::cout << std::endl;

	::iter(dbl_arr, 5, testInc<double>);
	::iter(dbl_arr, 5, testPrint);
	std::cout << std::endl;

	::iter(str_arr, 5, testPrint);
	std::cout << std::endl;
}

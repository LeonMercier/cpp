/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:46:03 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/14 17:08:02 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <cctype> // isprint()
#include <limits>
#include <sstream>
#include <iomanip>

class ScalarConverter {
public:
	static void convert(std::string input);
private:
	static std::string	char_result;
	static std::string	int_result;
	static std::string	float_result;
	static std::string	double_result;

	ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter &source) = delete;
	ScalarConverter &operator=(ScalarConverter &source) = delete;
	~ScalarConverter() = delete;
};

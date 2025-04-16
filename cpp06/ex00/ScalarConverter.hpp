/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:46:03 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/16 11:56:32 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <cctype> // isprint()
#include <limits>
#include <sstream>
#include <iomanip>

typedef enum {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	ERROR
} numType;

class ScalarConverter {
public:
	static void convert(std::string input);
private:
	static std::string	char_result;
	static std::string	int_result;
	static std::string	float_result;
	static std::string	double_result;
	// static numType		detected_type;

	ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter &source) = delete;
	ScalarConverter &operator=(ScalarConverter &source) = delete;
	~ScalarConverter() = delete;
};



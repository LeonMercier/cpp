/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:54:04 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/16 12:00:03 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string	ScalarConverter::char_result;
std::string	ScalarConverter::int_result;
std::string	ScalarConverter::float_result;
std::string	ScalarConverter::double_result;

static std::string getChar(int input) {
	std::string result = "impossible";
	if (input < std::numeric_limits<unsigned char>::min()
	 || input > std::numeric_limits<unsigned char>::max()) {
		return result;
	}
	try {
		unsigned char test_char = static_cast<unsigned char>(input);
		if (std::isprint(test_char) != 0) {
			result = test_char;
		} else {
			result = "Non displayable";
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return "impossible";
	}
	return result;
}

// there seems to be no easy solution that will produce exactly one trailing 
// zero when converting floats to strings, hence this function
static void stripTrailingZeroes(std::string &str) {
	if (str.find('.') != std::string::npos) {
		str = str.substr(0, str.find_last_not_of('0') + 2);
	}
}

static numType	detectType(std::string& input) {
	if (input.length() == 1)					{ return CHAR; }
	if (input == "nanf")						{ return FLOAT; }
	if (input == "nan")							{ return DOUBLE; }
	if (input.find('.') == std::string::npos)	{ return INT; }
	return ERROR;
}

void ScalarConverter::convert(std::string input) {
	numType detected_type = detectType(input);
	switch (detected_type) {
		case CHAR:

	}

}

// TODO: use implicit casts only for promotion, othwerwise use static casts
// TODO: handle nan and nanf inputs
// TODO: convert char to int and other numrics
// TODO: detect type of input and then cast into the other types
void ScalarConverter::convert(std::string input) {
	char_result = "impossible";
	if (input.length() == 1) {
		char_result = getChar(static_cast<int>(input[0]));
	}
	try {
		int test_int = std::stoi(input);
		int_result = std::to_string(test_int);
		if (char_result == "impossible") {
			char_result = getChar(test_int);
		}
	} catch (std::exception &e) {
		int_result = "impossible";
	}
	try {
		float_result = std::to_string(std::stof(input));
		stripTrailingZeroes(float_result);
	} catch (std::exception &e) {
		float_result = "impossible";
	}
	try {
		double_result = std::to_string(std::stod(input));
		stripTrailingZeroes(double_result);
	} catch (std::exception &e) {
		double_result = "impossible";
	}

	// TODO: impossibleF
	std::cout << "char: " << char_result << std::endl;
	std::cout << "int: " << int_result << std::endl;
	std::cout << "float: " << float_result;
	if (float_result != "impossible") {
		std::cout << "f";
	}
	std::cout << std::endl;
	std::cout << "double: " << double_result << std::endl;
}

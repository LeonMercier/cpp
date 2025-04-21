/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:54:04 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/21 16:54:43 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static std::string getChar(int input) {
	std::string result = ScalarConverter::IMPOSSIBLE;
	if (input < std::numeric_limits<unsigned char>::min()
	 || input > std::numeric_limits<unsigned char>::max()) {
		return result;
	}
	try {
		unsigned char test_char = static_cast<unsigned char>(input);
		if (std::isprint(test_char) != 0) {
			result = test_char;
		} else {
			result = "Not displayable";
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return ScalarConverter::IMPOSSIBLE;
	}
	return result;
}

// there seems to be no easy solution that will produce exactly one trailing 
// zero when converting floats to strings, hence this function
static void stripTrailingZeroes(std::string &str) {
	if (str.find('.') != std::string::npos) {
		str = str.substr(0, str.find_last_not_of('0') + 1);
	}
	if (str[str.length() -1] == '.') {
		str += '0';
	}
}

static numType	detectType(std::string& input) {
	if (input.length() == 1)					{ return CHAR; }
	/* if (input == "nanf")						{ return FLOAT; }
	if (input == "nan")							{ return DOUBLE; } */
	if (input.find('.') == std::string::npos)	{ return INT; }
	if (input[input.length() -1] == 'f')		{ return FLOAT; }
	return DOUBLE;
}

static void	printResult(std::string char_result, std::string int_result,
				 std::string float_result, std::string double_result) {
	std::cout << "char: " << char_result << std::endl;
	std::cout << "int: " << int_result << std::endl;
	std::cout << "float: " << float_result << std::endl;
	std::cout << "double: " << double_result << std::endl;
}

static void	handlePseudoLiteral(std::string input) {
	std::string	flt_result;
	std::string	dbl_result;

	if (input == "nanf" || input == "-inff" || input == "+inff" ||
		input == "inff") {
		flt_result = input;
		dbl_result = input.substr(0, input.find_last_of('f'));
	} else {
		flt_result = input + "f";
		dbl_result = input;
	}
	printResult(ScalarConverter::IMPOSSIBLE, ScalarConverter::IMPOSSIBLE,
			 flt_result, dbl_result);
}

// if a number has no '.', then it is an int. But if it's too large to fit into
// an int, we cannot convert it into float/double either
void ScalarConverter::convert(std::string input) {
	std::string	chr_result;
	std::string	int_result;
	std::string	flt_result;
	std::string	dbl_result;
	
	if (input == "nan" || input == "nanf" || input == "-inff" ||
		input == "+inff" || input == "+inf" || input == "-inf" ||
		input == "inf" || input == "inff") {
		handlePseudoLiteral(input);
		return ;
	}
	
	numType detected_type = detectType(input);
	switch (detected_type) {
		case CHAR:
			if (std::isprint(input[0]) != 0) {
				chr_result = input[0];
			} else {
				chr_result = "Not displayable";
			}
			if (std::isdigit(input[0]) != 0) {
				int_result = std::to_string(static_cast<int>(input[0] - '0'));
				flt_result = std::to_string(static_cast<float>(input[0] - '0'));
				dbl_result = std::to_string(static_cast<double>(input[0] - '0'));
			} else {
				int_result = std::to_string(static_cast<int>(input[0]));
				flt_result = std::to_string(static_cast<float>(input[0]));
				dbl_result = std::to_string(static_cast<double>(input[0]));
			}
			break;
		case INT:
			try {
				int test_int = std::stoi(input);
				chr_result = getChar(test_int);
				int_result = std::to_string(test_int);
				flt_result = std::to_string(static_cast<float>(test_int));
				dbl_result = std::to_string(static_cast<double>(test_int));
			} catch (std::exception &e) {
				chr_result = IMPOSSIBLE;
				int_result = IMPOSSIBLE;
				flt_result = IMPOSSIBLE;
				dbl_result = IMPOSSIBLE;
			}
			break ;
		case FLOAT: 
			try {
				float test_float = std::stof(input);
				double test_double = static_cast<double>(test_float);
				flt_result = std::to_string(test_float);
				chr_result = getChar(static_cast<int>(test_float));
				if (test_double >= std::numeric_limits<int>::min() &&
					test_double <= std::numeric_limits<int>::max()) {
					int_result = std::to_string(static_cast<int>(test_float));
				} else {
					int_result = IMPOSSIBLE;
				}
				dbl_result = std::to_string(static_cast<double>(test_float));
			} catch (std::exception &e) {
				chr_result = IMPOSSIBLE;
				int_result = IMPOSSIBLE;
				flt_result = IMPOSSIBLE;
				dbl_result = IMPOSSIBLE;
			}
			break ;
		case DOUBLE:
			try {
				double test_double = std::stod(input);
				dbl_result = std::to_string(test_double);
				chr_result = getChar(static_cast<int>(test_double));
				if (test_double >= std::numeric_limits<int>::min() &&
					test_double <= std::numeric_limits<int>::max()) {
					int_result = std::to_string(static_cast<int>(test_double));
				} else {
					int_result = IMPOSSIBLE;
				}
				flt_result = std::to_string(static_cast<float>(test_double));
			} catch (std::exception &e) {
				chr_result = IMPOSSIBLE;
				int_result = IMPOSSIBLE;
				flt_result = IMPOSSIBLE;
				dbl_result = IMPOSSIBLE;
			}
			break ;
		case ERROR:
			chr_result = IMPOSSIBLE;
			int_result = IMPOSSIBLE;
			flt_result = IMPOSSIBLE;
			dbl_result = IMPOSSIBLE;
	}
	if (flt_result != IMPOSSIBLE) {
		stripTrailingZeroes(flt_result);
		flt_result += "f";
	}
	stripTrailingZeroes(dbl_result);
	printResult(chr_result, int_result, flt_result, dbl_result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:46:03 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/21 13:49:43 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <cctype> // isprint()
#include <limits>

typedef enum {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	ERROR
} numType;

class ScalarConverter {
public:
	inline const static std::string IMPOSSIBLE = "impossible";
	static void convert(std::string input);
private:
	ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter &source) = delete;
	ScalarConverter &operator=(ScalarConverter &source) = delete;
	~ScalarConverter() = delete;
};



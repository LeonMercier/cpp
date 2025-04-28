/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:53:22 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/28 14:58:45 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main(void) {
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		try {
			std::cout << "Span of zero" << std::endl;
			Span zero = Span(0);
			zero.addNumber(5);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << "Span of one" << std::endl;
		Span one = Span(1);
		one.addNumber(5);
		try {
			std::cout << one.shortestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << one.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
		
		std::cout << "add elements using a range of iterators" << std::endl;
		std::vector<int> asd = {6, 3, 17, 9, 11};
		Span super(5);
		super.superAdd(asd.begin(), asd.end());
		std::cout << super.shortestSpan() << std::endl;
		std::cout << super.longestSpan() << std::endl;


	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	} catch (...) {
		std::cerr << "Error: unhandled exception" << std::endl;
	}
}

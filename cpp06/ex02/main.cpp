/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:55:08 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/15 18:31:24 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void) {
	int rnum = rand() % 3;
	switch (rnum) {
		case 0:
			std::cout << "A = ";
			return new A;
			break;
		case 1:
			std::cout << "B = ";
			return new B;
			break;
		case 2:
			std::cout << "C = ";
			return new C;
	}
	return nullptr;
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p) != nullptr) {
		std::cout << "A";
	} else if (dynamic_cast<B*>(p) != nullptr) {
		std::cout << "B";
	} else if (dynamic_cast<C*>(p) != nullptr) {
		std::cout << "C";
	} else {
		std::cout << "Error";
	}
	std::cout << std::endl;
}

void	identify(Base& p) {
	try {
		A &temp = dynamic_cast<A&>(p);
		std::cout << "A";
		(void) temp;
	} catch (...) {}
	try {
		B &temp = dynamic_cast<B&>(p);
		std::cout << "B";
		(void) temp;
	} catch (...) {}
	try {
		C &temp = dynamic_cast<C&>(p);
		std::cout << "C";
		(void) temp;
	} catch (...) {}
	std::cout << std::endl;
}

int main(void) {
	std::srand(time(NULL));
	Base *test;

	std::cout << "testing pointers" << std::endl;
	for (int i = 0; i < 10; i++) {
		test = generate();
		identify(test);
		delete test;
	}

	std::cout << "testing references" << std::endl;
	for (int i = 0; i < 10; i++) {
		test = generate();
		identify(*test);
		delete test;
	}
}

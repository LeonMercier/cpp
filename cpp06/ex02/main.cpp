/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:55:08 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/22 13:43:16 by lemercie         ###   ########.fr       */
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
			std::cout << "generating: A";
			return new A;
		case 1:
			std::cout << "generating: B";
			return new B;
		case 2:
			std::cout << "generating: C";
			return new C;
	}
	return nullptr;
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p) != nullptr) {
		std::cout << "identified: A" << std::endl;
		return ;
	}
	if (dynamic_cast<B*>(p) != nullptr) {
		std::cout << "identified: B" << std::endl;
		return ;
	}
	if (dynamic_cast<C*>(p) != nullptr) {
		std::cout << "identified: C" << std::endl;
		return ;
	}
	std::cout << "Could not identify" << std::endl;
}

void	identify(Base& p) {
	try {
		(void) dynamic_cast<A&>(p);
		std::cout << "identified: A" << std::endl;
		return ;
	} catch (...) {}
	try {
		(void) dynamic_cast<B&>(p);
		std::cout << "identified: B" << std::endl;
		return ;
	} catch (...) {}
	try {
		(void) dynamic_cast<C&>(p);
		std::cout << "identified: C" << std::endl;
		return ;
	} catch (...) {}
	std::cout << "Could not identify" << std::endl;
}

int main(void) {
	try {
		std::srand(time(NULL));
		Base *test;

		std::cout << "testing pointers" << std::endl;
		for (int i = 0; i < 10; i++) {
			test = generate();
			std::cout << ", ";
			identify(test);
			delete test;
		}

		std::cout << "testing references" << std::endl;
		for (int i = 0; i < 10; i++) {
			test = generate();
			std::cout << ", ";
			identify(*test);
			delete test;
		}
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

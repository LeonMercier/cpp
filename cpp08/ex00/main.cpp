/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:33:32 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/29 12:19:11 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <list>
#include <iostream>

#include "easyfind.hpp"

int	main(void) {
	try {
		std::cout << "Find element in vector" << std::endl;
		const std::vector<int> vec = {1, 2, 3, 4, 5};
		auto found1 = easyfind(vec, 3);
		if (found1 != vec.end()) {
			std::cout << *found1 << std::endl;
		} else {
			std::cout << "Not found" << std::endl;
		}

		std::cout << "we cannot alter the element using the returned const";
		std::cout << "iterator" << std::endl;
		for (auto iter = vec.begin(); iter != vec.end(); iter++) {
			std::cout << *iter << ", ";
		}
		std::cout << std::endl;
		//this will not compile because of constness
	//	(*found1)++;

		for (auto iter = vec.begin(); iter != vec.end(); iter++) {
			std::cout << *iter << ", ";
		}
		std::cout << std::endl << std::endl;


		std::cout << "Find element in deque" << std::endl;
		std::deque<int> deq = {1, 2, 3, 4, 5};
		auto found2 = easyfind(deq, 1);
		if (found2 != deq.end()) {
			std::cout << *found1 << std::endl;
		} else {
			std::cout << "Not found" << std::endl;
		}

		std::cout << "we can alter the element using the returned iterator"
			<< std::endl;
		for (auto iter = deq.begin(); iter != deq.end(); iter++) {
			std::cout << *iter << ", ";
		}
		std::cout << std::endl;

		(*found2)++;

		for (auto iter = deq.begin(); iter != deq.end(); iter++) {
			std::cout << *iter << ", ";
		}
		std::cout << std::endl << std::endl;


		{ //scope
			std::cout << "Find element in list" << std::endl;
			std::list<int> lst = {1, 2, 3, 4, 5};
			auto found3 = easyfind(lst, 5);
			if (found3 != lst.end()) {
				std::cout << *found3 << std::endl;
			} else {
				std::cout << "Not found" << std::endl;
			}
			std::cout << "we can alter the element using the returned iterator"
				<< std::endl;
			for (auto iter = lst.begin(); iter != lst.end(); iter++) {
				std::cout << *iter << ", ";
			}
			std::cout << std::endl;
			(*found3)++;
			for (auto iter = lst.begin(); iter != lst.end(); iter++) {
				std::cout << *iter << ", ";
			}
			std::cout << std::endl << std::endl;
		}

		{ // scope
			std::cout << "Element not in list" << std::endl;
			std::list<int> lst = {1, 2, 3, 4, 5};
			auto found3 = easyfind(lst, 6);
			if (found3 != lst.end()) {
				std::cout << *found3 << std::endl;
			} else {
				std::cout << "Not found" << std::endl;
			}
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Unhandled exception" << std::endl;
	}
}

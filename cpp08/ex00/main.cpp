/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:33:32 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/25 13:57:08 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <list>
#include <iostream>

#include "easyfind.hpp"

int	main(void) {
	std::vector<int> vec = {1, 2, 3, 4, 5};

	std::cout << "Find element in vector" << std::endl;
	std::cout << *easyfind(vec, 3) << std::endl;

	std::cout << "we can alter the element despite the iterator being const"
		<< std::endl;
	auto elem = easyfind(vec, 4);
	std::cout << *elem << std::endl;
	(*elem)++;
	std::cout << *elem << std::endl;


	std::cout << std::endl << "Find element in deque" << std::endl;
	std::deque<int> deq = {1, 2, 3, 4, 5};
	std::cout << *easyfind(deq, 3) << std::endl;

	std::cout << "we can alter the element despite the iterator being const"
		<< std::endl;
	auto elem2 = easyfind(deq, 5);
	std::cout << *elem2 << std::endl;
	(*elem2)++;
	std::cout << *elem2 << std::endl;


	std::cout << std::endl << "Find element in list" << std::endl;
	std::list<int> lst = {1, 2, 3, 4, 5};
	std::cout << *easyfind(lst, 3) << std::endl;

	std::cout << "we can alter the element despite the iterator being const"
		<< std::endl;
	auto elem3 = easyfind(lst, 5);
	std::cout << *elem3 << std::endl;
	(*elem3)++;
	std::cout << *elem3 << std::endl;
	std::cout << *easyfind(lst, 5) << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:39:53 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/25 12:25:23 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat	john("John", 0);
		std::cout << john;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat	baba("Baba", 151);
		std::cout << baba;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat	bobo("Bobo", 50);
		std::cout << bobo;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat	def;
		std::cout << def;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat	liz("Liz", 1);
		std::cout << liz;
		try {
			liz.incGrade();
			std::cout << liz;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			liz.decGrade();
			std::cout << liz;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat	minnie("Minnie", 150);
		std::cout << minnie;
		try {
			minnie.incGrade();
			std::cout << minnie;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			minnie.decGrade();
			std::cout << minnie;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			minnie.decGrade();
			std::cout << minnie;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

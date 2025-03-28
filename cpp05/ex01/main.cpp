/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:39:53 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/28 13:29:02 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	Bureaucrat	erm("Ermando", 1);
	Bureaucrat	orm("Ormando", 150);
	Form		fofo("Fofo", false, 50, 50);
	Form		fafa("Fafa", false, 50, 50);
	Form		fifi("Fifi", false, 50, 50);
	Form		fufu("Fufu", false, 50, 50);
	
	erm.signForm(fofo);
	orm.signForm(fafa);

	try {
		fifi.beSigned(erm);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << fifi.getSigned() << std::endl;

	try {
		fufu.beSigned(orm);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << fufu.getSigned() << std::endl;

}

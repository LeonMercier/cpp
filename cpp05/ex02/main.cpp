/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:39:53 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/16 16:59:21 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	try {
		std::srand(std::time(NULL));

		Bureaucrat	erm("Ermando", 1);
		Bureaucrat	orm("Ormando", 150);

		std::cout << "### Try to execute unsigned forms" << std::endl;
		RobotomyRequestForm asd("bad guy");
		try {
			asd.execute(erm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		
		PresidentialPardonForm fgh("good guy");
		try {
			fgh.execute(erm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		
		ShrubberyCreationForm jkl("tree");
		try {
			jkl.execute(erm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << std::endl;
		std::cout << "### Sign, then execute forms" << std::endl;
		erm.executeForm(asd);
		erm.signForm(asd);
		erm.executeForm(asd);

		erm.executeForm(fgh);
		erm.signForm(fgh);
		erm.executeForm(fgh);

		erm.executeForm(jkl);
		erm.signForm(jkl);
		erm.executeForm(jkl);


		std::cout << std::endl;
		std::cout << "### Fail to sign, then execute forms" << std::endl;
		orm.executeForm(asd);
		orm.signForm(asd);
		orm.executeForm(asd);

		orm.executeForm(fgh);
		orm.signForm(fgh);
		orm.executeForm(fgh);

		orm.executeForm(jkl);
		orm.signForm(jkl);
		orm.executeForm(jkl);


		std::cout << std::endl;
		std::cout << "### Test randomization" << std::endl;
		for (int i = 0; i < 10; i++) {
			erm.executeForm(asd);
		}

	} catch (...) {
		std::cout << "Error: unhandled exception" << std::endl;
	}
}

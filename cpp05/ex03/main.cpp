/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:39:53 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/21 12:48:27 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
	try {
		std::srand(std::time(NULL));

		Bureaucrat erm("Ermando", 1);
		Bureaucrat orm("Ormando", 50);
		Intern	dude;

		// non-existant form
		try {
			AForm *lol = dude.makeForm("useless form", "my house");
			delete lol;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		// non-signed forms
		AForm *shr = dude.makeForm("shrubbery creation", "my house");
		try {
			shr->execute(erm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		delete shr;

		AForm *rob = dude.makeForm("robotomy request", "my house");
		try {
			rob->execute(erm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		delete rob;

		AForm *pre = dude.makeForm("presidential pardon", "my house");
		try {
			pre->execute(erm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		delete pre;

		// sign forms first
		shr = dude.makeForm("shrubbery creation", "my house");
		try {
			erm.signForm(*shr);
			shr->execute(erm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		delete shr;

		rob = dude.makeForm("robotomy request", "my house");
		try {
			erm.signForm(*rob);
			rob->execute(erm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		delete rob;

		pre = dude.makeForm("presidential pardon", "my house");
		try {
			erm.signForm(*pre);
			pre->execute(erm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		delete pre;

	} catch (...) {
		std::cout << "Error: unhandled exception" << std::endl;
	}
}

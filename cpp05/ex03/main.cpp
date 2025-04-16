/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:39:53 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/16 17:12:10 by lemercie         ###   ########.fr       */
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
		try {
			AForm *shr = dude.makeForm("shrubbery creation", "my house");
			shr->execute(erm);
			delete shr;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			AForm *rob = dude.makeForm("robotomy request", "my house");
			rob->execute(erm);
			delete rob;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			AForm *pre = dude.makeForm("presidential pardon", "my house");
			pre->execute(erm);
			delete pre;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		// sign forms first
		try {
			AForm *shr = dude.makeForm("shrubbery creation", "my house");
			erm.signForm(*shr);
			shr->execute(erm);
			delete shr;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			AForm *rob = dude.makeForm("robotomy request", "my house");
			erm.signForm(*rob);
			rob->execute(erm);
			delete rob;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			AForm *pre = dude.makeForm("presidential pardon", "my house");
			erm.signForm(*pre);
			pre->execute(erm);
			delete pre;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

	} catch (...) {
		std::cout << "Error: unhandled exception" << std::endl;
	}
}

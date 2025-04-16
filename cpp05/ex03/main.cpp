/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:39:53 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/16 11:54:39 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

//TODO: memleak
int main(void) {
	Bureaucrat	erm("Ermando", 1);
	Bureaucrat	orm("Ormando", 50);

	Intern	dude;
	AForm *shr = dude.makeForm("shrubbery creation", "my house");
	AForm *rob = dude.makeForm("robotomy request", "my house");
	AForm *pre = dude.makeForm("presidential pardon", "my house");
	AForm *lol = dude.makeForm("useless form", "my house");

	try {
		shr->execute(erm);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		rob->execute(erm);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	erm.signForm(*pre);
	try {
		pre->execute(erm);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		if (lol != nullptr) {
			lol->execute(erm);
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:39:53 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/28 15:41:39 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	Bureaucrat	erm("Ermando", 1);
	Bureaucrat	orm("Ormando", 150);
/* 	Form		fofo("Fofo", false, 50, 50);
	erm.signForm(fofo);
	orm.signForm(fofo); */
	RobotomyRequestForm asd("bad guy");
	try {
		asd.execute(erm);
	} catch (...) {}
	
	PresidentialPardonForm fgh("good guy");
	try {
		fgh.execute(erm);
	} catch (...) {}
	
	ShrubberyCreationForm jkl("tree");
	try {
		jkl.execute(erm);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	erm.executeForm(asd);
	erm.signForm(asd);
	erm.executeForm(asd);

	erm.executeForm(fgh);
	erm.signForm(fgh);
	erm.executeForm(fgh);

	erm.executeForm(jkl);
	erm.signForm(jkl);
	erm.executeForm(jkl);

	orm.executeForm(asd);
	orm.signForm(asd);
	orm.executeForm(asd);

	orm.executeForm(fgh);
	orm.signForm(fgh);
	orm.executeForm(fgh);

	orm.executeForm(jkl);
	orm.signForm(jkl);
	orm.executeForm(jkl);

}

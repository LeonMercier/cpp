/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:39:53 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/27 17:24:41 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
	Bureaucrat	erm("Ermando", 1);
	Bureaucrat	orm("Ormando", 50);
/* 	Form		fofo("Fofo", false, 50, 50);
	erm.signForm(fofo);
	orm.signForm(fofo); */
	
/* 
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
	erm.executeForm(jkl);
 */
	Intern	dude;
	AForm *shr = dude.makeForm("shrubbery creation", "my house");
	AForm *rob = dude.makeForm("robotomy request", "my house");
	AForm *pre = dude.makeForm("presidential pardon", "my house");

	shr->execute(erm);
	rob->execute(erm);
	pre->execute(erm);
}

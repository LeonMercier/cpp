/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:19:23 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/28 15:59:03 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}
Intern::~Intern() {}

AForm *Intern::makeShr(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRob(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePre(std::string target) {
	return new PresidentialPardonForm(target);
}

// if the make* functions were not static, the function call would need to
// be prepended with this->
AForm *Intern::makeForm(std::string name, std::string target) {
	for (int i = 0; i < 3; i++) {
		if (name == _formNames[i]) {
			std::cout << "Intern creates " << name << " form" << std::endl;
			return (_functions[i])(target);
		}
	}
	std::cout << "Error: no form with such name found" << std::endl;
	return nullptr;
}

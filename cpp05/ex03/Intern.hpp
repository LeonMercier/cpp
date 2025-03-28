/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:06:44 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/28 16:20:30 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
  public:
	Intern();
	Intern(const Intern &source)			= delete;
	Intern &operator=(const Intern &source) = delete;
	~Intern();

	AForm *makeForm(std::string name, std::string target);

  private:
	static AForm *makeShr(std::string target);
	static AForm *makeRob(std::string target);
	static AForm *makePre(std::string target);
	std::string	  _formNames[3] = {"shrubbery creation", "robotomy request",
								   "presidential pardon"};
	AForm *(*_functions[3])(std::string target) = {makeShr, makeRob, makePre};
};

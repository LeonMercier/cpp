/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:10:18 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/27 12:14:16 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

#include "AForm.hpp"
class AForm;
class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &source);
	Bureaucrat &operator=(const Bureaucrat &source);
	~Bureaucrat();

	std::string getName() const;
	int			getGrade() const;
	void		incGrade();
	void		decGrade();

	void		signForm(AForm &form);
	void		executeForm(AForm const &form);

	class GradeTooHighException;
	class GradeTooLowException;

private:
	const std::string _name;
	int				  _grade;
};

std::ostream &operator<<(std::ostream &ostm, const Bureaucrat &src);

class Bureaucrat::GradeTooHighException : public std::exception {
  private:
	const std::string _msg;

  public:
	GradeTooHighException();
	const char *what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception {
  private:
	std::string _msg;

  public:
	GradeTooLowException();
	const char *what() const throw();
};

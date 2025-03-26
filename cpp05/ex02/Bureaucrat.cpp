/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:23:54 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/26 15:24:46 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default name"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1) {
		throw GradeTooHighException();
	}
	if (grade > 150) {
		throw GradeTooLowException();
	}
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &source)
	: _name(source._name), _grade(source._grade) {}

// name is const and thus cannot be reassigned
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &source) {
	if (this != &source) {
		_grade = source._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return (_name); }

int Bureaucrat::getGrade() const { return (_grade); }

void Bureaucrat::incGrade() {
	if (_grade > 1) {
		_grade--;
	} else {
		throw GradeTooHighException();
	}
}

void Bureaucrat::decGrade() {
	if (_grade < 150) {
		_grade++;
	} else {
		throw GradeTooLowException();
	}
}

void	Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
	} catch (std::exception &e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because "
			<< e.what() << std::endl;
		return ;
	}
	std::cout << _name << " signed " << form.getName() << std::endl;
}

std::ostream &operator<<(std::ostream &ostm, const Bureaucrat &src) {
	ostm << src.getName() << ", bureaucrat grade " << src.getGrade()
		 << std::endl;
	return (ostm);
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
	: _msg("Grade too high") {}

Bureaucrat::GradeTooLowException::GradeTooLowException()
	: _msg("Grade too low") {}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return (_msg.c_str());
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return (_msg.c_str());
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:38:20 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/26 13:42:27 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default name"), _signed(false), _gradeToSign(150),
	_gradeToExecute(150) {}

// _gradeToSign and _gradeToExecute have to be const, therefore they have to be
// set in the initializer list. So exceptions can only be thrown after having 
// set the values already
Form::Form(std::string name, bool sig, int gradeToSign, int gradeToExecute) :
	_name(name),
	_signed(sig),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException();
	}
}

Form::Form(const Form &source) :
	_name(source._name),
	_signed(source._signed),
	_gradeToSign(source._gradeToSign),
	_gradeToExecute(source._gradeToExecute) {}

// TODO: delete this?
Form &Form::operator=(const Form &source) {
	if (this != &source)
	{
		_signed = source._signed;
	}
	return *this;
}

Form::~Form() {}

std::string	Form::getName() const {
	return (_name);
}

bool		Form::getSigned() const {
	return (_signed);
}

int			Form::getGradeToSign() const {
	return (_gradeToSign);
}

int			Form::getGradeToExecute() const {
	return (_gradeToExecute);
}

void		Form::beSigned(Bureaucrat &bur) {
	if (bur.getGrade() > _gradeToSign) {
		throw GradeTooLowException();
	}
	_signed = true;
}

std::ostream &operator<<(std::ostream &ostm, const Form &src) {
	ostm << "Form: " << src.getName()
		<< ": Signed: " << src.getSigned()
		<< ", grade to sign: " << src.getGradeToSign() 
		<< ", grade to execute: " << src.getGradeToExecute()
		<< std::endl;
	return (ostm);
}

Form::GradeTooHighException::GradeTooHighException()
	: _msg("Grade too high") {}

Form::GradeTooLowException::GradeTooLowException()
	: _msg("Grade too low") {}

const char *Form::GradeTooHighException::what() const throw() {
	return (_msg.c_str());
}

const char *Form::GradeTooLowException::what() const throw() {
	return (_msg.c_str());
}

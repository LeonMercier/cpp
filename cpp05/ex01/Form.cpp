/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:38:20 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/25 17:50:05 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form() : _name("Default name"), _signed(false), _gradeToSign(150),
	_gradeToExecute(150) {}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) :
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute) {}

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

std::string	Form::getName() {
}

bool		Form::getSigned() {
}

int			Form::getGradeToSign() {
}

int			Form::getGradeToExecute() {
}

void		Form::beSigned(Bureaucrat bur) const {
}

class GradeTooHighException;
class GradeTooLowException;

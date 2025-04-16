/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:38:20 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/16 15:53:50 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default name"), _signed(false), _gradeToSign(150),
	_gradeToExecute(150) {}

// _gradeToSign and _gradeToExecute have to be const, therefore they have to be
// set in the initializer list. So exceptions can only be thrown after having 
// set the values already
AForm::AForm(std::string name, bool sig, int gradeToSign, int gradeToExecute,
			 std::string target) :
	_name(name),
	_signed(sig),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_target(target) 
{
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException();
	}
}

AForm::AForm(const AForm &source) :
	_name(source._name),
	_signed(source._signed),
	_gradeToSign(source._gradeToSign),
	_gradeToExecute(source._gradeToExecute),
	_target(source._target) {}

// up to interpretation whether a class that has const data members should 
// have this overload at all....
AForm &AForm::operator=(const AForm &source) {
	if (this != &source)
	{
		_signed = source._signed;
	}
	return *this;
}

AForm::~AForm() {}

std::string	AForm::getName() const {
	return (_name);
}

bool		AForm::getSigned() const {
	return (_signed);
}

int			AForm::getGradeToSign() const {
	return (_gradeToSign);
}

int			AForm::getGradeToExecute() const {
	return (_gradeToExecute);
}

std::string	AForm::getTarget() const {
	return (_target);
}

void		AForm::beSigned(Bureaucrat &bur) {
	if (bur.getGrade() > _gradeToSign) {
		throw GradeTooLowException();
	}
	_signed = true;
}

void		AForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > _gradeToExecute) {
		throw GradeTooLowException();
	}
	if (!_signed) {
		throw FormNotSignedException();
	}
	this->formAction();
}

std::ostream &operator<<(std::ostream &ostm, const AForm &src) {
	ostm << "AForm: " << src.getName()
		<< ": Signed: " << src.getSigned()
		<< ", grade to sign: " << src.getGradeToSign() 
		<< ", grade to execute: " << src.getGradeToExecute()
		<< std::endl;
	return (ostm);
}

AForm::GradeTooHighException::GradeTooHighException()
	: _msg("Grade too high") {}

AForm::GradeTooLowException::GradeTooLowException()
	: _msg("Grade too low") {}

AForm::FormNotSignedException::FormNotSignedException()
	: _msg("Form not signed") {}

const char *AForm::GradeTooHighException::what() const throw() {
	return (_msg.c_str());
}

const char *AForm::GradeTooLowException::what() const throw() {
	return (_msg.c_str());
}

const char *AForm::FormNotSignedException::what () const throw() {
	return (_msg.c_str());
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:23:54 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/24 12:30:14 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
	{
		throw GradeTooLowException();
	}
	if (grade > 150)
	{
		throw GradeTooHighException();
	}
	_grade = grade;


}

Bureaucrat::Bureaucrat(const Bureaucrat &source)
{}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &source)
{}

Bureaucrat::~Bureaucrat()
{}


std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

std::ostream &operator<<(std::ostream &ostm, const Bureaucrat &src)
{
	ostm << src.getName() << ", bureaucrat grade " << src.getGrade()
		<< std::endl;
	return (ostm);
}


Bureaucrat::GradeTooHighException::GradeTooHighException() :
	_msg("Grade too high") {}

Bureaucrat::GradeTooLowException::GradeTooLowException() :
	_msg("Grade too low") {}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return (_msg.c_str());
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return (_msg.c_str());
}

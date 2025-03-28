/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:50:21 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/28 13:32:36 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
class Bureaucrat;
class Form {
  public:
	Form();
	Form(std::string name, bool sig, int gradeToSign, int gradeToExecute);
	Form(const Form &source);
	Form &operator=(const Form &source);
	~Form();

	std::string getName() const;
	bool		getSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;
	void		beSigned(Bureaucrat &bur);

	class GradeTooHighException;
	class GradeTooLowException;

  private:
	const std::string _name;
	bool			  _signed;
	const int		  _gradeToSign;
	const int		  _gradeToExecute;
};

std::ostream &operator<<(std::ostream &ostm, const Form &src);

class Form::GradeTooHighException : public std::exception {
  public:
	GradeTooHighException();
	const char *what() const throw();

  private:
	const std::string _msg;
};

class Form::GradeTooLowException : public std::exception {
  public:
	GradeTooLowException();
	const char *what() const throw();

  private:
	const std::string _msg;
};

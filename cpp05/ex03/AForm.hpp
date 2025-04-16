/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:50:21 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/16 14:50:09 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <fstream>

#include "Bureaucrat.hpp"
class Bureaucrat;
class	AForm {
public:
	AForm();
	AForm(std::string name, bool sig, int gradeToSign, int gradeToExecute, 
	   std::string target);
	AForm(const AForm &source);
	AForm &operator=(const AForm &source);
	virtual ~AForm();

	std::string		getName() const;
	bool			getSigned() const;
	int				getGradeToSign() const;
	int				getGradeToExecute() const;
	std::string		getTarget() const;
	void			beSigned(Bureaucrat &bur);
	void			execute(Bureaucrat const &executor) const;
	virtual void	formAction() const = 0;
	
	class GradeTooHighException;
	class GradeTooLowException;
	class FormNotSignedException;
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	const std::string	_target;
};

std::ostream &operator<<(std::ostream &ostm, const AForm &src);

class AForm::GradeTooHighException : public std::exception {
  private:
	const std::string _msg;

  public:
	GradeTooHighException();
	const char *what() const throw();
};

class AForm::GradeTooLowException : public std::exception {
  private:
	std::string _msg;

  public:
	GradeTooLowException();
	const char *what() const throw();
};

class AForm::FormNotSignedException : public std::exception {
  private:
	std::string _msg;

  public:
	FormNotSignedException();
	const char *what() const throw();
};

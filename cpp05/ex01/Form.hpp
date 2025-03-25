/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:50:21 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/25 17:37:52 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Bureaucrat.hpp"

class	Form {
public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form &source);
	Form &operator=(const Form &source);
	~Form();

	std::string	getName();
	bool		getSigned();
	int			getGradeToSign();
	int			getGradeToExecute();
	void		beSigned(Bureaucrat bur) const;
	
	class GradeTooHighException;
	class GradeTooLowException;
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;
};

std::ostream &operator<<(std::ostream &ostm, const Form &src);

class Form::GradeTooHighException : public std::exception {
  private:
	const std::string _msg;

  public:
	GradeTooHighException();
	const char *what() const throw();
};

class Form::GradeTooLowException : public std::exception {
  private:
	std::string _msg;

  public:
	GradeTooLowException();
	const char *what() const throw();
};

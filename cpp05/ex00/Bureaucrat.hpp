/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:10:18 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/24 12:29:50 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class	Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &source);
	Bureaucrat	&operator=(const Bureaucrat &source);
	~Bureaucrat();

	std::string	getName() const;
	int			getGrade() const;

	class	GradeTooHighException;
	class	GradeTooLowException;
};

std::ostream &operator<<(std::ostream &ostm, const Bureaucrat &src);

class Bureaucrat::GradeTooHighException: public std::exception
{
private:
	const std::string	_msg;
public:
	GradeTooHighException();
	const char *what() const throw();
};

class Bureaucrat::GradeTooLowException: public std::exception
{
private:
	std::string	_msg;
public:
	GradeTooLowException();
	const char *what() const throw();
};

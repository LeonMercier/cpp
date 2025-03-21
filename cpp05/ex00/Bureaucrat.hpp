/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:10:18 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/21 14:09:05 by lemercie         ###   ########.fr       */
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

	std::string	getName();
	int			getGrade();

	class	GradeTooHighException;
	class	GradeTooLowException;

	

};

std::ostream &operator<<(std::ostream &ostm, const Bureaucrat &src);

class Bureaucrat::GradeTooHighException: public std::exception
{
	const char *what() const throw();
};

class Bureaucrat::GradeTooLowException: public std::exception
{
	const char *what() const throw();
};

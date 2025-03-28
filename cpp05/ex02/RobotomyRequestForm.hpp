/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:22:36 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/28 14:59:15 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
public:
	// default constructor is a constructo where all arguments have default 
	// values (indicated with = sign)
	RobotomyRequestForm(std::string target = "Default target");
	RobotomyRequestForm(const RobotomyRequestForm &source);
	RobotomyRequestForm &operator=(RobotomyRequestForm &source);
	~RobotomyRequestForm();

	void	formAction() const;
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:24:59 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/26 16:44:07 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
	AForm("Robotomy form", false, 72, 45, target)
{
	std::cout << "Shr constructor with nameattribute" << target << std::endl;
}

void	RobotomyRequestForm::formAction() const {
	std::cout << "Robotomized: " << this->getTarget() << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:24:59 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/27 16:13:48 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
	AForm("robotomy request", false, 72, 45, target) {}

// srand() has to be called for initialization before calling rand()
void	RobotomyRequestForm::formAction() const {
	std::srand(std::time(NULL));
	int	test = std::rand() % 2;
	std::cout << "* wild drilling noises *" << std::endl;
	if (test == 0) {
		std::cout << this->getTarget() << " has been robotomized successfully!"
			<< std::endl;
	} else {
		std::cout << "Robotomy of " << this->getTarget() << " failed..."
			<< std::endl;
	}
}

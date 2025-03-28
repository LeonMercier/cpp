/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:44:24 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/28 15:07:43 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("Presidential form", false, 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm &source)
	: AForm(source) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &source) {
	if (this != &source) {
		AForm::operator=(source);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::formAction() const {
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox"
			  << std::endl;
}

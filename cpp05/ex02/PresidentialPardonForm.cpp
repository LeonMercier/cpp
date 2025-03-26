/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:44:24 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/26 16:50:48 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
	AForm("Presidential form", false, 25, 5, target)
{
	std::cout << "Shr constructor with nameattribute" << target << std::endl;
}

void	PresidentialPardonForm::formAction() const {
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox"
		<< std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:44:24 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/27 16:14:19 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
	AForm("presidential pardon", false, 25, 5, target) {}

void	PresidentialPardonForm::formAction() const {
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox"
		<< std::endl;
}

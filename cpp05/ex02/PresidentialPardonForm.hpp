/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:22:36 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/26 16:49:27 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	// default constructor is a constructo where all arguments have default 
	// values (indicated with = sign)
	PresidentialPardonForm(std::string target = "Default target");

	void	formAction() const;

};

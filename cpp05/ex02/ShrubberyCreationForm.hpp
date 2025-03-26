/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:22:36 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/26 16:25:31 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
	// default constructor is a constructor where all arguments have default 
	// values (indicated with = sign)
	ShrubberyCreationForm(std::string target = "Default target");

};

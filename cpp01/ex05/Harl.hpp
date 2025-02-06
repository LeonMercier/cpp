/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:52:26 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/06 15:31:02 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
# include <iostream>
# include <string>

class	Harl
{
private:
	std::string	_lvl_names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*_funcs[4])() = {&Harl::debug, &Harl::info, &Harl::warning,
		&Harl::error};

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
public:
	void	complain(std::string level);
};
#endif

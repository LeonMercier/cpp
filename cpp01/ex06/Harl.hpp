/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:22:53 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/06 15:45:14 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
# include <iostream>
# include <string>

class	Harl
{
private:
	void (Harl::*_funcs[4])() = {&Harl::debug, &Harl::info, &Harl::warning,
		&Harl::error};

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
public:
	std::string	lvl_names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void	complain(std::string level);
};
#endif

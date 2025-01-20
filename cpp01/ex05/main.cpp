/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:29:09 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/20 11:49:16 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	harlie;

	harlie.complain("DEBUG");
	harlie.complain("INFO");
	harlie.complain("WARNING");
	harlie.complain("ERROR");

	harlie.complain("asd");
	harlie.complain("");

	Harl	horl;
	horl.complain("DEBUG");
}

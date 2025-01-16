/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:29:09 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/16 14:34:47 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl harlie;

	harlie.complain("DEBUG");
	harlie.complain("INFO");
	harlie.complain("WARNING");
	harlie.complain("ERROR");
}

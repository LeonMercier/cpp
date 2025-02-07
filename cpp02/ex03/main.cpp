/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:37:26 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/07 18:44:58 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point a(0,0);
	Point b(0, 100);
	Point c(100, 0);
	Point d(0, 5);

	if (bsp(a, b, c, d))
	{		
		std::cout << "inside" << std::endl;
	}
	else
	{
		std::cout << "outside or on edge" << std::endl;
	}
	return 0;
}

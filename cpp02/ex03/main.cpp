/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:37:26 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/13 13:30:17 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

Fixed	dotProd(Point p_a, Point p_b, Point p_c)
{
	return ((p_c.getY() - p_b.getY()) * (p_a.getX() - p_b.getX()) + 
			(p_b.getX() - p_c.getX()) * (p_a.getY() - p_b.getY()));
}

// idea: if the point lies to the same side of each edge of the triangle, 
// then it is inside. This is tested by checking if all dot products have the
// same sign 
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	prod_a = dotProd(point, a, b);
	Fixed	prod_b = dotProd(point, b, c);
	Fixed	prod_c = dotProd(point, c, a);

	if (prod_a > 0 && prod_b > 0 && prod_c > 0)
	{
		return (true);
	}
	if (prod_a < 0 && prod_b < 0 && prod_c < 0)
	{
		return (true);
	}
	return (false);
}

void	test( Point const a, Point const b, Point const c, Point const point)
{
	std::cout << "Point " << point << " is";
	if (bsp(a, b, c, point))
	{
		std::cout << " inside of";
	}
	else
	{
		std::cout << " outside or on the edge of";
	}
	std::cout << " triangle " << a << "; " << b << "; " << c << std::endl;
}

int main( void )
{
	Point a(0,0);
	Point b(0, 100);
	Point c(100, 0);

	test(a, b, c, Point(0, 5));
	test(a, b, c, Point(1, 5));
	test(a, b, c, Point(-1, 5));
	test(a, b, c, Point(101, 101));
	test(a, b, c, Point(-1, 0));
	test(a, b, c, Point(0, -1));
	test(a, b, c, Point(50, 0));
	test(a, b, c, Point(0, 50));
	return 0;
}

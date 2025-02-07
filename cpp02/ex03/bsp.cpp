/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:49:09 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/07 18:37:33 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	dotProd(Point p_a, Point p_b, Point p_c)
{
	// return ((p_a.getX() - p_c.getX()) * (p_b.getY() - p_c.getY()) -
 //  		(p_b.getX() - p_c.getX()) * (p_a.getY() - p_c.getY()));

	return ((p_c.getY() - p_b.getY()) * (p_a.getX() - p_b.getX()) + 
			(-1 * p_c.getX() + p_b.getX()) * (p_a.getY() - p_b.getY()));
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

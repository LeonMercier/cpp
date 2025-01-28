/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:45:10 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/28 12:46:36 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


Point::Point() : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {}

Point::Point(const Point &source) : x(source.x), y(source.y) {}

// this is made in a weird way because the data members are required to be const
Point &Point::operator=(const Point &source)
{
	if (this != &source)
	{
		Point *p = new Point(source);
		this->~Point();
		return (*p);
	}
	return (*this);
}

Point::~Point() {}

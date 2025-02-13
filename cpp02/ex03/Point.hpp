/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:44:16 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/13 13:04:42 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

# include "Fixed.hpp"

class	Point {
private:
	const Fixed	x;
	const Fixed	y;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point &source);
	~Point();
	
	Point &operator=(const Point &source);

	const Fixed	&getX() const;
	const Fixed	&getY() const;
};

std::ostream	&operator<<(std::ostream &ostm, const Point &point);
#endif

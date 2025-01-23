/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:27:32 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/23 15:16:51 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_num = 0;
}

Fixed::Fixed(const int num)
{
	if (num == 0)
	{
		_num = 0;
	}
	else if (num > 0)
	{
		_num = num << _FRACTIONAL_BITS;
		//shift left as many time as there are fractional bits
	}
	else
	{
		_num = 0;
		//take twos complement
	}
}

Fixed::Fixed(const float num)
{
	_num = (int) num;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &source)
{
	_num = source._num;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& source)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &source)
	{
		_num = source._num;
	}
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_num);
}

void	Fixed::setRawBits(int const raw)
{
	_num = raw;
}

float	Fixed::toFloat(void) const
{
	return (0);
}

int		Fixed::toInt(void) const
{
	return (0);
}

std::ostream&	operator<<(std::ostream &ostm, const Fixed &fixed)
{
	ostm << fixed.toFloat();
	return (ostm);
}



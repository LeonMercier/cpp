/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:27:32 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/23 18:13:51 by lemercie         ###   ########.fr       */
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
	}
	else
	{
		_num = 0;
		//take twos complement
	}
}

Fixed::Fixed(const float num)
{
	_num = (int) num << _FRACTIONAL_BITS;
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
	// maybe extract fractional part by bitwise and with 00000011111111
	// where 1's are for fractional
	// but mask then depends on _fractional_bits
	// take 0xFFFFFF and shift it left _fractional bits times, then invert it
	return ((float) (_num >> _FRACTIONAL_BITS));
}

int		Fixed::toInt(void) const
{
	return (_num >> _FRACTIONAL_BITS);
}

std::ostream&	operator<<(std::ostream &ostm, const Fixed &fixed)
{
	ostm << fixed.toFloat();
	return (ostm);
}



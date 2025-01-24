/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:27:32 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/24 16:50:02 by lemercie         ###   ########.fr       */
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

Fixed::Fixed(const float flo)
{
	int	int_part;
	int	frac_part;
	// TODO: use roundf() here to only take _fractional bits decimals
	int_part = (int) flo;
	// remove the integer part from the float
	// then shift the fractional part so it becomes integer
	frac_part = (int) ((flo - int_part) * (1 << _FRACTIONAL_BITS));
	_num = int_part << _FRACTIONAL_BITS;
	_num += frac_part;
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
	int	int_part;
	int	frac_part;
	float	ret;

	int_part = _num >> _FRACTIONAL_BITS;
	frac_part = _num - (int_part << _FRACTIONAL_BITS);
	ret = ((float) int_part) +  (((float) frac_part) / (1 << _FRACTIONAL_BITS));
	return (ret);
}

int		Fixed::toInt(void) const
{
	int	int_part;
	int	frac_part;

	int_part = _num >> _FRACTIONAL_BITS;
	frac_part = _num - (int_part << _FRACTIONAL_BITS);
	if (frac_part > (1 << _FRACTIONAL_BITS) /2 -1) // frac_part > 127
	{
		int_part++; // rounding up
	}
	return (int_part);
}

std::ostream&	operator<<(std::ostream &ostm, const Fixed &fixed)
{
	ostm << fixed.toFloat();
	return (ostm);
}



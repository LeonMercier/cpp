/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:27:32 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/21 15:15:31 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_num = 0;
}

Fixed::Fixed(const int num)
{}

Fixed::Fixed(const float num)
{}

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

std::ostream&	Fixed::operator<<(std::ostream &ostm) const
{
	ostm << _num;
	return (ostm);
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
{}

int		Fixed::toInt(void) const
{}

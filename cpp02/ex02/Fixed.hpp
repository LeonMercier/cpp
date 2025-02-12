/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:15:41 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/12 12:48:53 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
private:
	int					_num;
	const static int	FRACTIONAL_BITS = 8;
public:
	Fixed();
	Fixed(const int num);
	Fixed(const float flo);
	Fixed(const Fixed &source);
	~Fixed();

	Fixed&	operator=(const Fixed &source);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	// prefix increment
	Fixed	&operator++();
	//postfix increment
	Fixed	operator++(int);
	// prefix decrement
	Fixed	&operator--();
	// postfix decrement
	Fixed	operator--(int);

	static Fixed		&min(Fixed &lhs, Fixed &rhs);
	static const Fixed	&min(const Fixed &lhs, const Fixed &rhs);
	static Fixed		&max(Fixed &lhs, Fixed &rhs);
	static const Fixed	&max(const Fixed &lhs, const Fixed &rhs);

	static int		getFracBits(void);

};

std::ostream	&operator<<(std::ostream &ostm, const Fixed &fixed);

//TODO these have to be member functions
Fixed	operator+(const Fixed &lhs, const Fixed &rhs);
Fixed	operator-(const Fixed &lhs, const Fixed &rhs);
Fixed	operator*(const Fixed &lhs, const Fixed &rhs);
Fixed	operator/(const Fixed &lhs, const Fixed &rhs);

bool	operator>(const Fixed &lhs, const Fixed &rhs);
bool	operator<(const Fixed &lhs, const Fixed &rhs);
bool	operator>=(const Fixed &lhs, const Fixed &rhs);
bool	operator<=(const Fixed &lhs, const Fixed &rhs);
bool	operator==(const Fixed &lhs, const Fixed &rhs);
bool	operator!=(const Fixed &lhs, const Fixed &rhs);

int		getFracBits(void);

#endif

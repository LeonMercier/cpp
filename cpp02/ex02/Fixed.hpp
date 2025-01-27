/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:15:41 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/27 13:24:23 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class	Fixed
{
private:
	int	_num;
	const static int _FRACTIONAL_BITS = 8;
public:
	Fixed();
	Fixed(const int num);
	Fixed(const float flo);
	~Fixed();
	Fixed(const Fixed &source);
	Fixed& operator=(const Fixed &source);

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


};

std::ostream	&operator<<(std::ostream &ostm, const Fixed &fixed);

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

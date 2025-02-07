/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:15:41 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/07 14:51:40 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <cmath>

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
};

std::ostream	&operator<<(std::ostream &ostm, const Fixed &fixed);

#endif

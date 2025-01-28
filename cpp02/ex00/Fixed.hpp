/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:15:41 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/28 11:49:39 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed
{
private:
	int	_num;
	const static int FRACTIONAL_BITS = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &source);
	Fixed& operator=(const Fixed &source);

	int	getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif

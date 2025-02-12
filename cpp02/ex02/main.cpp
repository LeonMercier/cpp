/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:37:26 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/12 12:52:17 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const	c( Fixed( 5.05f ) / Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::max( c, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << Fixed::min( c, b ) << std::endl;

	Fixed d(14.1f);
	Fixed e(5.3f);
	std::cout << "Addition: " << d + e << std::endl;
	std::cout << "Substraction: " << d - e << std::endl;
	std::cout << "Multiplication: " << d * e << std::endl;
	std::cout << "Division: " << d / e << std::endl;

	std::cout << e.toFloat() << std::endl;

	Fixed f(1);
	Fixed g(3);
	std::cout << "Division: " << f / g << std::endl;

	return 0;
}

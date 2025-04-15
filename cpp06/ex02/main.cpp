/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:55:08 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/15 17:05:17 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

Base*	generate(void) {
	return new A;
}

void	identify(Base* p) {
	(void) p;
}

void	identify(Base& p) {
	(void) p;
}

int main(void) {
	Base* test = generate();
	identify(test);
}

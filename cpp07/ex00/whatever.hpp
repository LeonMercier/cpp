/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:31:39 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/18 14:54:33 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// apparently "typename" and "class" would be equivalent in the context of this
// exercise

template<typename T>
void	swap(T& a, T& b) {
	T	temp;

	temp = a;
	a = b;
	b = temp;
}

template<typename T>
T	min(T& a, T& b) {
	if (a < b) { return a; }
	return b;
}

template<typename T>
T	max(T& a, T& b) {
	if (a > b) { return a; }
	return b;
}

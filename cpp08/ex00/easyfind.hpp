/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:16:29 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/28 12:04:15 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// if this function were to take a const reference to container as parameter,
// then it would also have to return a T::const_iterator
template <typename T>
typename T::iterator easyfind(T &cont, const int to_find) {
	for (auto iter = cont.begin(); iter != cont.end(); iter++) {
		if (*iter == to_find) {
			return iter;
		}
	}
	return cont.end();
}

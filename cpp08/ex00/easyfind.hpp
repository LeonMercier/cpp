/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:16:29 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/25 13:54:21 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
typename T::iterator easyfind(T &cont, const int to_find) {
	for (auto iter = cont.begin(); iter != cont.end(); iter++) {
		if (*iter == to_find) {
			return iter;
		}
	}
	return cont.end();
}

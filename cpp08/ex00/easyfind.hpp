/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:16:29 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/29 17:02:34 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &cont, const int &to_find) {
	return std::find(cont.begin(), cont.end(), to_find);
}

// because if this function takea a const reference to container as parameter,
// then it also has to return a T::const_iterator
template <typename T>
typename T::const_iterator easyfind(const T &cont, const int &to_find) {
	return std::find(cont.begin(), cont.end(), to_find);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:21:15 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/15 16:37:18 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data *ptr) {
	return reinterpret_cast<std::uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

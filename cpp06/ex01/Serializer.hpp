/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:07:43 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/16 17:18:31 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdint>
#include <string>
#include <iostream>
#include "Data.hpp"

class Serializer {
public:
	static uintptr_t	serialize(Data *ptr);
	static Data*		deserialize(uintptr_t raw);
private:
	Serializer() = delete;
	Serializer(const Serializer &source) = delete;
	Serializer &operator=(Serializer &source) = delete;
	~Serializer() = delete;
};

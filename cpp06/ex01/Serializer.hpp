/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:07:43 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/15 16:31:16 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdint>
#include <string>
#include <iostream>

typedef struct SData {
	std::string	name;
	int			value;
}	Data;

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

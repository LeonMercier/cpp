/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:18:37 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/22 12:57:55 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Data {
public:
	std::string	name;
	int			value;

	Data() = default;
	Data(Data &source) = default;
	Data &operator=(Data &source) = default;
	~Data() = default;
};


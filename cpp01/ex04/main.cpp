/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:56:23 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/15 16:17:36 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string	find_and_replace(std::string line, std::string to_find,
							 std::string replacement)
{
	size_t	pos = 0;
	while (true)
	{
		pos = line.find(to_find, pos);
		if (pos == std::string::npos)
		{
			break ;
		}
		line.erase(pos, to_find.length());
		line.insert(pos, replacement);
		pos += replacement.length();
	}
	return (line);
}

// TODO: handle replacing null terminator
int	main(int argc, char **argv)
{
	std::string	filename;
	std::string	line;
	std::ifstream	instream;
	std::ofstream	outstream;

	if (argc != 4)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return (1);
	}
	filename = argv[1];
	instream.open(filename.c_str());
	if (!instream.is_open())
	{
		std::cout << "Error: could not open ";
		std::cout << "'" << filename << "'" << std::endl;
		return (1);
	}
	outstream.open((filename + ".replace").c_str());
	if (!outstream.is_open())
	{
		std::cout << "Error: could not open ";
		std::cout << "'" << filename << ".replace" << "'" << std::endl;
		return (1);
	}
	while (getline(instream, line))
	{
		outstream << find_and_replace(line, argv[2], argv[3]);
		outstream << '\n';
	}
}

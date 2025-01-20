/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:56:23 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/20 14:23:48 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

std::string	findAndReplace(std::string line, std::string to_find,
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

void	openFiles(std::string filename, std::ifstream &instream,
				std::ofstream &outstream)
{
	instream.open(filename.c_str());
	if (!instream.is_open())
	{
		std::cout << "Error: could not open ";
		std::cout << "'" << filename << "'" << std::endl;
		std::exit(1);
	}
	outstream.open((filename + ".replace").c_str());
	if (!outstream.is_open())
	{
		std::cout << "Error: could not open ";
		std::cout << "'" << filename << ".replace" << "'" << std::endl;
		std::exit(1);
	}
}

int	main(int argc, char **argv)
{
	std::string		filename;
	std::string		line;
	std::ifstream	instream;
	std::ofstream	outstream;
	std::string		to_find;
	std::string		replacement;

	if (argc != 4)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return (1);
	}
	filename = argv[1];
	to_find = argv[2];
	replacement = argv[3];
	if (to_find.length() == 0)
	{
		std::cout << "nothing to replace" << std::endl;
		return (0);
	}
	openFiles(filename, instream, outstream);
	while (getline(instream, line))
	{
		outstream << findAndReplace(line, to_find, replacement);
		outstream << '\n';
	}
}

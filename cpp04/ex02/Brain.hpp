/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:14:21 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/03 14:49:04 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <string>
# include <iostream>

class	Brain {
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain &source);
	Brain	&operator=(const Brain &source);
	~Brain();

	void		putIdea(int index, std::string idea);
	std::string	getIdea(int index) const;
};
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:10:41 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/03 16:50:26 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria *_inventory[4];
public:
	Character(std::string name);
	Character(const Character &source);
	 ~Character();
	Character & operator=(const Character &source);
	 std::string const & getName() const;
	 void equip(AMateria* m);
	 void unequip(int idx);
	 void use(int idx, ICharacter& target);
};

#endif

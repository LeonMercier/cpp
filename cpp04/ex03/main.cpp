/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:31:30 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/03 17:52:02 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void	copyTest(Character cha, Character target)
{
	cha.use(0, target);
}

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	Character john("John");
	Character dave("Dave");
	Character bork("Borko");
	AMateria* mat = new Ice();
	AMateria* mat2 = new Cure();
	AMateria* mat3 = new Cure();
	std::cout << john.getName() << std::endl;
	std::cout << dave.getName() << std::endl;
	dave.unequip(0);
	dave.unequip(1);
	dave.unequip(2);
	dave.unequip(3);
	dave.equip(mat);
	dave.equip(mat2);
	dave.use(0, bork);
	dave.use(1, bork);
	dave.unequip(1);
	std::cout << "do nothing" << std::endl;
	dave.use(1, bork);
	dave.equip(mat2); // equip it again so it can be destroyed by ~Character 

	john = dave;
	std::cout << john.getName() << std::endl;
	std::cout << dave.getName() << std::endl;
	dave.use(0, bork);
	dave.use(1, bork);

	std::cout << "deep copy constructor" << std::endl;
	copyTest(dave, bork);

	// deep copy assignement
	{
		Character temp("temp");
		temp.equip(mat3);
		dave = temp;
	}
	std::cout << "deep copy assigement" << std::endl;
	dave.use(0, bork);

	delete bob;
	delete me;
	delete src;

	return (0);
}

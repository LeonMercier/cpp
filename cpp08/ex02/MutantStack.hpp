/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:12:59 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/28 16:23:14 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>

template <class T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() = default;
	MutantStack(const MutantStack &source) = default;
	MutantStack& operator=(const MutantStack &source) = default;
	~MutantStack() = default;

	// container_type is whatever container std::stack is using under the hood
	// so here we allow using that typename with just the name 'iterator'
	typedef typename std::stack<T>::container_type::iterator
													iterator;
	typedef typename std::stack<T>::container_type::const_iterator
													const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator
													reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator
													const_reverse_iterator;

	// the 'c' data member is the underlying container of the std::stack
	iterator				begin() { return this->c.begin(); };
	const_iterator			cbegin() { return this->c.cbegin(); };

	iterator				end() { return this->c.end(); };
	const_iterator			cend() { return this->c.cend(); };

	reverse_iterator 		rbegin() { return this->c.rbegin(); };
	const_reverse_iterator	crbegin() { return this->c.crbegin(); };

	reverse_iterator		rend() { return this->c.rend(); };
	const_reverse_iterator	crend() { return this->c.crend(); };


};

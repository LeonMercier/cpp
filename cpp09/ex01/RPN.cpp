/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:13:38 by lemercie          #+#    #+#             */
/*   Updated: 2025/05/05 13:56:29 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool	isOperator(char chr) {
	std::string operators = "+-*/";
	return operators.find(chr) != std::string::npos;
}

static void	doCalc(std::stack<int> &stack, char oper) {
	if (stack.size() < 2) {
		throw (std::runtime_error("not enough operands"));
	}
	int num_b = stack.top();
	stack.pop();
	int num_a = stack.top();
	stack.pop();

	switch (oper) {
		case '+':
			stack.push(num_a + num_b);
			break ;
		case '-':
			stack.push(num_a - num_b);
			break ;
		case '*':
			stack.push(num_a * num_b);
			break ;
		case '/':
			stack.push(num_a / num_b);
	}


}


void	RPN(std::string input) {
	std::istringstream iss(input);
	char	token;
	std::stack<int> stack;

	// the >> operator skips whitespace by default
	while (iss >> token) {
		if (isOperator(token)) {
			doCalc(stack, token);
		} else {
			if (std::isdigit(token) != 0) {
				stack.push(token - '0');
			} else {
				throw (std::runtime_error("invalid input"));
			}
		}
	}
	std::cout << "result: " << stack.top() << std::endl;
}

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

	using intlims = std::numeric_limits<int>;

	switch (oper) {
		case '+':
			if ((num_b > 0 && num_a > intlims::max() - num_b) ||
				(num_b < 0 && num_a < intlims::min() - num_b)) {
				throw (std::runtime_error("integer under/overflow detected"));
			}
			stack.push(num_a + num_b);
			break ;
		case '-':
			if ((num_b < 0 && num_a > intlims::max() + num_b) ||
				(num_b > 0 && num_a < intlims::min() + num_b)) {
				throw (std::runtime_error("integer under/overflow detected"));
			}
			stack.push(num_a - num_b);
			break ;
		case '*':
			if (num_b != 0 && num_a > intlims::max() / num_b) {
				throw (std::runtime_error("integer under/overflow detected"));
			}
			stack.push(num_a * num_b);
			break ;
		case '/':
			if (num_b == 0) {
				throw (std::runtime_error(
					"division by zero: universe terminating in: 3..2..1."));
			}
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
			// without this check, '-1' would be interpreted as an operator
			if (std::isdigit(iss.peek()) != 0) {
				throw (std::runtime_error(
					"Error: input error (negative numbers are not supported)"));
			}
			doCalc(stack, token);
		} else {
			if (std::isdigit(token) != 0) {
				stack.push(token - '0');
			} else {
				throw (std::runtime_error("Error: non-numeric input"));
			}
		}
	}
	if (stack.size() == 0) {
		throw (std::runtime_error("Error: empty input"));
	} 
	std::cout << stack.top() << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:18:48 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/30 15:27:28 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void readAccount(
	std::map<timepoint, double> & db, std::string filename) {

	std::ifstream file(filename);
	std::string line;
	while (getline(file, line)) {
		
		// do stuff
	}
	file.close();
}

// account: date | value
// rates: date,value
void	btc(std::string filename_account) {
	std::map<timepoint, double> account;
	readAccount(account, filename_account);
	//std::map account = read account
	//std::map rates = read rates

}

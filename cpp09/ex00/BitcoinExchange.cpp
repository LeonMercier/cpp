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
	(void) db;

	std::ifstream file(filename);
	if (!file.is_open()) {
		throw (std::runtime_error("could not open file: " + filename));
	}
	std::string line;
	std::string delim = ",";
	while (getline(file, line)) {
		std::string date_str = line.substr(0, line.find(delim));
		std::string val_str = line.erase(0, date_str.length() + delim.length());
		std::cout << date_str << " * " << val_str << std::endl;
		struct std::tm tm;
		std::get_time(); // needs a string stream
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

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

// mktime() modifies its argument on succesful conversion
void readAccount(
	std::map<timepoint, double> & db, std::string filename) {
	(void) db;

	std::ifstream file(filename);
	if (!file.is_open()) {
		throw (std::runtime_error("could not open file: " + filename));
	}
	std::string line;
	std::string delim = ",";
	getline(file, line);
	while (getline(file, line)) {
		std::string date_str(line.substr(0, line.find(delim)));
		std::tm date;
		std::tm test_date;
		std::istringstream date_stream(date_str);
		date_stream >> std::get_time(&date, "%Y-%m-%d");
		test_date = date;
		std::mktime(&test_date);
		if (test_date.tm_year != date.tm_year
			|| test_date.tm_mon != date.tm_mon
			|| test_date.tm_mday != date.tm_mday) {
			std::cout << "bad date validatioon: "  << date_str << std::endl;
		} else {
			std::cout << "OK: " << std::put_time(&date, "%c") << std::endl;
		}
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

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

// IDEA: rates can be a map, account can be just parsed line by line
//

// safer for this to get passed by value as mktime() modifies its argument
bool isValidDate(std::tm date) {
	// curly brances are needed to initialize std::tm
	struct std::tm test_date{};
	test_date = date;
	std::mktime(&test_date);
	if (test_date.tm_year != date.tm_year
		|| test_date.tm_mon != date.tm_mon
		|| test_date.tm_mday != date.tm_mday) {
		return false;
	} 
	return true;
}

// mktime() modifies its argument on succesful conversion
void readRates(
	std::map<std::time_t, double> &rates, std::string filename) {

	std::ifstream file(filename);
	if (!file.is_open()) {
		throw (std::runtime_error("could not open file: " + filename));
	}

	std::string line;
	std::string delim = ",";
	getline(file, line);
	if (line != "date,exchange_rate") {
		throw (std::runtime_error("wrong csv format"));
	}

	while (getline(file, line)) {
		std::string date_str(line.substr(0, line.find(delim)));
		std::string value_str(line.substr(
			date_str.length() + delim.length(),
			line.length() - date_str.length() ));
		// curly brances are needed to initialize std::tm
		struct std::tm date{};
		std::istringstream date_stream(date_str);
		date_stream >> std::get_time(&date, "%Y-%m-%d");
		if (isValidDate(date)) {
			double rate = std::stod(value_str);
			if (rate < 0) {
				throw (std::runtime_error("bad rate in csv file"));
			}
			rates.insert({std::mktime(&date), rate});
		} else {
			throw (std::runtime_error("bad date in csv file"));
		}
	}
	// for (auto iter = rates.begin(); iter != rates.end(); iter++) {
	// 	std::cout << iter->first << ": " << iter->second << std::endl;
	// }
	file.close();
}

double getRate(std::map<std::time_t, double> &rates, std::time_t time) {
	auto rate = rates.find(time);
	if (rate != rates.end()) {
		return rate->second;
	}
	auto iter = rates.lower_bound(time);
	if (iter == rates.begin()) {
		return 0;
	}
	if (iter != rates.end()) {
		iter--;
		return iter->second;
	}
	return 0;
}

void	processAcc(std::map<std::time_t, double> &rates, std::string filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		throw (std::runtime_error("could not open file: " + filename));
	}
	std::string line;
	std::string delim = " | ";
	getline(file, line);
	if (line != "date | value") {
		throw (std::runtime_error("wrong input format"));
	}
	while (getline(file, line)) {
		std::string date_str(line.substr(0, line.find(delim)));
		if (date_str.length() + delim.length() >= line.length()) {
			std::cerr << "Error: bad input => " << date_str << std::endl;
			continue ;
		}
		std::string value_str(line.substr(
			date_str.length() + delim.length(),
			line.length() - date_str.length() ));
		if (value_str.length() == 0) {
			std::cerr << "Error: bad input => " << date_str << std::endl;
			continue ;
		}
		// curly braces are needed to initialize std::tm
		struct std::tm date{};
		std::istringstream date_stream(date_str);
		date_stream >> std::get_time(&date, "%Y-%m-%d");
		if (isValidDate(date)) {
			double value;
			try {
				value = std::stod(value_str);
			} catch (...) {
				std::cerr << "Error: bad input => " << date_str << std::endl;
				continue ;
			}
			if (value < 0) {
				std::cerr << "Error: not a positive number." << std::endl;
			} else if (value > 1000) {
				std::cerr << "Error: too large a number." << std::endl;
			} else {
				double rate = getRate(rates, std::mktime(&date));
				std::cout << std::put_time(&date, "%c")
					<< " => " << value << " = " << value * rate << std::endl;
			}
		} else {
			std::cerr << "Error: bad input => " << date_str << std::endl;
		}
	}
}

// map keys need to be comparable (with <) and std::tm is not, but
// std::time_t is
void	btc(std::string filename_account) {
	std::map<std::time_t, double> rates;
	readRates(rates, "data.csv");
	processAcc(rates, filename_account);
}

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <map>
#include <ctime>
#include <fstream>
#include <utility>
#include <stdlib.h>

class BcExchange {

private:

	std::map<std::string, double> _database;

public:

	BcExchange();
	BcExchange( BcExchange const & src );
	~BcExchange();

	BcExchange & operator=( BcExchange const & rhs );

	void setData( std::string key, double value );

};


#endif
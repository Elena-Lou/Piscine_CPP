#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <map>
#include <ctime>
#include <fstream>
#include <utility>
#include <stdlib.h>
#include <algorithm>

class BcExchange {

private:

	std::map<std::string, double> _database;
	
	std::ifstream	_infile;
	std::string		_line;
	size_t			_pos;
	std::string		_inputDate;
	std::string		_str_date;


public:

	BcExchange();
	BcExchange( BcExchange const & src );
	~BcExchange();

	BcExchange & operator=( BcExchange const & rhs );

	void	initialiseDB( void );

	void getOneDBValue( std::string date ) ;

	void getDatesInputFile( char* file );
};


#endif
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
	
	std::string		_inputDate;
	std::string		_strDate;
	double			_rate;
	double			_amountBTC;
	double			_valueBTC;


public:

	BcExchange();
	BcExchange( BcExchange const & src );
	~BcExchange();

	BcExchange & operator=( BcExchange const & rhs );

	std::string extractData(std::ifstream & infile, std::string del, double & value );

	void		checkInputDate( void );

	void		initialiseDB( void );

	void		printOneDBValue( std::string date );

	double		calculateValue( void );

	void 		getDatesInputFile( char* file );

	void		getBTCValues( char* file );

	class BadInputException : public std::exception 
	{
		public:

			const char* what( void ) const throw();
	};
};


#endif
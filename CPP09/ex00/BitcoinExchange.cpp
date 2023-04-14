#include "./include/BitcoinExchange.hpp"

BcExchange::BcExchange() {

}

BcExchange::BcExchange ( BcExchange const & src ) {

	*this = src;
}

BcExchange & BcExchange::operator=( BcExchange const & rhs ) {

	if (this != &rhs)
		this->_database = rhs._database;
	return *this;
}

BcExchange::~BcExchange() {

}

// void BcExchange::setData( std::string key, double value ) {

// 	std::cout << "SET DATA" << std::endl;
// }

void	BcExchange::initialiseDB( void ) {

	std::ifstream	infile;
	std::string		line;
	std::string		str_date;
	double			rate;
	size_t			pos;

	infile.open("data.csv", std::ifstream::in);
	if (!infile)
	{
		std::cerr << "Open Error" << std::endl;
		return ;
	}
	/* reads the file, while the stream is food, find the position of the 
	comma in the line recovered with getline(). 
	Saves the part of the string which is before the comma in a str_date 
	string, removes the orignal string from the line + the comma.
	Converts the remaining string to a double */
	while(infile.good())
	{
		std::getline(infile, line);
		pos = line.find(",");
		str_date = line.substr(0, pos);
		// std::cout << "date : " << str_date << std::endl;
		line.erase(0, pos + 1);
		rate = strtod(line.c_str(), NULL);
		// std::cout << "rate : " << rate << std::endl;
		_database.insert( std::make_pair(str_date, rate) );
	}
	infile.close();
	// int i = 0;
	// for (std::map<std::string, double>::iterator it = _database.begin(); it != _database.end(); it++)
	// {
	// 	std::cout << i << " : " << it->first << " " << it->second << std::endl;
	// 	i++;
	// }
}

void BcExchange::getOneDBValue( std::string date ) {

	try {
		double res;
		res = this->_database.at(date);
		std::cout << "On the " << date << " the rate was : " <<  res << std::endl;
	}
	catch (std::out_of_range & e)
	{
		std::cerr << "This date is not included in the DB" << std::endl;
	}
}
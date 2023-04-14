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

	/* reads the file, while the stream is food, find the position of the 
	delimiter in the line recovered with getline(). 
	Saves the part of the string which is before the delimiter in a date 
	string, removes the orignal string from the line + the delimiter.
	Converts the remaining string to a double to either be saved as the rate or the amount of
	bitcoins owned */

std::string BcExchange::extractData( std::ifstream & infile, std::string del, double & value )
{
	std::string		line;
	size_t			pos;
	std::string 	date; 

	std::getline(infile, line);
	pos = line.find(del);
	date = line.substr(0, pos);
	// std::cout << "date : " << date << std::endl;
	line.erase(0, pos + del.length());
	value = strtod(line.c_str(), NULL);
	// std::cout << "value : " << value << std::endl;
	return date;
}

void	BcExchange::initialiseDB( void ) {

	std::ifstream	infile;

	infile.open("data.csv", std::ifstream::in);
	if (!infile)
	{
		std::cerr << "Open Error" << std::endl;
		return ;
	}

	while (infile.good())
	{
		this->_strDate = this->extractData(infile, ",", this->_rate);
		_database.insert( std::make_pair(this->_strDate, this->_rate) );
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

void BcExchange::getDatesInputFile( char* file ) {

	std::ifstream	infile;

	infile.open(file, std::ifstream::in);
	if (!infile)
	{
		std::cerr << "Open Error" << std::endl;
		return ;
	}

	while (infile.good())
	{
		this->_inputDate = this->extractData(infile, " | ", this->_amountBTC);
		this->getOneDBValue(this->_inputDate);
	}

	infile.close();
}
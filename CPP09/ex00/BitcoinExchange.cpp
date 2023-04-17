#include "./include/BitcoinExchange.hpp"

BcExchange::BcExchange() : _rate(0), _amountBTC(0) {

}

BcExchange::BcExchange ( BcExchange const & src ) {

	*this = src;
}

BcExchange & BcExchange::operator=( BcExchange const & rhs ) {

	if (this != &rhs)
	{
		this->_database = rhs._database;
		this->_rate = rhs._rate;
		this->_amountBTC = rhs._amountBTC;
		this->_inputDate = rhs._inputDate;
		this->_strDate = rhs._strDate;
	}
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
	line.erase(0, pos + del.length());
	value = strtod(line.c_str(), NULL);
	return date;
}

void BcExchange::checkInputDate( void ) {

	struct tm tm;

	if (!strptime(this->_inputDate.c_str(), "%Y-%m-%d", &tm))
		throw BcExchange::BadInputException();
		
}

void BcExchange::checkInputAmount( void ) {

	if (this->_amountBTC < 0)
		throw BcExchange::NegativeException();
	if (this->_amountBTC > 1000)
		throw BcExchange::TooLargeANumberException();
		
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

void BcExchange::printOneDBValue( std::string date ) {

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

double BcExchange::calculateValue( double & value ) {

	double rate;

	try {
		rate = this->_database.at(this->_inputDate);
	}
	catch (std::out_of_range & e)
	{
		std::cerr << "This date is not included in the DB" << std::endl;
		std::map<std::string, double>::iterator itlow;
		itlow = this->_database.lower_bound(this->_inputDate);
		itlow--;
		rate = itlow->second;
	}
		std::cout << this->_inputDate << " : " << rate << std::endl;
		value = rate * this->_amountBTC;
	return value;
}

void BcExchange::getBTCValues( char* file ) {

	std::ifstream	infile;

	infile.open(file, std::ifstream::in);
	if (!infile)
	{
		std::cerr << "Open Error" << std::endl;
		return ;
	}

	while (infile.good())
	{
		try {

		double valueBTC = 0;
		this->_inputDate = this->extractData(infile, " | ", this->_amountBTC);
		if (this->_inputDate.empty())
			continue ;
		this->checkInputDate();
		this->checkInputAmount();
		if (this->_amountBTC != 0)
			valueBTC = this->calculateValue(valueBTC);
		std::cout << this->_inputDate << " => " ;
		std::cout << this->_amountBTC;
		std::cout << " = " << valueBTC << std::endl;	
		}
		catch (BadInputException & e )
		{
			std::cerr << e.what() << this->_inputDate << std::endl;
		}
		catch (NegativeException & e )
		{
			std::cerr << e.what() << std::endl;
		}
		catch (TooLargeANumberException & e )
		{
			std::cerr << e.what() << std::endl;
		}
	}

	infile.close();
}

const char* BcExchange::BadInputException::what( void ) const throw() {

	return ("Error : bad input => ");
}

const char* BcExchange::NegativeException::what( void ) const throw() {

	return ("Error : not a positive number");
}

const char* BcExchange::TooLargeANumberException::what( void ) const throw() {

	return ("Error : too large a number");
}
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


void	BcExchange::initialiseDB( void ) {

	double			rate;

	this->_infile.open("data.csv", std::ifstream::in);
	if (!this->_infile)
	{
		std::cerr << "Open Error" << std::endl;
		return ;
	}
	/* reads the file, while the stream is food, find the position of the 
	comma in the line recovered with getline(). 
	Saves the part of the string which is before the comma in a str_date 
	string, removes the orignal string from the line + the comma.
	Converts the remaining string to a double */
	while (this->_infile.good())
	{
		std::getline(this->_infile, this->_line);
		this->_pos = this->_line.find(",");
		this->_str_date = this->_line.substr(0, this->_pos);
		// std::cout << "date : " << str_date << std::endl;
		this->_line.erase(0, this->_pos + 1);
		rate = strtod(this->_line.c_str(), NULL);
		// std::cout << "rate : " << rate << std::endl;
		_database.insert( std::make_pair(this->_str_date, rate) );
	}
	this->_infile.close();
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

	this->_infile.open(file, std::ifstream::in);
	if (!this->_infile)
	{
		std::cerr << "Open Error" << std::endl;
		return ;
	}

	while (this->_infile.good())
	{
		std::getline(this->_infile, this->_line);
		this->_pos = this->_line.find(" ");
		this->_str_date = this->_line.substr(0, this->_pos);
		std::cout << this->_str_date << std::endl;
		this->getOneDBValue(this->_str_date);
	}
	this->_infile.close();
}
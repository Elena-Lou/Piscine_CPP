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

void BcExchange::setData( std::string key, double value ) {

	std::cout << "SET DATA" << std::endl;
}

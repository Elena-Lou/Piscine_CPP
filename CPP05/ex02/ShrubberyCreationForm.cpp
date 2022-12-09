/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:47:48 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/09 17:22:27 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm ( void ) : AForm() {

	std::cout << "[Shrubbery Creation] Default Constructor" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm ( std::string target ) : AForm( "Shrubbery Creation", 145, 137, target) {

	std::cout << "[Shrubbery Creation] Default Constructor" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm ( ShrubberyCreationForm const & src ) : AForm( src ) {

	std::cout << "[Shrubbery Creation] copy constructor" << std::endl;
	return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs ) {

	(void)rhs;
	return *this;
}

void ShrubberyCreationForm::execute( Bureaucrat const & executor ) const {

	std::ofstream	outfile;
	std::string		outName;

	if (executor.getGrade() > this->getExecGrade())
	{
		throw AForm::GradeTooLowException();
	}
	
	std::cout << "After throw" << std::endl;
	outName = this->getTarget();
	outName += "_shrubbery";
	outfile.open(outName.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!outfile)
	{
		std::cerr << "Open error" << std::endl;
		return ;
	}
		
	outfile <<"       ,., "<< "\n";
	outfile << "      MMMM_    ,..," << "\n" ;
	outfile << "        \"_ \"__\"MMMMM          ,...,," << "\n" ;
	outfile << " ,..., __.\" --\"    ,.,     _-\"MMMMMMM" << "\n" ;
	outfile << "MMMMMM\"___ \"_._   MMM\"_.\"\" _ \"\"\"\"\"\"" << "\n" ;
	outfile << " \"\"\"\"\"    \"\" , \\_.   \"_. .\"" << "\n" ;
	outfile << "        ,., _\"__ \\__./ .\"" << "\n" ;
	outfile << "       MMMMM_\"  \"_    ./" << "\n" ;
	outfile << "        ''''      (    )" << "\n" ;
	outfile << " ._______________.-'____\"---._." << "\n" ;

	outfile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm ( void ) {
	
	std::cout << "[Shrubbery Creation] Destructor" << std::endl;
	return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:59:52 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/04 15:23:42 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
#include <string>

class WrongAnimal
{
private:
	
protected:

	std::string type;

public:

			WrongAnimal();
			WrongAnimal( WrongAnimal const & src );	
	virtual	~WrongAnimal();
	
			WrongAnimal & operator=( WrongAnimal const & rhs );

	void makeSound ( void ) const;
	std::string getType ( void ) const;
};

#endif
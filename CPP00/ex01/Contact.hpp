/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:27:09 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/13 16:38:41 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#  define CONTACT_HPP
#include <string>

class Contact {

private: 

    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNb;
    std::string _secret;
    int         _index;

public:

    Contact( void );
    ~Contact( void );
	std::string	get_firstname() const;
	std::string	get_lastname() const;
	std::string	get_nickname() const;
	std::string	get_number() const;
	std::string	get_secret() const;
	int			get_index() const;
	
	void	set_firstname(std::string firstName);
	void	set_lastname(std::string lastName);
	void	set_nickname(std::string nickname);
	void	set_number(std::string phoneNb);
	void	set_secret(std::string secret);
	void	set_index(int index);
};
#endif
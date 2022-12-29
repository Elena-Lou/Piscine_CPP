/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:27:09 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/08 21:29:41 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#  define CONTACT_HPP
#include <string>

class Contact {

private: 

    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_nb;
    std::string _secret;
    int         _index;

public:

    Contact(void);
    ~Contact(void);
	std::string	get_firstname() const;
	std::string	get_lastname() const;
	std::string	get_nickname() const;
	std::string	get_number() const;
	std::string	get_secret() const;
	int			get_index() const;
	
	void	set_firstname(std::string);
	void	set_lastname(std::string);
	void	set_nickname(std::string);
	void	set_number(std::string);
	void	set_secret(std::string);
	void	set_index(int);
};
#endif
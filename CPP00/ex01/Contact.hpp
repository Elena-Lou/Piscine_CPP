/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:27:09 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/04 14:13:13 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#  define CONTACT_HPP
#include <string>

class Contact {

public:

    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_nb;
    std::string secret;

    Contact(void);
    ~Contact(void);


};
#endif
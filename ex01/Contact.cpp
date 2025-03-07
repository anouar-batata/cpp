/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 03:23:21 by alouriga          #+#    #+#             */
/*   Updated: 2025/02/18 05:27:10 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
    
}
Contact::~Contact()
{
    
}
std::string Contact::get_first_name()
{
    return first_name;    
}
std::string Contact::get_last_name()
{
    return last_name;    
}
std::string Contact::get_nickname()
{
    return nickname;    
}
std::string Contact::get_phone_number()
{
    return phone_number;   
} 
std::string Contact::get_darkest_secret()
{
    return darkest_secret;   
}


void    Contact::set_first_name(std::string input)
{
    first_name = input;
}
void    Contact::set_last_name(std::string input)
{
    last_name = input;
}
void    Contact::set_nickname(std::string input)
{
    nickname = input;
}
void    Contact::set_phone_number(std::string input)
{
    phone_number = input;
}

void    Contact::set_darkest_secret(std::string input)
{
    darkest_secret = input;
}
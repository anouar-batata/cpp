/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 03:12:32 by alouriga          #+#    #+#             */
/*   Updated: 2025/03/01 10:21:43 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    int i = 1;
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while(av != NULL && av[i])
        {
            size_t j = 0;
            std::string res = av[i];
            while(j < res.length())
            {
                char c = toupper(res[j]);
                std::cout << c;
                j++;
            }
            i++;
        }
    }
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:41:54 by hyungseok         #+#    #+#             */
/*   Updated: 2023/12/13 11:00:51 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Sed.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "sed: error: wrong number of arguments." << std::endl;
        return (1);
    }

    try {
        Sed sed(argv[1], argv[2], argv[3]);
        sed.replace();
    }
    catch (std::string &str) {
        std::cerr << str << std::endl;
    }

    return (0);
}
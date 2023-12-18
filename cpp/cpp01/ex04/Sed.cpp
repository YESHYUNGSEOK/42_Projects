/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:48:16 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/17 14:48:17 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string input, std::string s1, std::string s2) : s1(s1), s2(s2), ifs(), ofs() 
{
    this->ifs.open(input.c_str());
    if (!this->ifs.is_open())
        throw std::string("sed: error: could not open " + input);
    this->ofs.open((input + ".replace").c_str());
    if (!this->ofs.is_open())
        throw std::string("sed: error: could not create " + input + ".replace");
    if (this->s1.length() == 0)
        throw std::string("sed: error: search pattern may not be empty");
}

Sed::~Sed()
{
    this->ifs.close();
    this->ofs.close();
}

void    Sed::replace()
{
    std::string replaced;

    while (std::getline(this->ifs, replaced))
    {
        if (this->ifs.eof())
            break ;
        this->replaceStr(&replaced);
        this->ofs << replaced << std::endl;
    }
}

void    Sed::replaceStr(std::string *replaced)
{
    size_t  pos = 0;

    while (pos < replaced->length())
    {
        pos = replaced->find(this->s1, pos);
        if (pos == std::string::npos)
            break ;
        replaced->erase(pos, this->s1.length());
        replaced->insert(pos, this->s2);
        pos += this->s2.length();
    }
}

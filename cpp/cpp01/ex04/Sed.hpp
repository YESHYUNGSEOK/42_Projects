#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
# include <string>

class Sed
{
    private:
        std::string s1;
        std::string s2;
        std::ifstream ifs;
        std::ofstream ofs;
    public:
        Sed(std::string input, std::string s1, std::string s2);
        ~Sed();
        void replace();
        void replaceStr(std::string *replaced);
};

#endif
# include "Sed.hpp"

Sed::Sed(std::string input, std::string s1, std::string s2) : s1(s1), s2(s2)
{
	this->ifs.open(input);
	if (!this->ifs.is_open())
		throw std::string("error: could not open " + input);
	this->ofs.open(input + ".replace");
	if (!this->ofs.is_open())
		throw std::string("error: could not create " + input + ".replace");
}

Sed::~Sed()
{
	this->ifs.close();
	this->ofs.close();
}

void Sed::replace()
{
	std::string line;
	while (std::getline(this->ifs, line))
	{
		this->replaceStr(&line);
		this->ofs << line << std::endl;
	}
}

void Sed::replaceStr(std::string *replaced)
{
	size_t pos = 0;
	while ((pos = replaced->find(this->s1, pos)) != std::string::npos)
	{
		replaced->replace(pos, this->s1.length(), this->s2);
		pos += this->s2.length();
	}
}
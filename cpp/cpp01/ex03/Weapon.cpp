# include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
	std::cout << "Weapon \'" << type << "\' is created." << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon \'" << this->type << "\' is destroyed." << std::endl;
}

const std::string& Weapon::getType() const
{
	return (this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
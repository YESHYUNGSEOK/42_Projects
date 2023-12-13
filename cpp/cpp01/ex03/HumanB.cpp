# include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
	std::cout << "HumanB \'" << name << "\' is born." << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB \'" << name << "\' died." << std::endl;
}

void HumanB::attack()
{
	std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}
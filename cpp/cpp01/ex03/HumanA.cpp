# include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon)
{
    std::cout << "HumanA \'" << name << "\' is born, holding \'" << weapon.getType() << "\'." << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "HumanA \'" << name << "\' died." << std::endl;
}

void HumanA::attack()
{
    std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}

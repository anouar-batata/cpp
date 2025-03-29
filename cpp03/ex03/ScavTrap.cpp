#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << " ScavTrap Default constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap Constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}
ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
    std::cout << " ScavTrap Copy constructor called" << std::endl;
    this->name = obj.name;
    this->hitPoints = obj.hitPoints;
    this->energyPoints = obj.energyPoints;
    this->attackDamage = obj.attackDamage;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
    std::cout << " ScavTrap Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->name = obj.name;
        this->hitPoints = obj.hitPoints;
        this->energyPoints = obj.energyPoints;
        this->attackDamage = obj.attackDamage;
    }
    return *this;
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}
void ScavTrap::attack(const std::string &target)
{
    unsigned int tmp = this->energyPoints;
    if (this->hitPoints == 0 || this->energyPoints == 0)
    {
        std::cout << "ScavTrap" << this->name << " has no energy or hit points left to attack!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints--;
    if (this->energyPoints > tmp)
        this->energyPoints = 0;
}
void ScavTrap::takeDamage(unsigned int amount)
{
    ScavTrap::ClapTrap::takeDamage(amount);
}
void ScavTrap::beRepaired(unsigned int amount)
{
    ScavTrap::ClapTrap::beRepaired(amount);
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}

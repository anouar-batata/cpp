#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Claptrap Default constructor called" << std::endl;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "Claptrap Constructor called" << std::endl;
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}
ClapTrap::ClapTrap(const ClapTrap &obj)
{
    std::cout << "Claptrap Copy constructor called" << std::endl;
    this->name = obj.name;
    this->hitPoints = obj.hitPoints;
    this->energyPoints = obj.energyPoints;
    this->attackDamage = obj.attackDamage;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
    std::cout << "Claptrap Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->name = obj.name;
        this->hitPoints = obj.hitPoints;
        this->energyPoints = obj.energyPoints;
        this->attackDamage = obj.attackDamage;
    }
    return *this;
}
ClapTrap::~ClapTrap()
{
    std::cout << "Claptrap Destructor called" << std::endl;
}
void ClapTrap::attack(const std::string &target)
{
    if (this->hitPoints == 0 || this->energyPoints == 0)
    {
        std::cout << " ClapTrap " << this->name << " has no energy or hit points left to attack!" << std::endl;
        return;
    }
    std::cout << " ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
        return;
    }
    if (amount > this->hitPoints)
    {
        this->hitPoints = 0;
        return;
    }
    this->hitPoints -= amount;
    std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage! Hit points left: " << this->hitPoints << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoints == 0 || this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " has no energy or hit points left to be repaired!" << std::endl;
        return;
    }
    this->hitPoints += amount;
    std::cout << "ClapTrap " << this->name << " is repaired by " << amount << " points! Hit points: " << this->hitPoints << std::endl;
}
std::string ClapTrap::getName() const
{
    return this->name;
}
unsigned int ClapTrap::getHitPoints() const
{
    return this->hitPoints;
}
unsigned int ClapTrap::getEnergyPoints() const
{
    return this->energyPoints;
}
unsigned int ClapTrap::getAttackDamage() const
{
    return this->attackDamage;
}
    
#include <iostream>
#include <string.h>
#include "BattleShip.h"

template <typename Pilot>
bool BattleShip<Pilot>::operator==(const BattleShip& other)const
{
    return this->size == other.size &&
           this->speed == other.speed &&
           this->cannons == other.cannons &&
           this->can_Hyperdrive == other.can_Hyperdrive;
           this->pilot == other.pilot;
}
template <typename Pilot>
BattleShip<Pilot>& BattleShip<Pilot>::operator=(const BattleShip<Pilot>& other)  
{
    if (this != &other)
    {
        this->cannons = other.cannons;
        this->size = other.size;
        this->can_Hyperdrive = other.can_Hyperdrive;
        this->speed = other.speed;
        this->pilot = other.pilot;
    }
    return *this;
}
template <typename Pilot>
std::ostream& operator<<(std::ostream& output, const BattleShip<Pilot>& battleShip)
{
    output << battleShip.pilot << std::endl << battleShip.cannons << std::endl
        << battleShip.size << std::endl << battleShip.speed << std::endl;
    if (battleShip.can_Hyperdrive)
    {
        output << "Can Hyperdrive" << std::endl;
    }
    output << "Can`t hyperdrive" << std::endl;
    return output;
}
template <typename Pilot>
std::istream& operator>>(std::istream& input, BattleShip<Pilot>& battleShip)
{

}
template <typename Pilot>
BattleShip<Pilot>::BattleShip()
{
    this->size = 0;
    this->speed = 0;
    this->cannons = 0;
    this->can_Hyperdrive = false;
    this->pilot = NULL;
}
template <typename Pilot>
BattleShip<Pilot>::BattleShip(const BattleShip& other)
{
    this->cannons = other.cannons;
    this->size = other.size;
    this->can_Hyperdrive = other.can_Hyperdrive;
    this->speed = other.speed;
    this->pilot = other.pilot;
}
template <typename Pilot>
BattleShip<Pilot>::BattleShip(const double Speed, const Jedi Pilot, const int Cannons,
    const bool Can_Hyperdrive, const double Size)
{
    this->cannons = Cannons;
    this->size = Size;
    this->can_Hyperdrive = Can_Hyperdrive;
    this->speed = Speed;
    this->pilot = Pilot;
}
template <typename Pilot>
BattleShip<Pilot>::BattleShip(const double Speed, const Stormtrooper Pilot, const int Cannons,
    const bool Can_Hyperdrive, const double Size)
{
    this->cannons = Cannons;
    this->size = Size;
    this->can_Hyperdrive = Can_Hyperdrive;
    this->speed = Speed;
    this->pilot = Pilot;
}
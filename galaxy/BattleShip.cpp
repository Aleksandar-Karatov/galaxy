#include <iostream>
#include <string.h>
#include "BattleShip.h"
void ToLower15(char* string)
{
    for (size_t i = 0; string[i] != NULL; i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] += 32;
        }
    }
}
template <class T>
bool BattleShip<T>::operator==(const BattleShip& other)const
{
    return this->size == other.size &&
           this->speed == other.speed &&
           this->cannons == other.cannons &&
           this->can_Hyperdrive == other.can_Hyperdrive;
           this->pilot == other.pilot;
}
template <class T>
BattleShip<T>& BattleShip<T>::operator=(const BattleShip<T>& other)  
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
template <class T>
std::ostream& operator<<(std::ostream& output, const BattleShip<T>& battleShip)
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
template <class T>
std::istream& operator>>(std::istream& input, BattleShip<T>& battleShip)
{
    char buffer[50];
    input.getline(buffer, 50);
    ToLower15(buffer);
    if (!strcmp(buffer, "jedi"))
    {
        Jedi temp;
        input >> temp;
        battleShip.set_Pilot(temp);
    }
    else if (!strcmp(buffer,"stormtrooper"))
    {
        Stormtrooper temp;
        input >> temp;
        battleShip.set_Pilot(temp);
    }
    int intBuff;
    input >> intBuff;
    battleShip.set_Cannons(intBuff);
    double doubleBuff;
    input >> doubleBuff;
    battleShip.set_Size(doubleBuff);
    input >> doubleBuff;
    battleShip.set_Speed(doubleBuff);
    input >> buffer;
    ToLower15(buffer);
    if (!strcmp(buffer,"yes"))
    {
        battleShip.set_can_Hyperdrive(true);
        return input;
    }
    battleShip.set_can_Hyperdrive(false);
    return input;
}
template <class T>
BattleShip<T>::BattleShip()
{
    this->size = 0;
    this->speed = 0;
    this->cannons = 0;
    this->can_Hyperdrive = false;
    this->pilot = T();
}
template <class T>
BattleShip<T>::BattleShip(const BattleShip<T>& other)
{
    this->cannons = other.cannons;
    this->size = other.size;
    this->can_Hyperdrive = other.can_Hyperdrive;
    this->speed = other.speed;
    this->pilot = other.pilot;
}
template <class T>
BattleShip<T>::BattleShip( double Speed, T Pilot,  int Cannons,
     bool Can_Hyperdrive,  double Size)
{
    this->cannons = Cannons;
    this->size = Size;
    this->can_Hyperdrive = Can_Hyperdrive;
    this->speed = Speed;
    this->pilot = Pilot;
}
//template <typename Pilot>
/*template <typename Stormtrooper>
BattleShip<Pilot>::BattleShip(const double Speed, const Stormtrooper Pilot, const int Cannons,
    const bool Can_Hyperdrive, const double Size)
{
    this->cannons = Cannons;
    this->size = Size;
    this->can_Hyperdrive = Can_Hyperdrive;
    this->speed = Speed;
    this->pilot = Pilot;
}*/



#include <iostream>
#include <string.h>
#include "Planet.h"
#include "Stormtrooper.h"




bool Stormtrooper:: operator == (const Stormtrooper& other) const
{
    return !strcmp(this->id, other.id) && !strcmp(this->type, other.type)
        && this->planet == other.planet && this->rank == other.rank;
}
std::ostream& operator<<(std::ostream& output, const Stormtrooper& stormtrooper)
{
    output << stormtrooper.id;
    switch (stormtrooper.rank)
    {
    case Stormtrooper::StormtrooperRank::Cadet:
        output << "Cadet";
        break;
    case Stormtrooper::StormtrooperRank::Private:
        output << "Private";
        break;
    case Stormtrooper::StormtrooperRank::LanceCorporal:
        output << "Lance Corporal";
        break;
    case Stormtrooper::StormtrooperRank::Corporal:
        output << "Corporal";
        break;
    case Stormtrooper::StormtrooperRank::Sergeant:
        output << "Sergeant";
        break;
    case Stormtrooper::StormtrooperRank::StaffSergeant:
        output << "Staff Sergeant";
        break;
    case Stormtrooper::StormtrooperRank::MasterSergeant:
        output << "Master Sergeant";
        break;
    case Stormtrooper::StormtrooperRank::OfficerCadet:
        output << "Officer Cadet";
        break;
    case Stormtrooper::StormtrooperRank::Lieutenant:
        output << "Lieutenant";
        break;
    case Stormtrooper::StormtrooperRank::Captain:
        output << "Captain";
        break;
    case Stormtrooper::StormtrooperRank::Major:
        output << "Major";
        break;
    case Stormtrooper::StormtrooperRank::Colonel:
        output << "Colonel";
        break;
    case Stormtrooper::StormtrooperRank::Commander:
        output << "Commander";
        break;
    default:
        break;
    }
    Planet planet = stormtrooper.planet;
    output << std::endl << stormtrooper.type << std::endl << planet.get_name() << std::endl;
    planet.~Planet();
    return output;
}
Stormtrooper& Stormtrooper:: operator=(const Stormtrooper& other)
{
    if (this != &other)
    {
        this->id = new char[strlen(other.id) + 1];
        this->type = new char[strlen(other.type) + 1];
        strcpy_s(this->id, strlen(other.id) + 1, other.id);
        strcpy_s(this->type, strlen(other.type) + 1, other.type);
        this->planet = other.planet;
        this->rank = other.rank;
    }
    return *this;
}
Stormtrooper::Stormtrooper()
{
    this->id = nullptr;
    this->rank = Cadet;
    this->type = nullptr;
}
Stormtrooper::Stormtrooper(const Stormtrooper& other)
{
    this->id = new char[strlen(other.id) + 1];
    this->type = new char[strlen(other.type) + 1];
    strcpy_s(this->id, strlen(other.id) + 1, other.id);
    strcpy_s(this->type, strlen(other.type) + 1, other.type);
    this->planet = other.planet;
    this->rank = other.rank;
}
Stormtrooper::Stormtrooper(char* Id, StormtrooperRank Rank, Planet Planet, char* Type)
{
    this->id = new char[strlen(Id) + 1];
    this->type = new char[strlen(Type) + 1];
    strcpy_s(this->id, strlen(Id) + 1, Id);
    strcpy_s(this->type, strlen(Type) + 1, Type);
    this->planet = Planet;
    this->rank = Rank;
}
Stormtrooper::~Stormtrooper()
{
    delete[] id;
    delete[] type;
}
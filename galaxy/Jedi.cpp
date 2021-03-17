#include <iostream>
#include <string.h>
#include "Planet.h"
#include "Jedi.h"

bool Jedi:: operator == (const Jedi& other) const
{
    return !strcmp(this->name, other.name)
        && !strcmp(this->species, other.species)
        && !strcmp(this->militaryRank, other.militaryRank)
        && this->rank == other.rank
        && this->planet == other.planet
        && this->midi_chlorian == other.midi_chlorian;
}
std::ostream& operator<<(std::ostream& output, const Jedi& jedi)
{
    output << jedi.name << std::endl;
    switch (jedi.rank)
    {
    case Jedi::JediRank::Non_Force_User:
        output<< "Non Force User";
        break;
    case Jedi::JediRank::Youngling:
        output << "Youngling";
        break;
    case Jedi::JediRank::Padwan:
        output << "Padwan";
        break;
    case Jedi::JediRank::Jedi_Knight:
        output << "Jedi Knight";
        break;
    case Jedi::JediRank::Jedi_Consular:
        output << "Jedi Consular";
        break;
    case Jedi::JediRank::Jedi_Guardian:
        output << "Jedi Guardian";
        break;
    case Jedi::JediRank::Jedi_Sentinel:
        output << "Non Force User";
        break;
    case Jedi::JediRank::Jedi_master:
        output << "Jedi master";
        break;
    case Jedi::JediRank::Jedi_Council_Member:
        output << "Jedi Council Member";
        break;
    case Jedi::JediRank::Master_Of_The_Order:
        output << "Master Of The Order";
        break;
    case Jedi::JediRank::Grand_master:
        output << "Grand master";
        break;
    default:
        break;
    }

    Planet planet = jedi.planet;
    output << std::endl << jedi.midi_chlorian << std::endl <<planet.get_name() << std::endl
       << jedi.species << std::endl << jedi.militaryRank << std::endl;
    planet.~Planet();
    return output;
}

Jedi::Jedi()
{
    name = nullptr;
    rank = Non_Force_User;
    midi_chlorian = 0;
    species = nullptr;
    militaryRank = nullptr;
}
Jedi::Jedi(char* Name, Jedi::JediRank Rank, double Midi_chlorian, Planet Planet, char* Species, char* MilitaryRank)
{
    this->name = Name;
    this->rank = Rank;
    this->midi_chlorian = Midi_chlorian;
    this->planet = Planet;
    this->species = Species;
    this->militaryRank = MilitaryRank;
}
Jedi::Jedi(const Jedi& other)
{
    this->name = new char[strlen(other.name) + 1];
    this->species = new char[strlen(other.species) + 1];
    this->militaryRank = new char[strlen(other.militaryRank) + 1];
    strcpy_s(this->name, strlen(other.name) + 1, other.name);
    this->rank = other.rank;
    this->midi_chlorian = other.midi_chlorian;
    this->planet = other.planet;
    strcpy_s(this->species, strlen(other.species) + 1, other.species);
    strcpy_s(this->militaryRank, strlen(other.militaryRank) + 1, other.militaryRank);
}
Jedi& Jedi :: operator=(const Jedi& other)
{
    if (this != &other)
    {
        delete[] name;
        delete[] militaryRank;
        delete[] species;
        this->name = new char[strlen(other.name) + 1];
        this->militaryRank = new char[strlen(other.militaryRank) + 1];
        this->species = new char[strlen(other.species) + 1];
        strcpy_s(this->name, strlen(other.name) + 1, other.name);
        strcpy_s(this->militaryRank, strlen(other.militaryRank) + 1, other.militaryRank);
        strcpy_s(this->species, strlen(other.species) + 1, other.species);
        this->rank = other.rank;
        this->planet = other.planet;
        this->midi_chlorian = other.midi_chlorian;
    }
    return *this;
}
Jedi::~Jedi()
{
    delete[] name;
    delete[] species;
    delete[] militaryRank;
    midi_chlorian = NULL;
}



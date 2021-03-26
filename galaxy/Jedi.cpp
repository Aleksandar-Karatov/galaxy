#include <iostream>
#include <string.h>
#include "Planet.h"
#include "Jedi.h"


void ToLower1(char* string)
{
    for (size_t i = 0; string[i] != NULL; i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] += 32;
        }
    }
}

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
    return output;
}
std::istream& operator>>(std::istream& input, Jedi& jedi)
{
    char buffer[50];
    input.getline(buffer, 50);
    jedi.set_name(buffer);
    input.getline(buffer, 50);
    ToLower1(buffer);
    if (!strcmp(buffer, "non force user"))
    {
        jedi.set_rank(Jedi::JediRank::Non_Force_User);
    }
    else if (!strcmp(buffer, "youngling"))
    {
        jedi.set_rank(Jedi::JediRank::Youngling);
    }
    else if (!strcmp(buffer, "padwan"))
    {
        jedi.set_rank(Jedi::JediRank::Padwan);
    }
    else if (!strcmp(buffer, "jedi knight"))
    {
        jedi.set_rank(Jedi::JediRank::Jedi_Knight);
    }
    else if (!strcmp(buffer, "jedi consular"))
    {
        jedi.set_rank(Jedi::JediRank::Jedi_Consular);
    }
    else if (!strcmp(buffer, "jedi guardian"))
    {
        jedi.set_rank(Jedi::JediRank::Jedi_Guardian);
    }
    else if (!strcmp(buffer, "jedi sentinel"))
    {
        jedi.set_rank(Jedi::JediRank::Jedi_Sentinel);
    }
    else if (!strcmp(buffer, "jedi master"))
    {
        jedi.set_rank(Jedi::JediRank::Jedi_master);
    }
    else if (!strcmp(buffer, "jedi council member"))
    {
        jedi.set_rank(Jedi::JediRank::Jedi_Council_Member);
    }
    else if (!strcmp(buffer, "master of the order"))
    {
        jedi.set_rank(Jedi::JediRank::Master_Of_The_Order);
    }
    else if (!strcmp(buffer, "grand master"))
    {
        jedi.set_rank(Jedi::JediRank::Grand_master);
    }
    else
    {
        jedi.set_rank(Jedi::JediRank::Non_Force_User);
    }
    int temp_midichlorian;
    input >> temp_midichlorian;
    jedi.set_midi_chlorians(temp_midichlorian);
    input.ignore();
    input.getline(buffer, 50);
    const Planet temp(buffer, "", "", Planet::typeOfPlanet::Chthonian_Planet);
    jedi.set_planet(temp);
    input.getline(buffer, 50);
    jedi.set_species(buffer);
    input.getline(buffer, 50);
    jedi.set_militaryRank(buffer);

    return input;
}

Jedi::Jedi()
{
    name = nullptr;
    rank = Non_Force_User;
    midi_chlorian = 0;
    species = nullptr;
    militaryRank = nullptr;
    planet;
}
Jedi::Jedi(const char* Name,const Jedi::JediRank Rank, const double Midi_chlorian,const  Planet Planet, 
    const char* Species, const char* MilitaryRank)
{
    this->rank = Rank;
    this->midi_chlorian = Midi_chlorian;
    this->planet = Planet;

    this->name = new char[strlen(Name) + 1];
    this->species = new char[strlen(Species) + 1];
    this->militaryRank = new char[strlen(MilitaryRank) + 1];
    strcpy_s(this->name, strlen(Name) + 1, Name);
    strcpy_s(this->species, strlen(Species) + 1, Species);
    strcpy_s(this->militaryRank, strlen(MilitaryRank) + 1, MilitaryRank);
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



#pragma once
#include <iostream>
#include <string.h>
#include "Planet.h"

enum JediRank
{
    Non_Force_User,
    Youngling,
    Padwan,
    Jedi_Knight,
    Jedi_Consular,
    Jedi_Guardian,
    Jedi_Sentinel,
    Jedi_master,
    Jedi_Council_Member,
    Master_Of_The_Order,
    Grand_master
};

class Jedi
{
private:
    char* name;
    JediRank rank;
    double midi_chlorian;
    Planet planet;
    char* species;
    char* militaryRank;
public:
    Jedi();
    Jedi(const Jedi& other);
    Jedi(char*, JediRank, double, Planet, char*, char*);
    void set_name(const char* Name)
    {
        name = new char[strlen(Name) + 1];
        strcpy_s(name, strlen(Name) + 1, Name);
    }
    void set_rank(const JediRank Rank)
    {
        rank = Rank;
    }
    void set_midi_chlorians(const double Midi_chlorian)
    {
        midi_chlorian = Midi_chlorian;
    }
    void set_species(const char* Species)
    {
        species = new char[strlen(Species) + 1];
        strcpy_s(species, strlen(Species) + 1, Species);
    }
    void set_militaryRank(const char* MilitaryRank)
    {
        militaryRank = new char[strlen(MilitaryRank) + 1];
        strcpy_s(militaryRank, strlen(MilitaryRank) + 1, MilitaryRank);
    }
    void set_planet(Planet Planet)
    {
        planet = Planet;
    }
    char* get_name()
    {
        return name;
    }
    JediRank get_rank()
    {
        return rank;
    }
    double get_midi_chlorians()
    {
        return midi_chlorian;
    }
    Planet get_planet()
    {
        return planet;
    }
    char* get_species()
    {
        return species;
    }
    char* get_militaryRank()
    {
        return militaryRank;
    }
    void print();
    bool operator == (const Jedi& other) const
    {
        return strcmp(name, other.name)
            && strcmp(species, other.species)
            && strcmp(militaryRank, other.militaryRank)
            && rank == other.rank
            && planet == other.planet
            && midi_chlorian == other.midi_chlorian;
    }
    Jedi& operator=(const Jedi& other);
    ~Jedi();
};

Jedi::Jedi()
{
    name = NULL;
    rank = Non_Force_User;
    midi_chlorian = NULL;
    planet = Planet();
    species = NULL;
    militaryRank = NULL;
}
Jedi::Jedi(char* _name, JediRank _rank, double _midi_chlorian, Planet _planet, char* _species, char* _militaryRank)
{
    this->name = _name;
    this->rank = _rank;
    this->midi_chlorian = _midi_chlorian;
    this->planet = _planet;
    this->species = _species;
    this->militaryRank = _militaryRank;
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
    planet.DeletePlanet();
    midi_chlorian = NULL;
}
void Jedi::print()
{
    std::cout << name << " " << rank << " " << midi_chlorian << " " << planet.get_name() <<
        " " << species << " " << militaryRank << std::endl;
}
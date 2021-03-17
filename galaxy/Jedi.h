#pragma once
#include <iostream>
#include <string.h>
#include "Planet.h"


class Jedi
{


public:
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
    Jedi();
    Jedi(const Jedi& other);
    Jedi(char*, Jedi::JediRank, double, Planet, char*, char*);
    void set_name(const char* Name)
    {
        name = new char[strlen(Name) + 1];
        strcpy_s(name, strlen(Name) + 1, Name);
    }
    void set_rank(const Jedi::JediRank Rank)
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
    bool operator == (const Jedi& other) const;
    Jedi& operator=(const Jedi& other);
    friend std::ostream& operator<<(std::ostream& output, const Jedi& jedi);
    ~Jedi();
private:
    char* name;
    Jedi::JediRank rank;
    double midi_chlorian;
    Planet planet;
    char* species;
    char* militaryRank;
};


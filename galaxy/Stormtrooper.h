#pragma once
#include <iostream>
#include <string.h>
#include "Planet.h"



class Stormtrooper
{

public:
    enum StormtrooperRank {
        Cadet,
        Private,
        LanceCorporal,
        Corporal,
        Sergeant,
        StaffSergeant,
        MasterSergeant,
        OfficerCadet,
        Lieutenant,
        Captain,
        Major,
        Colonel,
        Commander
    };
    Stormtrooper();
    Stormtrooper(const Stormtrooper& other);
    Stormtrooper(char*, StormtrooperRank, Planet, char*);
    void set_id(const char* Id)
    {
        id = new char[strlen(Id) + 1];
        strcpy_s(id, strlen(Id) + 1, Id);
    }
    void set_rank(Stormtrooper::StormtrooperRank Rank)
    {
        rank = Rank;
    }
    void set_type(const char* Type)
    {
        type = new char[strlen(Type) + 1];
        strcpy_s(type, strlen(Type) + 1, Type);
    }
    void set_planet(const Planet Planet)
    {
        planet = Planet;
    }
    char* get_id()
    {
        return id;
    }
    StormtrooperRank get_rank()
    {
        return rank;
    }
    Planet get_planet()
    {
        return planet;
    }
    char* get_type()
    {
        return type;
    }

    bool operator == (const Stormtrooper& other) const;
    Stormtrooper& operator=(const Stormtrooper& other);
    friend std::ostream& operator<<(std::ostream& output, const Stormtrooper& stormtrooper);
    friend std::istream& operator>>(std::istream& input, Stormtrooper& stormtrooper);

    ~Stormtrooper();
private:
    char* id;
    Stormtrooper::StormtrooperRank rank;
    Planet planet;
    char* type;
};



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
    void print();
    bool operator == (const Stormtrooper& other) const
    {
        return strcmp(id, other.id)
            && strcmp(type, other.type)
            && rank == other.rank
            && planet == other.planet;
    }
    Stormtrooper& operator=(const Stormtrooper& other);
    ~Stormtrooper();
private:
    char* id;
    Stormtrooper::StormtrooperRank rank;
    Planet planet;
    char* type;
};

Stormtrooper::Stormtrooper()
{
    id = NULL;
    rank = Cadet;
    planet.DeletePlanet();
    type = NULL;
}
Stormtrooper::Stormtrooper(char* _id, StormtrooperRank _rank, Planet _planet, char* _type)
{
    this->id = _id;
    this->rank = _rank;
    this->planet = _planet;
    this->type = _type;
}
Stormtrooper::Stormtrooper(const Stormtrooper& other)
{
    this->id = new char[strlen(other.id) + 1];
    this->type = new char[strlen(other.type) + 1];
    strcpy_s(this->id, strlen(other.id) + 1, other.id);
    this->rank = other.rank;
    this->planet = other.planet;
    strcpy_s(this->type, strlen(other.type) + 1, other.type);
}
Stormtrooper& Stormtrooper :: operator=(const Stormtrooper& other)
{
    if (this != &other)
    {
        delete[] id;
        delete[] type;
        this->id = new char[strlen(other.id) + 1];
        this->type = new char[strlen(other.type) + 1];
        strcpy_s(this->id, strlen(other.id) + 1, other.id);
        strcpy_s(this->type, strlen(other.type) + 1, other.type);
        this->rank = other.rank;
        this->planet = other.planet;
    }
    return *this;
}
Stormtrooper::~Stormtrooper()
{
    delete[] id;
    delete[] type;
    planet.~Planet();
    rank = Cadet;
}
void Stormtrooper::print()
{
    std::cout << id << " " << rank << " " << planet.get_name() <<
        " " << type << " " << std::endl;
}

#pragma once
#include <iostream>
#include <string.h>
class Planet {
private:
    char* name;
    char* planetSystem;
    char* republic;

public:
    Planet();
    Planet(const Planet& other);
    Planet(char*, char*, char*);
    void set_name(const char* Name)
    {
        name = new char[strlen(Name) + 1];
        strcpy_s(name, strlen(Name) + 1, Name);
    }
    void set_planetSystem(const char* PlanetSystem)
    {
        planetSystem = new char[strlen(PlanetSystem) + 1];
        strcpy_s(planetSystem, strlen(PlanetSystem) + 1, PlanetSystem);
    }
    void set_republic(const char* Republic)
    {
        republic = new char[strlen(Republic) + 1];
        strcpy_s(republic, strlen(Republic) + 1, Republic);
    }
    char* get_name()
    {
        return name;
    }
    char* get_planetSystem()
    {
        return planetSystem;
    }
    char* get_Republic()
    {
        return republic;
    }
    void print() const;
    bool operator == (const Planet& other) const
    {
        return strcmp(name, other.name)
            && strcmp(planetSystem, other.planetSystem)
            && strcmp(republic, other.republic);
    }
    Planet& operator=(const Planet& other);
    void DeletePlanet();
};
Planet& Planet :: operator=(const Planet& other)
{
    if (this != &other)
    {
        
        name = other.name;
        planetSystem = other.planetSystem;
        republic = other.republic;
        /*this->name = new char[strlen(other.name) + 1];
        this->planetSystem = new char[strlen(other.planetSystem) + 1];
        this->republic = new char[strlen(other.republic) + 1];
        strcpy_s(this->name, strlen(other.name) + 1, other.name);
        strcpy_s(this->planetSystem, strlen(other.planetSystem) + 1, other.planetSystem);
        strcpy_s(this->republic, strlen(other.republic) + 1, other.republic);*/
        
    }
    return *this;
}
Planet::Planet()
{
    name = NULL;
    planetSystem = NULL;
    republic = NULL;
}
Planet::Planet(const Planet& other)
{
    this->name = new char[strlen(other.name) + 1];
    this->planetSystem = new char[strlen(other.planetSystem) + 1];
    this->republic = new char[strlen(other.republic) + 1];
    strcpy_s(this->name, strlen(other.name) + 1, other.name);
    strcpy_s(this->planetSystem, strlen(other.planetSystem) + 1, other.planetSystem);
    strcpy_s(this->republic, strlen(other.republic) + 1, other.republic);
}
Planet::Planet(char* _name, char* _planetSystem, char* _republic)
{
    this->name = _name;
    this->planetSystem = _planetSystem;
    this->republic = _republic;
}
void Planet::DeletePlanet()
{
    delete[] name;
    delete[] planetSystem;
    delete[] republic;
}
void Planet::print() const
{
    std::cout << name << " " << planetSystem <<
        " " << republic << std::endl;
}
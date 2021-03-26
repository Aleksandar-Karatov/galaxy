#include <iostream>
#include <string.h>
#include "Planet.h"


void ToLower(char* string)
{
    for (size_t i = 0; string[i] != NULL; i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] += 32;
        }
    }
}

std::ostream& operator<<(std::ostream& output, const Planet& planet)
{
    output << planet.name << std::endl << planet.planetSystem << std::endl << planet.republic << std::endl;
    switch (planet.typeofplanet)
    {
    case Planet::typeOfPlanet::Chthonian_Planet:
        output << "Chthonian Planet";
        break;
    case Planet::typeOfPlanet::Carbon_Planet:
        output << "Carbon Planet";
        break;
    case Planet::typeOfPlanet::Coreless_Planet:
        output << "Coreless Planet";
        break;
    case Planet::typeOfPlanet::Desert_Planet:
        output << "Desert Planet";
        break;
    case Planet::typeOfPlanet::Gas_Dwarf:
        output << "Gas Dwarf";
        break;
    case Planet::typeOfPlanet::Gas_Giant:
        output << "Gas Giant";
        break;
    case Planet::typeOfPlanet::Helium_Planet:
        output << "Helium Planet";
        break;
    case Planet::typeOfPlanet::Ice_Giant:
        output << "Ice Giant";
        break;
    case Planet::typeOfPlanet::Ice_Planet:
        output << "Ice Planet";
        break;
    case Planet::typeOfPlanet::Iron_Planet:
        output << "Iron Planet";
        break;
    case Planet::typeOfPlanet::Lava_Planet:
        output << "Lava Planet";
        break;
    case Planet::typeOfPlanet::Ocean_Planet:
        output << "Ocean Planet";
        break;
    case Planet::typeOfPlanet::Protoplanet:
        output << "Protoplanet";
        break;
    case Planet::typeOfPlanet::Puffy_Planet:
        output << "Puffy Planet";
        break;
    case Planet::typeOfPlanet::Silicate_Planet:
        output << "Silicate Planet";
        break;
    case Planet::typeOfPlanet::Terrestrial_Planet:
        output << "Terrestrial Planet";
        break;
    default:
        break;
    }
    output << std::endl;
    return output;
}

std::istream& operator>>(std::istream& input, Planet& planet)
{
    char buffer[50];
    input.getline(buffer,50);
    planet.set_name(buffer);
    input.getline(buffer, 50);
    planet.set_planetSystem(buffer);
    input.getline(buffer, 50);
    planet.set_republic(buffer);
    input.getline(buffer, 50);
    ToLower(buffer);
    if (!strcmp(buffer, "chthonian planet"))
    {
        planet.set_type(Planet::typeOfPlanet::Chthonian_Planet);
    }
    else if (!strcmp(buffer, "carbon planet"))
    {
        planet.set_type(Planet::typeOfPlanet::Carbon_Planet);
    }
    else if (!strcmp(buffer, "coreless planet"))
    {
        planet.set_type(Planet::typeOfPlanet::Coreless_Planet);
    }
    else if (!strcmp(buffer, "desert planet"))
    {
        planet.set_type(Planet::typeOfPlanet::Desert_Planet);
    }
    else if (!strcmp(buffer, "gas dwarf"))
    {
        planet.set_type(Planet::typeOfPlanet::Gas_Dwarf);
    }
    else if (!strcmp(buffer, "gas giant"))
    {
        planet.set_type(Planet::typeOfPlanet::Gas_Giant);
    }
    else if (!strcmp(buffer, "helium planet"))
    {
        planet.set_type(Planet::typeOfPlanet::Helium_Planet);
    }
    else if (!strcmp(buffer, "ice giant"))
    {
        planet.set_type(Planet::typeOfPlanet::Ice_Giant);
    }
    else if (!strcmp(buffer, "ice planet"))
    {
        planet.set_type(Planet::typeOfPlanet::Ice_Planet);
    }
    else if (!strcmp(buffer, "iron planet"))
    {
        planet.set_type(Planet::typeOfPlanet::Iron_Planet);
    }
    else if (!strcmp(buffer, "lava planet"))
    {
        planet.set_type(Planet::typeOfPlanet::Lava_Planet);
    }
    else if (!strcmp(buffer, "ocean planet"))
    {
        planet.set_type(Planet::typeOfPlanet::Ocean_Planet);
    }
    else if (!strcmp(buffer, "protoplanet"))
    {
        planet.set_type(Planet::typeOfPlanet::Protoplanet);
    }
    else if (!strcmp(buffer, "puffy planet"))
    {
        planet.set_type(Planet::typeOfPlanet::Puffy_Planet);
    }
    else if (!strcmp(buffer, "silicate planet"))
    {
        planet.set_type(Planet::typeOfPlanet::Silicate_Planet);
    }
    else if (!strcmp(buffer, "terrestrial planet"))
    {
        planet.set_type(Planet::typeOfPlanet::Terrestrial_Planet);
    }
    else
    {
        planet.set_type(Planet::typeOfPlanet::Chthonian_Planet);
    }
    return input;
}

Planet& Planet :: operator=(const Planet& other)
{
    if (this != &other)
    {
        
        this->name = new char[strlen(other.name) + 1];
        this->planetSystem = new char[strlen(other.planetSystem) + 1];
        this->republic = new char[strlen(other.republic) + 1];
        strcpy_s(this->name, strlen(other.name) + 1, other.name);
        strcpy_s(this->planetSystem, strlen(other.planetSystem) + 1, other.planetSystem);
        strcpy_s(this->republic, strlen(other.republic) + 1, other.republic);
        this->typeofplanet = other.typeofplanet;
    }
    return *this;
}
bool Planet:: operator == (const Planet& other) const
{
    return !strcmp(this->name, other.name)
        && !strcmp(this->planetSystem, other.planetSystem)
        && !strcmp(this->republic, other.republic)
        && this->typeofplanet == other.typeofplanet;

}
Planet::Planet()
{
    name = nullptr;
    planetSystem = nullptr;
    republic = nullptr;
    typeofplanet = Gas_Dwarf;
}
Planet::Planet(const Planet& other)
{
    this->name = new char[strlen(other.name) + 1];
    this->planetSystem = new char[strlen(other.planetSystem) + 1];
    this->republic = new char[strlen(other.republic) + 1];
    strcpy_s(this->name, strlen(other.name) + 1, other.name);
    strcpy_s(this->planetSystem, strlen(other.planetSystem) + 1, other.planetSystem);
    strcpy_s(this->republic, strlen(other.republic) + 1, other.republic);
    this->typeofplanet = other.typeofplanet;
}
Planet::Planet(const char* Name, const char* PlanetSystem, const char* Republic, Planet::typeOfPlanet Type)
{
    this->name = new char[strlen(Name) + 1];
    this->planetSystem = new char[strlen(PlanetSystem) + 1];
    this->republic = new char[strlen(Republic) + 1];
    strcpy_s(this->name, strlen(Name) + 1, Name);
    strcpy_s(this->planetSystem, strlen(PlanetSystem) + 1, PlanetSystem);
    strcpy_s(this->republic, strlen(Republic) + 1, Republic);
    this->typeofplanet = Type;
}
Planet::~Planet()
{
    delete[] name;
    delete[] planetSystem;
    delete[] republic;
}



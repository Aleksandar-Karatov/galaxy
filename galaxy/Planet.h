#pragma once
#include <iostream>
#include <string.h>

class Planet {

public:

    enum typeOfPlanet
    {
        Chthonian_Planet,
        Carbon_Planet,
        Coreless_Planet,
        Desert_Planet,
        Gas_Dwarf,
        Gas_Giant,
        Helium_Planet,
        Ice_Giant,
        Ice_Planet,
        Iron_Planet,
        Lava_Planet,
        Ocean_Planet,
        Protoplanet,
        Puffy_Planet,
        Silicate_Planet,
        Terrestrial_Planet

    };
    Planet();
    Planet(const Planet& other);
    Planet(const char*, const char*, const char*, Planet::typeOfPlanet);
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
    void set_type(const Planet::typeOfPlanet Type)
    {
        typeofplanet = Type;
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
    Planet::typeOfPlanet get_type()
    {
        return typeofplanet;
    }

    bool operator == (const Planet& other) const;
    Planet& operator=(const Planet& other);
    friend std::ostream& operator<<(std::ostream& output, const Planet& planet);
    friend std::istream& operator>>(std::istream& input, Planet& planet);
    ~Planet();
private:
    char* name;
    char* planetSystem;
    char* republic;
    typeOfPlanet typeofplanet;

};

template<class T>
void Print(T templ)
{
    std::cout << templ;
}


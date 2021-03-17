// galaxy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include "Planet.h"
#include "Jedi.h"
#include "Stormtrooper.h"


int main()
{
   Planet yavin = Planet();
    yavin.set_name("yavin");
    yavin.set_planetSystem("pancharevo");
    yavin.set_republic("republic");
    yavin.set_type(Planet::Terrestrial_Planet);
    std::cout<<yavin;
    Planet utapau;
    utapau.set_name("utapau");
    utapau.set_planetSystem("pernik");
    utapau.set_republic("separatists");
    utapau.set_type(Planet::Chthonian_Planet);
    std::cout<<utapau;
    utapau = yavin;
    std::cout<<utapau;
   
    Planet manja = Planet("asd","asd","asd",Planet::Gas_Dwarf);
    Planet test = Planet(manja);
    std::cout<<test;
    std::cout<<manja;
    Jedi yoda = Jedi();
    yoda.set_name("Yoda");
    yoda.set_midi_chlorians(900);
    yoda.set_militaryRank("general");
    yoda.set_rank(Jedi::Grand_master);
    yoda.set_species("yodalmao");
    yoda.set_planet(yavin);
    std::cout<<yoda;
    
    Stormtrooper fin = Stormtrooper();
    fin.set_id("FN123451");
    fin.set_planet(Planet(utapau.get_name(),utapau.get_planetSystem(),utapau.get_Republic(),utapau.get_type()));
    fin.set_rank(Stormtrooper::Sergeant);
    fin.set_type("Death trooper");
    
    Stormtrooper bau = fin;
    Jedi lol = yoda;

    if (yavin==utapau)
    {
        std::cout << "hih";
    }
    if (bau==fin)
    {
        std::cout << "lmao";
    }
    if (lol==yoda)
    {
        std::cout << "lol";
    }
}


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
    yavin.print();
    Planet utapau;
    utapau.set_name("utapau");
    utapau.set_planetSystem("pernik");
    utapau.set_republic("separatists");
    utapau.print();
    utapau = yavin;
    utapau.print();
    Jedi yoda = Jedi();
    yoda.set_name("Yoda");
    yoda.set_midi_chlorians(900);
    yoda.set_militaryRank("general");
    yoda.set_rank(Grand_master);
    yoda.set_species("yodalmao");
    yoda.set_planet(yavin);
    yoda.print();

    
    Stormtrooper fin = Stormtrooper();
    fin.set_id("FN123451");
    fin.set_planet(Planet(utapau.get_name(),utapau.get_planetSystem(),utapau.get_Republic()));
    fin.set_rank(Stormtrooper::Sergeant);
    fin.set_type("Death trooper");
    fin.print();




    yavin.DeletePlanet();
}


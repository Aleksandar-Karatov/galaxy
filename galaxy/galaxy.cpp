// galaxy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include "Planet.h"
#include "Jedi.h"
#include "Stormtrooper.h"
#include "BattleShip.h"

//template<typename T>
int main()
{
    Planet utapau;
    utapau.set_name("utapau");
    utapau.set_planetSystem("pernik");
    utapau.set_republic("separatists");
    utapau.set_type(Planet::Chthonian_Planet);

    Jedi yoda = Jedi();
    yoda.set_name("Yoda");
    yoda.set_midi_chlorians(900);
    yoda.set_militaryRank("general");
    yoda.set_rank(Jedi::Grand_master);
    yoda.set_species("yodalmao");
    yoda.set_planet(utapau);
    BattleShip<Jedi> testShip  ;
    //testShip.set_Pilot(yoda);
    //testShip.set_Cannons(123);
    //testShip.set_can_Hyperdrive(true);
    //testShip.set_Size(12314.123);
    //testShip.set_Speed(123.555);
    //std::cout << testShip;
    //Stormtrooper testTrooper;
    //std::cin >> testTrooper;
    //std::cout << testTrooper;
    //Jedi testJedi;
    //std::cin >> testJedi;
    //std::cout << testJedi;
    
    //Planet yavin = Planet();
    //std::cin >> yavin;
    //Print(yavin);
    /*yavin.set_name("yavin");
    yavin.set_planetSystem("pancharevo");
    yavin.set_republic("republic");
    yavin.set_type(Planet::Terrestrial_Planet);
    Print(yavin);
    Planet utapau;
    utapau.set_name("utapau");
    utapau.set_planetSystem("pernik");
    utapau.set_republic("separatists");
    utapau.set_type(Planet::Chthonian_Planet);
    Print(utapau);
    utapau = yavin;

    Print(utapau);
    Planet manja = Planet("asd","asd","asd",Planet::Gas_Dwarf);
    Planet test = Planet(manja);
    Print(test);
    Print(manja);
    Jedi yoda = Jedi();
    yoda.set_name("Yoda");
    yoda.set_midi_chlorians(900);
    yoda.set_militaryRank("general");
    yoda.set_rank(Jedi::Grand_master);
    yoda.set_species("yodalmao");
    yoda.set_planet(yavin);
    Print(yoda);
    
    Stormtrooper fin = Stormtrooper();
    fin.set_id("FN123451");
    fin.set_planet(Planet(utapau.get_name(),utapau.get_planetSystem(),utapau.get_Republic(),utapau.get_type()));
    fin.set_rank(Stormtrooper::Sergeant);
    fin.set_type("Death trooper");
    Print(fin);
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
    }*/
}


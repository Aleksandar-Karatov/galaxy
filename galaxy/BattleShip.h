#pragma once
#include <iostream>
#include <string.h>
#include "Jedi.h"
#include "Stormtrooper.h"
template <class T>
class BattleShip
{
public:
	BattleShip();
	BattleShip(const BattleShip<T>& other);
	BattleShip(const double Speed, const T Pilot, const int Cannons,
		const bool Can_Hyperdrive, const double Size);
	//template <typename Stormtrooper>
	//BattleShip(const double Speed, const Stormtrooper Pilot, const int Cannons,
		//const bool Can_Hyperdrive, const double Size);
	void set_Pilot(const T Pilot)
	{
		pilot = Pilot;
	}
	void set_Speed(const double Speed)
	{
		speed = Speed;
	}
	void set_Cannons(const int Cannons)
	{
		cannons = Cannons;
	}
	void set_can_Hyperdrive(const bool Can_Hyperdrive)
	{
		can_Hyperdrive = Can_Hyperdrive;
	}
	void set_Size(double Size)
	{
		size = Size;
	}
	T get_Pilot()
	{
		return pilot;
	}
	
	double get_Speed()
	{
		return speed;
	}
	int get_Cannons()
	{
		return cannons;
	}
	bool get_Can_Hyperdrive()
	{
		return can_Hyperdrive;
	}
	double get_Size()
	{
		return size;
	}
	bool operator==(const BattleShip<T>& other)const;
	BattleShip& operator=(const BattleShip<T>& other);

	friend std::ostream& operator<<(std::ostream& output, const BattleShip<T>& battleShip);

	friend std::istream& operator>>(std::istream& input, BattleShip<T>& battleShip);


private:
	T pilot;
	double speed;
	int cannons;
	bool can_Hyperdrive;
	double size;
};



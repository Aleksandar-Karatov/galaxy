#pragma once
#include <iostream>
#include <string.h>
#include "Jedi.h"
#include "Stormtrooper.h"
template <typename Pilot>
class BattleShip
{
public:
	BattleShip();
	BattleShip(const BattleShip& other);
	BattleShip(const double Speed, const Jedi Pilot, const int Cannons,
		const bool Can_Hyperdrive, const double Size);
	BattleShip(const double Speed, const Stormtrooper Pilot, const int Cannons,
		const bool Can_Hyperdrive, const double Size);
	void set_Pilot(const Jedi Pilot)
	{
		pilot = Pilot;
	}
	void set_Pilot(const Stormtrooper Pilot)
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
	Pilot get_Pilot()
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
	bool operator==(const BattleShip& other)const;
	BattleShip& operator=(const BattleShip& other);
	friend std::ostream& operator<<(std::ostream& output, const BattleShip& battleShip);
	friend std::istream& operator>>(std::istream& input, BattleShip& battleShip);
	~BattleShip();

private:
	Pilot pilot;
	double speed;
	int cannons;
	bool can_Hyperdrive;
	double size;
};



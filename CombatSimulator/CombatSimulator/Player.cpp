#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "Player.h"
#include "Enemy.h"
#include "Combat.h"

Player::Player()
{
	WeaponType = 0;
	SetName("Unnamed");
	SetWeapon("No Weapon");
	TotalHP = 300;
	CurrentHP = TotalHP;
	SwordMinDmg = 12;
	SwordMaxDmg = 20;
	SwordMissChance = 5;
	SwordCritChance = 10;
	AxeMinDmg = 11;
	AxeMaxDmg = 25;
	AxeMissChance = 7;
	AxeCritChance = 7;
	MaceMinDmg = 15;
	MaceMaxDmg = 30;
	MaceMissChance = 10;
	MaceCritChance = 5;
}

void Player::SetName(std::string a)
{
	Name = a;
}

void Player::EnterName()
{
	std::string a;
	std::cout << "Enter your name!\n";
	std::cin >> a;
	Player::SetName(a);
}

std::string Player::GetName()
{
	return Name;
}

void Player::SetWeapon(std::string a)
{
	Weapon = a;
}

void Player::EnterWeapon()
{
	std::string a;
	do
	{
		std::cout << "Choose your weapon! (sword, axe, mace)\n";
		std::cin >> a;
		if ((a == "sword") || (a == "axe") || (a == "mace"))
		{
			SetWeapon(a);
			if (a == "sword")
			{
				WeaponType = 1;
			}
			if (a == "axe")
			{
				WeaponType = 2;
			}
			if (a == "mace")
			{
				WeaponType = 3;
			}
		}
		else
		{
			std::cout << "Enter a valid weapon!\n";
		}
	} while ((a != "sword") && (a != "axe") && (a != "mace"));
	
}

std::string Player::GetWeapon()
{
	return Weapon;
}

int Player::GetCurrentHP()
{
	return CurrentHP;
}

void Player::SetCurrentHP(int a)
{
	CurrentHP = a;
}

int Player::GetTotalHP()
{
	return TotalHP;
}


int Player::GetCurrentMissChance(int weapon)
{
	if (weapon == 1)
	{
		return SwordMissChance;
	}
	if (weapon == 2)
	{
		return AxeMissChance;
	}
	if (weapon == 3)
	{
		return MaceMissChance;
	}
}

int Player::GetCurrentCritChance(int weapon)
{
	if (weapon == 1)
	{
		return SwordCritChance;
	}
	if (weapon == 2)
	{
		return AxeCritChance;
	}
	if (weapon == 3)
	{
		return MaceCritChance;
	}
}

int Player::GetCurrentMinDmg(int weapon)
{
	if (weapon == 1)
	{
		return SwordMinDmg;
	}
	if (weapon == 2)
	{
		return AxeMinDmg;
	}
	if (weapon == 3)
	{
		return MaceMinDmg;
	}
}

int Player::GetCurrentMaxDmg(int weapon)
{
	if (weapon == 1)
	{
		return SwordMaxDmg;
	}
	if (weapon == 2)
	{
		return AxeMaxDmg;
	}
	if (weapon == 3)
	{
		return MaceMaxDmg;
	}
}

int Player::GetWeaponType()
{
	return WeaponType;
}

void Player::Death()
{
	std::cout << Name << " has died.\nYou lost.\n\n";
}
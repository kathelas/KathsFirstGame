#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "Player.h"
#include "Enemy.h"
#include "Combat.h"

Enemy::Enemy(int XX)
{
	int Seed = XX;

	if (Seed % 3 == 0)
	{
		Type = 0;
		Name = "Goblin";
		TotalHP = rand() % 5 + 50;
		MinDmg = 5;
		MaxDmg = 10;
		CritChance = 5;
		MissChance = 10;
	}

	if (Seed % 3 == 1)
	{
		Type = 1;
		Name = "Troll";
		TotalHP = rand() % 11 + 95;
		MinDmg = 9;
		MaxDmg = 21;
		CritChance = 15;
		MissChance = 5;
	}

	if (Seed % 3 == 2)
	{
		Type = 2;
		Name = "Ogre";
		TotalHP = rand() % 16 + 160;
		MinDmg = 25;
		MaxDmg = 31;
		CritChance = 10;
		MissChance = 10;
	}

	SetCurrentHP(TotalHP);
}

int Enemy::GetType()
{
	return Type;
}

std::string Enemy::GetName()
{
	return Name;
}

int Enemy::GetTotalHP()
{
	return TotalHP;
}

void Enemy::SetCurrentHP(int a)
{
	CurrentHP = a;
}

int Enemy::GetCurrentHP()
{
	return CurrentHP;
}

int Enemy::GetMinDmg()
{
	return MinDmg;
}

int Enemy::GetMaxDmg()
{
	return MaxDmg;
}

int Enemy::GetCritChance()
{
	return CritChance;
}

int Enemy::GetMissChance()
{
	return MissChance;
}

bool Enemy::Loot()
{
	if (((Type == 2) && (rand() % 5 == 0)) || ((Type == 1) && (rand() % 7 == 0)) || ((Type == 0) && (rand() % 10 == 0)))
	{
		return true;
	}
	else
	{
		return false;
	}
}
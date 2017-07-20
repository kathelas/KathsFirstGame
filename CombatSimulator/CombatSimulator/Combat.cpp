#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "Player.h"
#include "Enemy.h"
#include "Combat.h"

Combat::Combat()
{
}

int Combat::HitType(int Seed, int MissChance, int CritChance)
{
	int Roll = Seed % 100 + 1;
	if (Roll > 100 - MissChance)
	{
		return 0;  // Miss
	}
	else
	{
		if (Roll <= CritChance)
		{
			return 2; // Crit
		}
		else
		{
			return 1; // Normal Hit
		}
	}
}

int Combat::GetDmg(int MinDmg, int MaxDmg)
{
	
	int Dmg = MinDmg + (rand() % (1 + MaxDmg - MinDmg));
	return Dmg;
}

bool Combat::GoodWeapon(int WeaponType, int EnemyType)
{
	if (((WeaponType == 1) && (EnemyType == 0)) || ((WeaponType == 2) && (EnemyType == 1)) || ((WeaponType == 3) && (EnemyType == 2)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Combat::PlayerHitsEnemy(Player* Player, Enemy* Enemy)
{
	int Hit = HitType(rand(), Player->GetCurrentMissChance(Player->GetWeaponType()), Player->GetCurrentCritChance(Player->GetWeaponType()));
	if (Hit == 0)  //miss
	{
		std::cout << Player->GetName() << " missed!\n";
	}
	if (Hit == 1)  //normal hit
	{
		if (GoodWeapon(Player->GetWeaponType(), Enemy->GetType()) == true)
		{
			int Dmg = GetDmg(Player->GetCurrentMinDmg(Player->GetWeaponType()), Player->GetCurrentMaxDmg(Player->GetWeaponType()));
			Enemy->SetCurrentHP(Enemy->GetCurrentHP() - (Dmg + 5));
			if (Enemy->GetCurrentHP() <= 0)
			{
				Enemy->SetCurrentHP(0);
			}
			std::cout << Player->GetName() << " hits " << Enemy->GetName() << " for " << Dmg + 5 << ". " << Enemy->GetName() << " has " << Enemy->GetCurrentHP() << "/" << Enemy->GetTotalHP() << " HP left.\n";
		}
		else
		{
			int Dmg = GetDmg(Player->GetCurrentMinDmg(Player->GetWeaponType()), Player->GetCurrentMaxDmg(Player->GetWeaponType()));
			Enemy->SetCurrentHP(Enemy->GetCurrentHP() - Dmg);
			if (Enemy->GetCurrentHP() <= 0)
			{
				Enemy->SetCurrentHP(0);
			}
			std::cout << Player->GetName() << " hits " << Enemy->GetName() << " for " << Dmg << ". " << Enemy->GetName() << " has " << Enemy->GetCurrentHP() << "/" << Enemy->GetTotalHP() << " HP left.\n";
		}
	}
	if (Hit == 2)  //crit
	{
		if (GoodWeapon(Player->GetWeaponType(), Enemy->GetType()) == true)
		{
			int Dmg = GetDmg(Player->GetCurrentMinDmg(Player->GetWeaponType()), Player->GetCurrentMaxDmg(Player->GetWeaponType()));
			Enemy->SetCurrentHP(Enemy->GetCurrentHP() - ((Dmg + 5)) * 2);
			if (Enemy->GetCurrentHP() <= 0)
			{
				Enemy->SetCurrentHP(0);
			}
			std::cout << "Critical hit! " << Player->GetName() << " hits " << Enemy->GetName() << " for " << (Dmg + 5) * 2 << ". " << Enemy->GetName() << " has " << Enemy->GetCurrentHP() << "/" << Enemy->GetTotalHP() << " HP left.\n";
		}
		else
		{
			int Dmg = GetDmg(Player->GetCurrentMinDmg(Player->GetWeaponType()), Player->GetCurrentMaxDmg(Player->GetWeaponType()));
			Enemy->SetCurrentHP(Enemy->GetCurrentHP() - Dmg * 2);
			if (Enemy->GetCurrentHP() <= 0)
			{
				Enemy->SetCurrentHP(0);
			}
			std::cout << "Critical hit! " << Player->GetName() << " hits " << Enemy->GetName() << " for " << Dmg * 2 << ". " << Enemy->GetName() << " has " << Enemy->GetCurrentHP() << "/" << Enemy->GetTotalHP() << " HP left.\n";
		}
	}
}

void Combat::EnemyHitsPlayer(Player* Player, Enemy* Enemy)
{
	int Hit = HitType(rand(), Enemy->GetMissChance(), Enemy->GetCritChance());
	if (Hit == 0)  //miss
	{
		std::cout << Enemy->GetName() << " missed!\n";
	}
	if (Hit == 1)  //normal hit
	{
		int Dmg = GetDmg(Enemy->GetMinDmg(), Enemy->GetMaxDmg());
		Player->SetCurrentHP(Player->GetCurrentHP() - Dmg);
		if (Player->GetCurrentHP() <= 0)
		{
			Player->SetCurrentHP(0);
		}
		std::cout << Enemy->GetName() << " hits " << Player->GetName() << " for " << Dmg << ". " << Player->GetName() << " has " << Player->GetCurrentHP() << "/" << Player->GetTotalHP() << " HP left.\n";
	}
	if (Hit == 2)  //crit
	{
		int Dmg = GetDmg(Enemy->GetMinDmg(), Enemy->GetMaxDmg());
		Player->SetCurrentHP(Player->GetCurrentHP() - Dmg * 2);
		if (Player->GetCurrentHP() <= 0)
		{
			Player->SetCurrentHP(0);
		}
		std::cout << "Critical hit! " << Enemy->GetName() << " hits " << Player->GetName() << " for " << Dmg * 2 << ". " << Player->GetName() << " has " << Player->GetCurrentHP() << "/" << Player->GetTotalHP() << " HP left.\n";
	}
}
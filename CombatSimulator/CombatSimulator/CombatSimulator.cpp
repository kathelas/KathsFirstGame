#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "Player.h"
#include "Enemy.h"
#include "Combat.h"

void Start(Player* Player);
void Fight(Player* Player);
Enemy* CreateEnemy();


Combat CO;
int count = 1;

int main()
{
	srand(time(NULL));
	Player* PO = new Player;
	Start(PO);
	do
	{
		Fight(PO);
	} while (PO->GetCurrentHP() != 0);
	PO->Death();
	delete PO;
	return 0;
}

void Start(Player* Player)
{
	std::cout << "Welcome!\n";
	Player->EnterName();
	std::cout << "Your name is " << Player->GetName() << ".\n";
	std::string a;
	do
	{
		std::cout << "Do you want to start your adventure? (y, n)\n";
		std::cin >> a;
		if (a == "n")
		{
			std::cout << "Think again!\n";
		}
	} while (a != "y");
}

void Fight(Player* Player)
{
	Enemy* E1 = CreateEnemy();
	std::cout << "Your " << count << ". opponent is a " << E1->GetName() << ". It has " << E1->GetCurrentHP() << "/" << E1->GetTotalHP() << " HP.\n";
	std::cout << "You have " << Player->GetCurrentHP() << "/" << Player->GetTotalHP() << " HP.\n";
	Player->EnterWeapon();
	std::cout << "You start the fight.\n...\n";
	do
	{
		CO.PlayerHitsEnemy(Player, E1);
		if (E1->GetCurrentHP() != 0)
		{
			CO.EnemyHitsPlayer(Player, E1);
		}
	} while ((Player->GetCurrentHP() != 0) && (E1->GetCurrentHP() != 0));

	if (E1->GetCurrentHP() == 0)
	{
		std::cout << "You slay " << E1->GetName() << "!\n";
		if (E1->Loot() == true)
		{
			Player->SetCurrentHP(Player->GetTotalHP());
			std::cout << Player->GetName() << " finds a health potion on the remains of " << E1->GetName() << ". " << Player->GetName() << " has his/her HP restored.\n";
		}
		count = count + 1;
	}
	std::cout << "...\n";
	delete E1;
}

Enemy* CreateEnemy()
{
	return new Enemy(rand());
}


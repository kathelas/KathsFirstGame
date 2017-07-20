#pragma once
class Combat
{
public:
	Combat();
	int HitType(int Seed, int MissChance, int CritChance);
	int GetDmg(int MinDmg, int MaxDmg);
	bool GoodWeapon(int WeaponType, int EnemyType);
	void Combat::PlayerHitsEnemy(Player* Player, Enemy* Enemy);
	void Combat::EnemyHitsPlayer(Player* Player, Enemy* Enemy);
};


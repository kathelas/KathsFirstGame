#pragma once
class Enemy
{
public:
	Enemy(int XX);
	std::string GetName();
	int GetTotalHP();
	int GetCurrentHP();
	void SetCurrentHP(int a);
	int GetMinDmg();
	int GetMaxDmg();
	int GetMissChance();
	int GetCritChance();
	bool Loot();
	int GetType();

private:
	std::string Name;
	int TotalHP;
	int CurrentHP;
	int MinDmg;
	int MaxDmg;
	int CritChance;
	int MissChance;
	int Type;
};


#pragma once
class Player
{
public:
	Player();
	void SetName(std::string a);
	void EnterName();
	std::string GetName();
	void SetWeapon(std::string a);
	void EnterWeapon();
	std::string GetWeapon();
	int GetTotalHP();
	int GetCurrentHP();
	void SetCurrentHP(int a);
	int GetCurrentMissChance(int weapon);
	int GetCurrentCritChance(int weapon);
	int GetCurrentMinDmg(int weapon);
	int GetCurrentMaxDmg(int weapon);
	int GetWeaponType();
	void Player::Death();

private:
	std::string Name;
	std::string Weapon;
	int TotalHP;
	int CurrentHP;
	int SwordMinDmg;
	int SwordMaxDmg;
	int SwordMissChance;
	int SwordCritChance;
	int AxeMinDmg;
	int AxeMaxDmg;
	int AxeMissChance;
	int AxeCritChance;
	int MaceMinDmg;
	int MaceMaxDmg;
	int MaceMissChance;
	int MaceCritChance;
	int WeaponType;
};


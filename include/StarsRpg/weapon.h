#pragma once
#include "types.h"
#include "item.h"
#include "corestats.h"
#include <string>

enum class WEAPONTYPE { MELEE, RANGED, NUM_SLOTS };
class Weapon final : public EquipmentDeletage {
public:
	WEAPONTYPE Slot;
	damageType MinDamage;
	damageType MaxDamage;
	bool is2H;
private:
	Weapon(std::string name, CoreStats cstats, WEAPONTYPE slot
		, damageType min, damageType max, bool hand = false);
	Weapon() = delete;
	Weapon(const Weapon&) = delete;
	Weapon(const Weapon&&) = delete;
	~Weapon();
	friend class ItemManager;
};
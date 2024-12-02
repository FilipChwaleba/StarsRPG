#include "weapon.h"

Weapon::Weapon(std::string name, CoreStats cstats, WEAPONTYPE slot
	, damageType min, damageType max, bool hand)
	:EquipmentDeletage(name, cstats), Slot(slot),
	MinDamage(min), MaxDamage(max), is2H(hand) {}

Weapon::~Weapon(){}
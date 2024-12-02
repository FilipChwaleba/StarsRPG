#include "armor.h"

Armor::Armor(std::string name, CoreStats cstats, ARMORSLOT slot)
	:EquipmentDeletage(name, cstats), Slot(slot) {}


Armor::~Armor(){}
#pragma once
#include "item.h"
#include "corestats.h"
#include <string>

enum class ARMORSLOT { HEAD, ARMS, CHEST, BOOTS, RELIC, NUM_SLOTS };
class Armor final : public EquipmentDeletage {
public:
	ARMORSLOT Slot;
private:
	Armor(std::string name, CoreStats cstats, ARMORSLOT slot);
	Armor() = delete;
	Armor(const Armor&) = delete;
	Armor(const Armor&&) = delete;
	~Armor();
	friend class ItemManager;
};

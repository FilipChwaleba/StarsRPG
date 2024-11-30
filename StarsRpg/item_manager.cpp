#include "item_manager.h"
#include "playerCharacter.h"

Item* ItemManager::CreateArmor(std::string name, CoreStats cstats, ARMORSLOT slot) {
	Item* temp_item = new Item(new Armor(name, cstats, slot));
	return temp_item;
}


void ItemManager::CastItemToArmor(const Item* in, Armor*& out) {
	out = dynamic_cast<Armor*>(in->_data);
}

bool ItemManager::IsItemArmor(const Item* in) {
	if (dynamic_cast<Armor*>(in->_data)) return true;
	else return false;
}


void ItemManager::CastItemToWeapon(const Item* in, Weapon*& out) {
	out = dynamic_cast<Weapon*>(in->_data);
}

bool ItemManager::IsItemWeapon(const Item* in) {
	if (dynamic_cast<Weapon*>(in->_data)) return true;
	else return false;
}

void ItemManager::CastItemToConsumable(const Item* in, Consumable*& out) {
	out = dynamic_cast<Consumable*>(in->_data);
}

bool ItemManager::IsItemConsumable(const Item* in) {
	if (dynamic_cast<Consumable*>(in->_data))return true;
	else return false;
}


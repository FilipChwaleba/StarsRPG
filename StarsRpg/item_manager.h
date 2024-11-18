#pragma once
#include "types.h"
#include "item.h"

 class ItemManager {
public:
	static Item* CreateArmor(std::string name, CoreStats cstats, ARMORSLOT slot) {
		Item* temp_item = new Item(new Armor(name, cstats, slot));
		return temp_item;
	}
	static Item* CreateWeapon(std::string name, CoreStats cstats, WEAPONTYPE slot
		, damageType min, damageType max, bool hand = false) {
		Item* temp_item = new Item(new Weapon(name, cstats, slot, min, max, hand));
		return temp_item;
	}
	//robi przynajmniej 1 consumable, wyra¿enie '? : '
	static Item* CreateConsumable(std::string name, wellType well = 1u, itemcount q = 1u, Effect* efc = nullptr){
		
		Item* temp_item = new Item(new Consumable(name, well, (q == 0) ? 1 : q, efc));
		return temp_item; 

	}



};






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


	//Nak³ada Pancerz lub Broñ, zwraca true. Zwraca false przy nieudanej próbie na³o¿enia
	//itemu. Jeœli item by³ ju¿ na³o¿ony w danym slocie, zostanie przeniesiony do ekwipunku
	static bool Equip(Item* item_to_equip, PlayerCharacter* p_char) {
		if (!item_to_equip->GetData() || !item_to_equip || !p_char) { 
			return false;
		}

		Armor* armor = dynamic_cast<Armor*>(item_to_equip->_data); 
		if (armor) {
			unsigned long long slot_num = (unsigned long long)armor->Slot;
			if (p_char->EquippedArmor[slot_num]) {
				//move old item to inventory
				MoveToInventory(p_char->EquippedArmor[slot_num], p_char);
				p_char->EquippedArmor[slot_num] = item_to_equip; 
			}else {//item slot empty
				p_char->EquippedArmor[slot_num] = item_to_equip;  
			}
			return true;
		}

		Weapon* weapon = dynamic_cast<Weapon*>(item_to_equip->_data); 
		if (weapon) {
			unsigned long long slot_num = (unsigned long long)weapon->Slot;
			if (p_char->EquippedWeapon[slot_num]) {
				MoveToInventory(p_char->EquippedWeapon[slot_num], p_char);
				p_char->EquippedWeapon[slot_num] = item_to_equip;
			}
			else {
				p_char->EquippedWeapon[slot_num] = item_to_equip;
			}
			return true;
		}
		return false;
	}
	static bool Use(Item* item_to_use, PlayerCharacter* p_char) {
		if (!item_to_use->GetData() || !item_to_use || !p_char) { 
			return false;
		}

		Consumable* tmp_con = dynamic_cast<Consumable*>(item_to_use->_data);
		if (tmp_con) {
			if (tmp_con->efc) {
				p_char->ApplyEffect(*tmp_con->efc);
			}
			//jeœli hp czy stamina s¹ max, lub gdy nie daje buffów
			//nie u¿ywaæ potek




			if (p_char->pcClass->HP->isFull() && !tmp_con->efc) 
				return false;// don't use potion at max Welltype

			if (p_char->pcClass->Stamina->isFull() && !tmp_con->efc) 
				//return false;	
				// dopóki nie zrobie oddzielnych potek (Stamina i Energia), zakomentowaæ

			//zwiêksz HP lub/i Stamine, mo¿e byæ ustawione na zero
				p_char->pcClass->HP->increaseCurrent(tmp_con->well); 
				p_char->pcClass->Stamina->increaseCurrent(tmp_con->well); 

			//consumable zosta³ u¿yty
			tmp_con->Quantity--;

			if (tmp_con->Quantity == 0) {
				item_to_use->marked_for_deletion = true;
				p_char->cleanup_inventory();
			}
			return true;
		}
	}
	static bool MoveToInventory(Item* item_to_move, PlayerCharacter* p_char) {
			if (!item_to_move->GetData() || !item_to_move || !p_char ) { 
				return false;
			}
		p_char->Inventory.push_back(item_to_move); 
		return true;
	}

};






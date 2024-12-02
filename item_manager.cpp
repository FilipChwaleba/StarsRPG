#include "item_manager.h"
#include "playerCharacter.h"
#include "consumable.h"
#include "armor.h"
#include "weapon.h"

[[nodiscard]]Item* ItemManager::CreateArmor(std::string name, CoreStats cstats, ARMORSLOT slot) {
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

[[nodiscard]] Item* ItemManager::CreateWeapon(std::string name, CoreStats cstats, WEAPONTYPE slot
	, damageType min, damageType max, bool hand) {
	Item* temp_item = new Item(new Weapon(name, cstats, slot, min, max, hand));
	return temp_item;
}
void ItemManager::CastItemToWeapon(const Item* in, Weapon*& out) {
	out = dynamic_cast<Weapon*>(in->_data);
}
bool ItemManager::IsItemWeapon(const Item* in) {
	if (dynamic_cast<Weapon*>(in->_data)) return true;
	else return false;
}

[[nodiscard]] Item* ItemManager::CreateConsumable(std::string name, wellType well , itemcount q , Buff* efc ) {
	Item* temp_item = new Item(new Consumable(name, well, (q == 0) ? 1 : q, efc));
	return temp_item;
}
void ItemManager::CastItemToConsumable(const Item* in, Consumable*& out) {
	out = dynamic_cast<Consumable*>(in->_data);
}

bool ItemManager::IsItemConsumable(const Item* in) {
	if (dynamic_cast<Consumable*>(in->_data))return true;
	else return false;
}

 bool ItemManager::Equip(Item* item_to_equip, PlayerCharacter* p_char) {
	if (!item_to_equip->GetData() || !item_to_equip || !p_char) {
		return false;
	}

	Armor* armor = dynamic_cast<Armor*>(item_to_equip->_data);
	if (armor) {
		unsigned long long slot_num = (unsigned long long)armor->Slot;
		if (p_char->_equipped_armor[slot_num]) {
			//move old item to inventory
			MoveToInventory(p_char->_equipped_armor[slot_num], p_char);
			p_char->_equipped_armor[slot_num] = item_to_equip;
		}
		else {//item slot empty
			p_char->_equipped_armor[slot_num] = item_to_equip;
		}
		return true;
	}

	Weapon* weapon = dynamic_cast<Weapon*>(item_to_equip->_data);
	if (weapon) {
		unsigned long long slot_num = (unsigned long long)weapon->Slot;
		if (p_char->_equipped_weapon[slot_num]) {
			MoveToInventory(p_char->_equipped_weapon[slot_num], p_char);
			p_char->_equipped_weapon[slot_num] = item_to_equip;
		}
		else {
			p_char->_equipped_weapon[slot_num] = item_to_equip;
		}
		return true;
	}
	return false;
}


  bool ItemManager::Use(Item* item_to_use, PlayerCharacter* p_char) {
	 if (!item_to_use->GetData() || !item_to_use || !p_char) {
		 return false;
	 }

	 Consumable* tmp_con = dynamic_cast<Consumable*>(item_to_use->_data);
	 if (tmp_con) {
		 if (tmp_con->_b) {
			 p_char->ApplyBuff(*tmp_con->_b);
		 }
		 //jeœli hp czy stamina s¹ max, lub gdy nie daje buffów
		 //nie u¿ywaæ potek

		 if (p_char->_player_class->HP->isFull() && !tmp_con->_b || 
			 p_char->_player_class->Stamina->isFull() && !tmp_con->_b)
			 return false;// don't use potion at max Welltype


		 //zwiêksz HP lub/i Stamine, mo¿e byæ ustawione na zero
		 p_char->_player_class->HP->increaseCurrent(tmp_con->well);
		 p_char->_player_class->Stamina->increaseCurrent(tmp_con->well);

		 //consumable zosta³ u¿yty
		 tmp_con->Quantity--;

		 if (tmp_con->Quantity == 0) {
			 item_to_use->marked_for_deletion = true;
			 p_char->cleanup_inventory();
		 }
		 return true;
	 }
 }

   bool ItemManager::MoveToInventory(Item* item_to_move, PlayerCharacter* p_char) {
	  if (!item_to_move->GetData() || !item_to_move || !p_char) {
		  return false;
	  }
	  p_char->Inventory.push_back(item_to_move);
	  return true;
  }
    void ItemManager::DeleteItem(Item*& item_to_delete/*, std::vector<Item*>& pack_to_delete_from*/) {
	   delete item_to_delete;
	   item_to_delete = nullptr;
   }
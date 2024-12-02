#pragma once
#include "playerCharacter.h"
#include "types.h"
#include "item.h"
#include "armor.h"
#include "consumable.h"
#include "weapon.h"

class Consumable;
class Armor;
class Weapon;
class PlayerCharacter;


 class ItemManager {
public:

	static Item* CreateArmor(std::string name, CoreStats cstats, ARMORSLOT slot);
	static void CastItemToArmor(const Item* in, Armor*& out);
	static bool IsItemArmor(const Item* in);

	static Item* CreateWeapon(std::string name, CoreStats cstats, WEAPONTYPE slot
		, damageType min, damageType max, bool hand = false);
	static void CastItemToWeapon(const Item* in, Weapon*& out);
	static bool IsItemWeapon(const Item* in);

	//robi przynajmniej 1 consumable, wyrażenie '? : '
	static Item* CreateConsumable(std::string name, wellType well = 1u, itemcount q = 1u, Buff* efc = nullptr);
	static void CastItemToConsumable(const Item* in, Consumable*& out);
	static bool IsItemConsumable(const Item* in);


	//Nakłada Pancerz lub Broń, zwraca true. Zwraca false przy nieudanej próbie nałożenia
	//itemu. Jeśli item był już nałożony w danym slocie, zostanie przeniesiony do ekwipunku
	static bool Equip(Item* item_to_equip, PlayerCharacter* p_char);
	static bool Use(Item* item_to_use, PlayerCharacter* p_char);
	static bool MoveToInventory(Item* item_to_move, PlayerCharacter* p_char);


	static void DeleteItem(Item*& item_to_delete/*, std::vector<Item*>& pack_to_delete_from*/);

};






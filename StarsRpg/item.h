#pragma once
#include "corestats.h"
#include "buff.h"
#include <string>
#include <typeinfo>

class ItemDelegate {
public:
	std::string Name;
	virtual const char* GetType() = 0;
protected:
	ItemDelegate(std::string name) : Name(name){}
};

#define GETTYPE \
const char* GetType() override { return typeid(*this).name(); }



class Consumable final : public ItemDelegate {
public:
	
	Effect* efc;
	wellType well;
	itemcount Quantity;

	~Consumable() {
		if (efc) {
			delete efc;
			efc = nullptr;
		}
	}
		

		GETTYPE
private:
	Consumable(std::string name, wellType w = 1u, itemcount q = 1, Effect* ef = nullptr)
		:ItemDelegate(name), well(w), Quantity(q), efc(ef) {} 

	

	/*Consumable() = delete;
	Consumable(const Consumable&) = delete;
	Consumable(const Consumable&&) = delete;*/

	friend class ItemManager;
};










//=====================================================

class EquipmentDeletage :  public ItemDelegate{
public:
	const std::uint32_t UniqueId;
	CoreStats Stats;
	;
protected:
	EquipmentDeletage(std::string name, CoreStats cstats);
};





//numslot do tablic
enum class ARMORSLOT{ HEAD, ARMS, CHEST, BOOTS, RELIC, NUM_SLOTS};

class Armor final : public EquipmentDeletage {
public:
	ARMORSLOT Slot; 
	GETTYPE

private:
	Armor() = delete;
	Armor(const Armor&) = delete;
	Armor(const Armor&&) = delete;

	Armor(std::string name, CoreStats cstats, ARMORSLOT slot)
		:EquipmentDeletage(name, cstats) , Slot(slot) {}
	friend class ItemManager; 
};

//===============

enum class WEAPONTYPE {MELEE, RANGED, NUM_SLOTS};
class Weapon final : public EquipmentDeletage {
public:
	WEAPONTYPE Slot;
	damageType MinDamage;
	damageType MaxDamage;
	bool is2H;
	GETTYPE

private:
	Weapon(std::string name, CoreStats cstats, WEAPONTYPE slot
	,damageType min, damageType max, bool hand = false)
		:EquipmentDeletage(name, cstats), Slot(slot),
		MinDamage(min),MaxDamage(max),is2H(hand){}

	Weapon() = delete;
	Weapon(const Weapon&) = delete;
	Weapon(const Weapon&&) = delete;

	friend class ItemManager;
};



//use this one in runtime
class Item {
public:
	const ItemDelegate* GetData() { return _data; }
	~Item() {
		if(_data){
			delete _data;
			_data = nullptr;
		}
		
	}
private:
	ItemDelegate* _data;
	Item(ItemDelegate* item) : _data(item) {}
	friend class ItemManager;
	friend class PlayerCharacter; //quickFix
	
};


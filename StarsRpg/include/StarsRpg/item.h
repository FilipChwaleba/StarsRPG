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
#include <iostream> //for outputing tests
class Item {
public:
	const ItemDelegate* GetData() { return _data; }
	~Item() {
		if(_data){
			delete _data;
			_data = nullptr;
		}
		
	}
	const bool getMarkedForDeletion() const{ return marked_for_deletion; } 
private:
	ItemDelegate* _data;
	bool marked_for_deletion = false; 
	Item(ItemDelegate* item) : _data(item) {}
	friend class ItemManager;
	friend class PlayerCharacter;
	
	friend std::ostream& operator<<(std::ostream& os, const Item& t) {
		Armor* tmp_cast = dynamic_cast<Armor*>(t._data);
		if (tmp_cast) {
			return os << tmp_cast->Name 
				<< "(Atk: "  << tmp_cast->Stats.Attack
				<< ", Def: " << tmp_cast->Stats.Defence
				<< ", Atn: " << tmp_cast->Stats.Attunment
				<< ", Wrd: " << tmp_cast->Stats.Warding
				<< ", Spd: " << tmp_cast->Stats.Speed << ")\n";
		}
		Weapon* tmp_cast2 = dynamic_cast<Weapon*>(t._data);
		if (tmp_cast2) {
			return os << tmp_cast2->Name << '(' << tmp_cast2->MinDamage << '/' << tmp_cast2->MaxDamage << ')'
				<< "(Atk: " <<  tmp_cast2->Stats.Attack
				<< ", Def: " << tmp_cast2->Stats.Defence
				<< ", Atn: " << tmp_cast2->Stats.Attunment
				<< ", Wrd: " << tmp_cast2->Stats.Warding
				<< ", Spd: " << tmp_cast2->Stats.Speed << ")\n";
		}
		Consumable* tmp_cast3 = dynamic_cast<Consumable*>(t._data);
		if (tmp_cast3) {
			return os << tmp_cast3->Name << '(' << tmp_cast3->Quantity << ")\n";	
		}
		return os; 
	}
};


#pragma once
#include "corestats.h"
#include "types.h"
#include"statblock.h"
#include"PointWell.h"
#include "abillity.h"
#include "item.h"
#include <string>
#include <memory>
#include <vector>



class PlayerCharacterDelegate : public StatBlock {   
public:
	static const expType LEVEL2AT = 100u; 
	 
	PlayerCharacterDelegate() : StatBlock(0u, 0u) {
		CurrentLevel =(levelType) 1u; 
		CurrentEXP = (expType)0u;  
		EXPToNextLevel = LEVEL2AT;  
		HP = std::make_unique<PointWell>(1u, 1u);  
		Energy = std::make_unique<PointWell>(1u, 1u);
		Stamina = std::make_unique<PointWell>(1u, 1u); 
	}
	void gainEXP(expType gained_exp) {
		CurrentEXP += gained_exp;
		while (check_if_level()) {}
	}

	levelType getLevel()const { return CurrentLevel; }

	expType getCurrentEXP()const { return CurrentEXP; }

	expType getEXPToNextLevel()const { return EXPToNextLevel; }

	void applyEffect(Effect efc){
		AddNewEffect(efc);  
	}
	void applyBuff(Buff b) {
		AddNewBuff(b);
	}
	void applyDebuff(Debuff d) {
		AddNewDebuff(d);
	}

	virtual void LevelUp() = 0;
	virtual std::string getClassName() = 0; 

	std::unique_ptr<PointWell> HP;
	std::unique_ptr<PointWell> Energy; 
	std::unique_ptr<PointWell> Stamina;

	std::vector<Ability> Abilities;

	std::vector<Item*> Inventory;

protected:
	levelType CurrentLevel;
	expType CurrentEXP;
	expType EXPToNextLevel;

	bool check_if_level() {
		static const levelType LEVELSCALAR = 2u;
		if (CurrentEXP >= EXPToNextLevel) {
			CurrentLevel++;
			LevelUp();
			EXPToNextLevel *= LEVELSCALAR; 
			return true;
		}
		return false;
	}
};


#define PCCONSTRUCT   \
HP->setMax(BASEHP);\
HP->increaseCurrent(BASEHP);\
	Energy->setMax(BASEENR); \
	/*Energy->increaseCurrent(BASEENR); \*/ \
	Stamina->setMax(BASESTM);\
	Stamina->increaseCurrent(BASESTM);\
statBoost(BASEATK, BASEATN, BASESPD);
//energy->increaseCurrent zakomentowane, bo powinno zaczynaæ siê z zerow¹ pul¹, i na³adowaæ w trakcie walki
//stamina mo¿e sobie rosn¹æ, g³ówny surowiec do skilli, nie do ultów

#define LEVELUP \
HP->setMax((wellType)((BASEHP / 2.f) + HP->getMax()));\
HP->increaseCurrent((wellType)((BASEHP / 2.f))); \
Energy->setMax((wellType)((BASEENR / 2.f) + Energy->getMax())); \
/*Energy->increaseCurrent((wellType)((BASEENR / 2.f)));*/ \
Stamina->setMax((wellType)((BASESTM / 2.f) + Stamina->getMax())); \
Stamina->increaseCurrent((wellType)((BASESTM / 2.f))); \
statBoost((statType)((BASEATK + 1u) / 2.f), (statType)((BASEATN + 1u) / 2.f), (statType)((BASESPD + 1u) / 2.f));

//to samo tutaj, pula energia mo¿e rosn¹æ w raz z levelami, lecz nie jej obecny stan
//ewentualnie moge zwiêkanie puli te¿ wykasowaæ, aby z góry by³o to zadeklarowane


//DEKLARACJA KLAS GRYWALNYCH

class Oracle : public PlayerCharacterDelegate {
 public:
	static const wellType BASEHP = (wellType)15u;
	static const statType BASEATK = (statType)6u;
	static const statType BASEATN = (statType)9u;
	static const statType BASESPD = (statType)7u;
	static const wellType BASEENR = (wellType)8u;
	static const wellType BASESTM = (wellType)14u;
	std::string getClassName() override {return std::string("Oracle"); }
	Oracle() :PlayerCharacterDelegate() {
		
		PCCONSTRUCT
			
		Abilities.emplace_back("Mending Flames", 2u,1u,ABILITYTARGET::ALLY, 2u, ABILLITYSCALAR::STM); 
	}
		//abillity : name, cost, cooldown, target, damage, scaling
	
private:
	void LevelUp() override {
	LEVELUP 
	if (CurrentLevel == 2) {
		Abilities.emplace_back("Blazing Chains", 3u, 2u, ABILITYTARGET::ENEMY, 5u, ABILLITYSCALAR::ATN);

		Stamina->setMax(1u + Stamina->getMax());
		Stamina->increaseCurrent(1u); 
		}

  }
};

class Interlacer : public PlayerCharacterDelegate {
public:
	static const wellType BASEHP = (wellType)9u;
	static const statType BASEATK = (statType)3u;
	static const statType BASEATN = (statType)18u;
	static const statType BASESPD = (statType)5u;
	static const wellType BASEENR = (wellType)14u;
	static const wellType BASESTM = (wellType)8u;
	std::string getClassName() override { return std::string("Interlacer"); }
	Interlacer() :PlayerCharacterDelegate() {

		PCCONSTRUCT

			Abilities.emplace_back("Surge of Neptune", 2u, 1u, ABILITYTARGET::ENEMY, 6u, ABILLITYSCALAR::ATN); 
	}
	//abillity : name, cost, cooldown, target, damage, scaling

private:
	void LevelUp() override {
		LEVELUP
			if (CurrentLevel == 2) {
				Abilities.emplace_back("Tranquil Waterplain", 1u, 2u, ABILITYTARGET::SELF, 10u, ABILLITYSCALAR::ENR);  
				HP->setMax(2u + HP->getMax());
				HP->increaseCurrent(2u);
				statBoost(0, 2, 0, 0, 1);
			} 

	}
};

class Justiciar : public PlayerCharacterDelegate {
public:
	static const wellType BASEHP = (wellType)18u;
	static const statType BASEATK = (statType)10u;
	static const statType BASEATN = (statType)2u;
	static const statType BASESPD = (statType)3u;
	static const wellType BASEENR = (wellType)8u;
	static const wellType BASESTM = (wellType)12u;
	std::string getClassName() override { return std::string("Justiciar"); }
	Justiciar() :PlayerCharacterDelegate() { 

		PCCONSTRUCT

			Abilities.emplace_back("Frozen Bulwark", 3u, 1u, ABILITYTARGET::ALLY, 7u, ABILLITYSCALAR::DEF);
	}
	//abillity : name, cost, cooldown, target, damage, scaling

private:
	void LevelUp() override {
		LEVELUP
			if (CurrentLevel == 2) {
				Abilities.emplace_back("Gnawing Glacier", 4u, 2u, ABILITYTARGET::ENEMY, 6u, ABILLITYSCALAR::ATK); 
				statBoost(0, 0, 0, 2, 2);
			}

	}
};

class Unveiler : public PlayerCharacterDelegate {
public:
	static const wellType BASEHP = (wellType)10u;
	static const statType BASEATK = (statType)14u;
	static const statType BASEATN = (statType)6u;
	static const statType BASESPD = (statType)12u;
	static const wellType BASEENR = (wellType)8u;
	static const wellType BASESTM = (wellType)10u;
	std::string getClassName() override { return std::string("Unveiler"); }
	Unveiler() :PlayerCharacterDelegate() { 

		PCCONSTRUCT

			Abilities.emplace_back("Prowl of the Storm", 2u, 1u, ABILITYTARGET::ALLY, 3u, ABILLITYSCALAR::SPD); 
	}
	//abillity : name, cost, cooldown, target, damage, scaling

private:
	void LevelUp() override {
		LEVELUP
			if (CurrentLevel == 2) {
				Abilities.emplace_back("Jaged Thunder", 4u, 1u, ABILITYTARGET::ENEMY, 5u, ABILLITYSCALAR::ATK);   

				statBoost(1, 0, 2, 0, 0);
			}

	}
};

class PlayerCharacter	
{
private:
	PlayerCharacterDelegate* pcClass;
	EquipmentDeletage* EquippedArmor[(unsigned long long)ARMORSLOT::NUM_SLOTS];
	EquipmentDeletage* EquippedWeapon[(unsigned long long)WEAPONTYPE::NUM_SLOTS];

	
public:
	
	PlayerCharacter(PlayerCharacterDelegate* pc):pcClass(pc) {
		auto i = 0;
		for (i; i < (unsigned long long)ARMORSLOT::NUM_SLOTS; i++) {
			EquippedArmor[i] = nullptr;
		}
		for (i; i < (unsigned long long)WEAPONTYPE::NUM_SLOTS; i++) {
			EquippedWeapon[i] = nullptr;
		}
	}
	~PlayerCharacter() { 
		delete pcClass;
		pcClass = nullptr;
		auto i = 0;
		for (i; i < (unsigned long long)ARMORSLOT::NUM_SLOTS; i++) {
			if (EquippedArmor[i]){
				delete EquippedArmor[i];
				EquippedArmor[i] = nullptr;
			}
		}
		for (i; i < (unsigned long long)WEAPONTYPE::NUM_SLOTS; i++) {
			if (EquippedWeapon[i]) {
				delete EquippedWeapon[i];
				EquippedWeapon[i] = nullptr;
			}
		}
	}
	//Getters
	std::string getClassName() { return pcClass->getClassName(); }
	levelType getLevel() { return pcClass->getLevel(); }
	expType getCurrentEXP() { return pcClass->getCurrentEXP(); }
	expType getEXPToNextLevel() { return pcClass->getEXPToNextLevel(); }

	wellType getCurrentHP() { return pcClass->HP->getCur(); }
	wellType getMaxHP() { return pcClass->HP->getMax(); }
	wellType getCurrentEnergy() { return pcClass->Energy->getCur() - 1; } //zaczynamy z pust¹ pul¹
	wellType getMaxEnergy() { return pcClass->Energy->getMax(); }
	wellType getCurrentStamina() { return pcClass->Stamina->getCur(); }
	wellType getMaxStamina() { return pcClass->Stamina->getMax(); }

	statType getBaseAttack() { return pcClass->getBaseAttack(); }
	statType getBaseDefence() { return pcClass->getBaseDefence(); }
	statType getBaseAttunment() { return pcClass->getBaseAttunement(); }
	statType getBaseWarding() { return pcClass->getBaseWarding(); }
	statType getBaseSpeed() { return pcClass->getBaseSpeed(); }

	statType getTotalAttack()   { 
		statType atkFromItems = 0;
		//z pancerza
		for (auto i = 0; i < (unsigned long long)ARMORSLOT::NUM_SLOTS; i++) {
			if (EquippedArmor[i]) {
				atkFromItems += EquippedArmor[i]->Stats.Attack;
			}
		}
		//z broni
		for (auto j = 0; j < (unsigned long long)WEAPONTYPE::NUM_SLOTS; j++) {
			if (EquippedWeapon[j]) {
				atkFromItems += EquippedWeapon[j]->Stats.Attack;
			}
		}

		return pcClass->getTotalAttack() + atkFromItems; }
	statType getTotalDefence()  {
		statType defFromItems = 0;
		//z pancerza
		for (auto i = 0; i < (unsigned long long)ARMORSLOT::NUM_SLOTS; i++) { 
			if (EquippedArmor[i]) {
				defFromItems += EquippedArmor[i]->Stats.Defence;
			}
		}

		//z broni
		for (auto j = 0; j < (unsigned long long)WEAPONTYPE::NUM_SLOTS; j++) {
			if (EquippedWeapon[j]) {
				defFromItems += EquippedWeapon[j]->Stats.Defence;
			}
		}
		return pcClass->getTotalDefence() + defFromItems; }
	statType getTotalAttunment(){ 
		statType atnFromItems = 0;
		//z pancerza
		for (auto i = 0; i < (unsigned long long)ARMORSLOT::NUM_SLOTS; i++) {
			if (EquippedArmor[i]) {
				atnFromItems += EquippedArmor[i]->Stats.Attunment;
			}
		}
		//z broni
		for (auto j = 0; j < (unsigned long long)WEAPONTYPE::NUM_SLOTS; j++) {
			if (EquippedWeapon[j]) {
				atnFromItems += EquippedWeapon[j]->Stats.Attunment;
			}
		}
		return pcClass->getTotalAttunement() + atnFromItems; }
	statType getTotalWarding()  { 
		statType wrdFromItems = 0;
		//z pancerza
		for (auto i = 0; i < (unsigned long long)ARMORSLOT::NUM_SLOTS; i++) {
			if (EquippedArmor[i]) {
				wrdFromItems += EquippedArmor[i]->Stats.Warding; 
			}
		}
		//z broni
		for (auto j = 0; j < (unsigned long long)WEAPONTYPE::NUM_SLOTS; j++) {
			if (EquippedWeapon[j]) {
				wrdFromItems += EquippedWeapon[j]->Stats.Warding;
			}
		}
		return pcClass->getTotalWarding() + wrdFromItems; }
	statType getTotalSpeed()    { 
		statType spdFromItems = 0;
		//z pancerza
		for (auto i = 0; i < (unsigned long long)ARMORSLOT::NUM_SLOTS; i++) {
			if (EquippedArmor[i]) {
				spdFromItems += EquippedArmor[i]->Stats.Speed; 
			}
		}
		//z broni
		for (auto j = 0; j < (unsigned long long)WEAPONTYPE::NUM_SLOTS; j++) {
			if (EquippedWeapon[j]) {
				spdFromItems += EquippedWeapon[j]->Stats.Speed;
			}
		}
		return pcClass->getTotalSpeed() + spdFromItems; }

	std::vector<Ability> getAbilityList() const { return pcClass->Abilities; }

	EquipmentDeletage* getEquippedArmorAt(unsigned long long i) {
		 return dynamic_cast<Armor*>(EquippedArmor[i]); 
	 }
	EquipmentDeletage* getEquippedWeaponAt(unsigned long long i) {
		 return dynamic_cast<Weapon*>(EquippedWeapon[i]);
	 }
	

	//Modifiers
	void gainEXP(expType amt) { pcClass->gainEXP(amt); } 
	void takeDamage(wellType amt) { pcClass->HP->reduceCurrent(amt); }
	void heal(wellType amt) { pcClass->HP->increaseCurrent(amt); }


	void ApplyEffect(Effect efc) { 
		pcClass->applyEffect(efc);   
	}
	void ApplyBuff(Buff buff) {
		pcClass->applyBuff(buff);
	}
	void ApplyDebuff(Debuff d) {
		pcClass->applyDebuff(d);
	}

	// todo : update once inventory implemened
	bool equip(Item* equip) { 
		if (!equip) { return false; }
		if (!equip->GetData()) {
			return false;
		}

		Armor* armor = dynamic_cast<Armor*>(equip->_data);
		if (armor) {
			unsigned long long slot_num = (unsigned long long)armor->Slot;
			if (EquippedArmor[slot_num]) {
				delete EquippedArmor[slot_num];
				EquippedArmor[slot_num] = nullptr;
				EquippedArmor[slot_num] = armor;
			}
			else {
				EquippedArmor[slot_num] = armor;
			}
		return true;
		}

		Weapon* weapon = dynamic_cast<Weapon*>(equip->_data); 
		if (weapon) {
			unsigned long long slot_num = (unsigned long long)weapon->Slot;
			if (EquippedWeapon[slot_num]) {
				delete EquippedWeapon[slot_num]; //powinno iœæ do inventory
				EquippedWeapon[slot_num] = nullptr;
				EquippedWeapon[slot_num] = armor;
			}
			else {
				EquippedWeapon[slot_num] = weapon;
			}
		return true;
		}
		return false;
	}


	bool use(Item* item_to_use) {
		if (!item_to_use) { return false; } 
		if (!item_to_use->GetData()) { 
			return false;
		}

		Consumable* tmp_con = dynamic_cast<Consumable*>(item_to_use->_data);
		if (tmp_con) { 
			if (tmp_con->efc) { 
				ApplyEffect(*tmp_con->efc); 
			}
			//jeœli hp czy stamina s¹ max, lub gdy nie daje buffów
			//nie u¿ywaæ potek
			

		 
			
		 if (pcClass->HP->isFull() && !tmp_con->efc)
			 return false;// don't use potion at max Welltype

		 if (pcClass->Stamina->isFull() && !tmp_con->efc)
			 //return false;	dopóki nie zrobie oddzielnych potek, zakomentowaæ

		 //zwiêksz HP lub/i Stamine, mo¿e byæ ustawione na zero
		 pcClass->HP->increaseCurrent(tmp_con->well);
		 pcClass->Stamina->increaseCurrent(tmp_con->well);

		 //consumable zosta³ u¿yty
		 tmp_con->Quantity--;
		 
		 if (tmp_con->Quantity == 0) {
			 delete tmp_con;
			 tmp_con = nullptr;
		 }
		 return true;
		}
	}

	PlayerCharacter() = delete;
	PlayerCharacter(const PlayerCharacter&) = delete;
	PlayerCharacter(const PlayerCharacter&&) = delete;
};
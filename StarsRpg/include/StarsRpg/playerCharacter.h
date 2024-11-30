#pragma once
#include "types.h"
#include"statblock.h"
#include"PointWell.h"
#include "abillity.h"
#include "corestats.h"
#include "item.h"
#include "buff.h"
#include <string>
#include <memory>
#include <vector>
#include <algorithm>



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

	std::vector<Effect>getEffectList() {
		return Effects;
	}
	std::vector<Buff>getBuffList() {
		return Buffs;
	}
	std::vector<Debuff>getDebuffList() {
		return Debuffs;
	}

	virtual void LevelUp() = 0;
	virtual std::string getClassName() = 0; 

	std::unique_ptr<PointWell> HP;
	std::unique_ptr<PointWell> Energy; 
	std::unique_ptr<PointWell> Stamina;

	std::vector<Ability> Abilities;


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
	Item* EquippedArmor[(unsigned long long)ARMORSLOT::NUM_SLOTS];
	Item* EquippedWeapon[(unsigned long long)WEAPONTYPE::NUM_SLOTS];
	std::vector<Item*> Inventory;
	friend class ItemManager;
	
	void cleanup_inventory() {
		const auto to_remove = std::stable_partition(Inventory.begin(), Inventory.end(),
			[](const Item* i) ->bool {return !i->getMarkedForDeletion(); });
		std::for_each(to_remove, Inventory.end(), [](Item*& i) {/*ItemManager::DeleteItem(i)*/delete(i);});
		Inventory.erase(to_remove, Inventory.end());
		
	};

public:

	PlayerCharacter(PlayerCharacterDelegate* pc) :pcClass(pc) {
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
			if (EquippedArmor[i]) {
				//ItemManager::DeleteItem(EquippedArmor[i]);
				delete EquippedArmor[i];
				EquippedArmor[i] = nullptr;
			}
		}
		for (i; i < (unsigned long long)WEAPONTYPE::NUM_SLOTS; i++) {
			if (EquippedWeapon[i]) {
				//ItemManager::DeleteItem(EquippedWeapon[i]);
				delete EquippedWeapon[i];
				EquippedWeapon[i] = nullptr;
				
			}
		}
		//Getters
	}
			std::string getClassName() const { return pcClass->getClassName(); }
			levelType getLevel() const { return pcClass->getLevel(); }
			expType getCurrentEXP() const { return pcClass->getCurrentEXP(); }
			expType getEXPToNextLevel() const { return pcClass->getEXPToNextLevel(); }

			wellType getCurrentHP() const { return pcClass->HP->getCur(); }
			wellType getMaxHP() const { return pcClass->HP->getMax(); }
			wellType getCurrentEnergy()const { return pcClass->Energy->getCur() - 1; } //zaczynamy z pust¹ pul¹
			wellType getMaxEnergy() const { return pcClass->Energy->getMax(); }
			wellType getCurrentStamina() const { return pcClass->Stamina->getCur(); }
			wellType getMaxStamina()const { return pcClass->Stamina->getMax(); }

			statType getBaseAttack() const { return pcClass->getBaseAttack(); }
			statType getBaseDefence() const { return pcClass->getBaseDefence(); }
			statType getBaseAttunment()const { return pcClass->getBaseAttunement(); }
			statType getBaseWarding() const { return pcClass->getBaseWarding(); }
			statType getBaseSpeed() const { return pcClass->getBaseSpeed(); }

			statType getTotalAttack()const {
				statType atkFromItems = 0;
				//z pancerza
				for (auto i = 0; i < (unsigned long long)ARMORSLOT::NUM_SLOTS; i++) {
					if (EquippedArmor[i]) {
						Armor* armor = dynamic_cast<Armor*>(EquippedArmor[i]->_data);
						atkFromItems += armor->Stats.Attack;
					}
				}
				//z broni
				for (auto j = 0; j < (unsigned long long)WEAPONTYPE::NUM_SLOTS; j++) {
					if (EquippedWeapon[j]) {
						Weapon* weapon = dynamic_cast<Weapon*>(EquippedWeapon[j]->_data);
						atkFromItems += weapon->Stats.Attack;
					}
				}

				return pcClass->getTotalAttack() + atkFromItems;
			}
			statType getTotalDefence()const {
				statType defFromItems = 0;
				//z pancerza
				for (auto i = 0; i < (unsigned long long)ARMORSLOT::NUM_SLOTS; i++) {
					if (EquippedArmor[i]) {
						Armor* armor = dynamic_cast<Armor*>(EquippedArmor[i]->_data);
						defFromItems += armor->Stats.Defence;
					}
				}

				//z broni
				for (auto j = 0; j < (unsigned long long)WEAPONTYPE::NUM_SLOTS; j++) {
					if (EquippedWeapon[j]) {
						Weapon* weapon = dynamic_cast<Weapon*>(EquippedWeapon[j]->_data);
						defFromItems += weapon->Stats.Defence;
					}
				}
				return pcClass->getTotalDefence() + defFromItems;
			}
			statType getTotalAttunment()const {
				statType atnFromItems = 0;
				//z pancerza
				for (auto i = 0; i < (unsigned long long)ARMORSLOT::NUM_SLOTS; i++) {
					if (EquippedArmor[i]) {
						Armor* armor = dynamic_cast<Armor*>(EquippedArmor[i]->_data);
						atnFromItems += armor->Stats.Attunment;
					}
				}
				//z broni
				for (auto j = 0; j < (unsigned long long)WEAPONTYPE::NUM_SLOTS; j++) {
					if (EquippedWeapon[j]) {
						Weapon* weapon = dynamic_cast<Weapon*>(EquippedWeapon[j]->_data);
						atnFromItems += weapon->Stats.Attunment;
					}
				}
				return pcClass->getTotalAttunement() + atnFromItems;
			}
			statType getTotalWarding()const {
				statType wrdFromItems = 0;
				//z pancerza
				for (auto i = 0; i < (unsigned long long)ARMORSLOT::NUM_SLOTS; i++) {
					if (EquippedArmor[i]) {
						Armor* armor = dynamic_cast<Armor*>(EquippedArmor[i]->_data);
						wrdFromItems += armor->Stats.Warding;
					}
				}
				//z broni
				for (auto j = 0; j < (unsigned long long)WEAPONTYPE::NUM_SLOTS; j++) {
					if (EquippedWeapon[j]) {
						Weapon* weapon = dynamic_cast<Weapon*>(EquippedWeapon[j]->_data);
						wrdFromItems += weapon->Stats.Warding;
					}
				}
				return pcClass->getTotalWarding() + wrdFromItems;
			}
			statType getTotalSpeed()const {
				statType spdFromItems = 0;
				//z pancerza
				for (auto i = 0; i < (unsigned long long)ARMORSLOT::NUM_SLOTS; i++) {
					if (EquippedArmor[i]) {
						Armor* armor = dynamic_cast<Armor*>(EquippedArmor[i]->_data);
						spdFromItems += armor->Stats.Speed;
					}
				}
				//z broni
				for (auto j = 0; j < (unsigned long long)WEAPONTYPE::NUM_SLOTS; j++) {
					if (EquippedWeapon[j]) {
						Weapon* weapon = dynamic_cast<Weapon*>(EquippedWeapon[j]->_data);
						spdFromItems += weapon->Stats.Speed;
					}
				}
				return pcClass->getTotalSpeed() + spdFromItems;
			}

			// const std::vector<Effect> getEffectList(){return pcClass->get }
			const std::vector<Item*> getInventoryList()const { return Inventory; }
			const std::vector<Ability> getAbilityList() const { return pcClass->Abilities; }

			Armor* getEquippedArmorAt(unsigned long long i) const {
				if (!EquippedArmor[i]) return nullptr;
				return dynamic_cast<Armor*>(EquippedArmor[i]->_data);
			}

			Weapon* getEquippedWeaponAt(unsigned long long i) const {
				if (!EquippedWeapon[i]) return nullptr;
				return dynamic_cast<Weapon*>(EquippedWeapon[i]->_data);
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


			PlayerCharacter() = delete;
			PlayerCharacter(const PlayerCharacter&) = delete;
			PlayerCharacter(const PlayerCharacter&&) = delete;

		};
	


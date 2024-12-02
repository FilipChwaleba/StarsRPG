#pragma once
#include "types.h"
#include"statblock.h"
#include"PointWell.h"
#include "abillity.h"
#include "corestats.h"
#include "item.h"
#include "item_manager.h"
#include "equipment_fwd.h"//armor, conumable, weapon
#include "appliable_fwd.h"//efffect, buff, debuff
#include <string>
#include <memory>
#include <vector>
#include <algorithm>



class PlayerCharacterDelegate : public StatBlock {   
public:
	static const expType LEVEL2AT = 100u; 
	PlayerCharacterDelegate();
	virtual ~PlayerCharacterDelegate() = 0;
	void gainEXP(expType gained_exp);

	std::unique_ptr<PointWell> HP;
	std::unique_ptr<PointWell> Energy;
	std::unique_ptr<PointWell> Stamina;
	std::vector<Ability> Abilities;

	std::vector<Effect> Effects;
	std::vector<Buff> Buffs;
	std::vector<Debuff> Debuffs;
	
	[[nodiscard]] levelType getLevel()const noexcept;
	[[nodiscard]] expType getCurrentEXP()const noexcept;
	[[nodiscard]] expType getEXPToNextLevel()const noexcept;

	void applyEffect(Effect efc)noexcept{
		AddNewEffect(efc);  
	}
	void applyBuff(Buff b)noexcept {
		AddNewBuff(b);
	}
	void applyDebuff(Debuff d)noexcept {
		AddNewDebuff(d);
	}
	//virtual std::string getClassName() = 0; 
protected:
	levelType CurrentLevel;
	expType CurrentEXP;
	expType EXPToNextLevel;
	virtual void LevelUp()noexcept = 0; 
	[[nodiscard]] const bool check_if_level()noexcept;
};

//to samo tutaj, pula energia mo¿e rosn¹æ w raz z levelami, lecz nie jej obecny stan
//ewentualnie moge zwiêkanie puli te¿ wykasowaæ, aby z góry by³o to zadeklarowane

class PlayerCharacter final
{

public:

	PlayerCharacter(PlayerCharacterDelegate* pc);
	~PlayerCharacter();

			 //[[nodiscard]] const std::string getClassName()  const noexcept;
			 [[nodiscard]] const levelType getLevel()        const noexcept;
			 [[nodiscard]] const expType getCurrentEXP()     const noexcept;
			 [[nodiscard]] const expType getEXPToNextLevel() const noexcept;
																		   
			 [[nodiscard]] const wellType getCurrentHP()     const noexcept;
			 [[nodiscard]] const wellType getMaxHP()         const noexcept;
			 [[nodiscard]] const wellType getCurrentEnergy() const noexcept; //zaczynamy z pust¹ pul¹
			 [[nodiscard]] const wellType getMaxEnergy()     const noexcept;
			 [[nodiscard]] const wellType getCurrentStamina()const noexcept;
			 [[nodiscard]] const wellType getMaxStamina()    const noexcept;
																		   
			 [[nodiscard]] const statType getBaseAttack()    const noexcept;
			 [[nodiscard]] const statType getBaseDefence()   const noexcept;
			 [[nodiscard]] const statType getBaseAttunment() const noexcept;
			 [[nodiscard]] const statType getBaseWarding()   const noexcept;
			 [[nodiscard]] const statType getBaseSpeed()     const noexcept;

			 [[nodiscard]] const statType getTotalAttack()const noexcept;
			 [[nodiscard]] const statType getTotalDefence()const noexcept;
			 [[nodiscard]] const statType getTotalAttunment()const noexcept;
			 [[nodiscard]] const statType getTotalWarding()const noexcept;
			 [[nodiscard]] const statType getTotalSpeed()const noexcept;

			// const std::vector<Effect> getEffectList(){return _player_class->get }
			[[nodiscard]] const std::vector<Item*> getInventoryList()const noexcept;
			[[nodiscard]] const std::vector<Ability> getAbilityList()const noexcept;
			[[nodiscard]] const std::vector<Effect>getEffectList()const noexcept;
			[[nodiscard]]  const std::vector<Buff>getBuffList()const noexcept;
			[[nodiscard]]  const std::vector<Debuff>getDebuffList()const noexcept;

			[[nodiscard]] const Armor* get_equipped_armorAt(unsigned long long i) const noexcept;
			[[nodiscard]] const Weapon* get_equipped_weaponAt(unsigned long long i) const noexcept;


			//Modifiers
			void gainEXP(expType amt)noexcept;
			void takeDamage(wellType amt)noexcept;
			void heal(wellType amt)noexcept;
			void restoreStamina(wellType amt)noexcept;
			void restoreEnergy(wellType amt)noexcept;

			void ApplyEffect(Effect _efc)noexcept; 
			void ApplyBuff(Buff _buff)noexcept;
			void ApplyDebuff(Debuff _debuff)noexcept; 

private:
	PlayerCharacterDelegate* _player_class;
	Item* _equipped_armor[(unsigned long long)ARMORSLOT::NUM_SLOTS];
	Item* _equipped_weapon[(unsigned long long)WEAPONTYPE::NUM_SLOTS];
	std::vector<Item*> Inventory;
	friend class ItemManager;

	void cleanup_inventory()noexcept;

	void move_to_inventory(Item* item_to_move)noexcept;


	PlayerCharacter() = delete;
	PlayerCharacter(const PlayerCharacter&) = delete;
	PlayerCharacter(const PlayerCharacter&&) = delete;
};
	


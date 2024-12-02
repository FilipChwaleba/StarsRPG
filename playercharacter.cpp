#include "playerCharacter.h"
#include <memory>

PlayerCharacterDelegate::~PlayerCharacterDelegate(){}

void PlayerCharacterDelegate::gainEXP(expType gained_exp) {
	CurrentEXP += gained_exp;
	while (check_if_level()) {}
}

 PlayerCharacterDelegate::PlayerCharacterDelegate() 
	: StatBlock(0u, 0u) {
		CurrentLevel = (levelType)1u;
		CurrentEXP = (expType)0u;
		EXPToNextLevel = LEVEL2AT;
}

 [[nodiscard]] levelType PlayerCharacterDelegate::getLevel()const noexcept { return CurrentLevel; }
 [[nodiscard]] expType PlayerCharacterDelegate::getCurrentEXP()const noexcept { return CurrentEXP; }
 [[nodiscard]] expType PlayerCharacterDelegate::getEXPToNextLevel()const noexcept { return EXPToNextLevel; }

 [[nodiscard]] const bool PlayerCharacterDelegate::check_if_level()noexcept {
	 static const levelType LEVELSCALAR = 2u; 
	 if (CurrentEXP >= EXPToNextLevel) { 
		 CurrentLevel++; 
		 LevelUp(); 
		 EXPToNextLevel *= LEVELSCALAR; 
		 return true;
	 }
	 return false;
 }
 //==================================
 //PlayerCharacter
 //==================================
 void PlayerCharacter::move_to_inventory(Item* item_to_move)noexcept {
	 Inventory.push_back(item_to_move);
 }

 void PlayerCharacter::cleanup_inventory()noexcept {
	 const auto to_remove = std::stable_partition(Inventory.begin(), Inventory.end(),
		 [](const Item* i) ->bool {return !i->getMarkedForDeletion(); }
	 );
	 std::for_each(to_remove, Inventory.end(), [](Item*& i) {ItemManager::DeleteItem(i); });
	 Inventory.erase(to_remove, Inventory.end());
 }

 PlayerCharacter::PlayerCharacter(PlayerCharacterDelegate* pc) :_player_class(pc) {
	 auto i = 0;
	 for (i; i < (unsigned long long)ARMORSLOT::NUM_SLOTS; i++) {
		 _equipped_armor[i] = nullptr;
	 }
	 for (i; i < (unsigned long long)WEAPONTYPE::NUM_SLOTS; i++) {
		 _equipped_weapon[i] = nullptr;
	 }
 }

 PlayerCharacter::~PlayerCharacter() { 
	 delete _player_class;
	 _player_class = nullptr;
	 auto i = 0;
	 for (i; i < (unsigned long long)ARMORSLOT::NUM_SLOTS; i++) { 
		 if (_equipped_armor[i]) {
			 ItemManager::DeleteItem(_equipped_armor[i]);
			 /*delete _equipped_armor[i];
			 _equipped_armor[i] = nullptr;*/
		 }
	 }
	 for (i; i < (unsigned long long)WEAPONTYPE::NUM_SLOTS; i++) {
		 if (_equipped_weapon[i]) {
			 ItemManager::DeleteItem(_equipped_weapon[i]);
			 //delete _equipped_weapon[i];
			 //_equipped_weapon[i] = nullptr;

		 }
	 }
 }

 //Getters
 //[[nodiscard]] const std::string PlayerCharacter::getClassName()  const noexcept { return _player_class->getClassName(); }

 [[nodiscard]] const levelType PlayerCharacter::getLevel()         const noexcept { return _player_class->getLevel(); }
 [[nodiscard]] const expType PlayerCharacter:: getCurrentEXP()     const noexcept { return _player_class->getCurrentEXP(); }
 [[nodiscard]] const expType PlayerCharacter:: getEXPToNextLevel() const noexcept { return _player_class->getEXPToNextLevel(); }
 			  				 
 [[nodiscard]] const wellType PlayerCharacter:: getCurrentHP()     const noexcept { return _player_class->HP->getCur(); }
 [[nodiscard]] const wellType PlayerCharacter:: getMaxHP()         const noexcept { return _player_class->HP->getMax(); }
 [[nodiscard]] const wellType PlayerCharacter:: getCurrentEnergy() const noexcept { return _player_class->Energy->getCur() - 1; } //zaczynamy z pust¹ pul¹
 [[nodiscard]] const wellType PlayerCharacter:: getMaxEnergy()     const noexcept { return _player_class->Energy->getMax(); }
 [[nodiscard]] const wellType PlayerCharacter:: getCurrentStamina()const noexcept { return _player_class->Stamina->getCur(); }
 [[nodiscard]] const wellType PlayerCharacter:: getMaxStamina()    const noexcept { return _player_class->Stamina->getMax(); }
 			  				  
 [[nodiscard]] const statType PlayerCharacter:: getBaseAttack()    const noexcept { return _player_class->getBaseAttack(); }
 [[nodiscard]] const statType PlayerCharacter:: getBaseDefence()   const noexcept { return _player_class->getBaseDefence(); }
 [[nodiscard]] const statType PlayerCharacter:: getBaseAttunment() const noexcept { return _player_class->getBaseAttunement(); }
 [[nodiscard]] const statType PlayerCharacter:: getBaseWarding()   const noexcept { return _player_class->getBaseWarding(); }
 [[nodiscard]] const statType PlayerCharacter:: getBaseSpeed()     const noexcept { return _player_class->getBaseSpeed(); }

 [[nodiscard]] const statType PlayerCharacter::getTotalAttack()const noexcept {
	 statType atkFromItems = 0;
	 //z pancerza
	 for (auto i = 0; i < (unsigned long long)ARMORSLOT::NUM_SLOTS; i++) {
		 if (_equipped_armor[i]) {
			 Armor* armor = dynamic_cast<Armor*>(_equipped_armor[i]->GetData());
			 atkFromItems += armor->Stats.Attack;
		 }
	 }
	 //z broni
	 for (auto j = 0; j < (unsigned long long)WEAPONTYPE::NUM_SLOTS; j++) {
		 if (_equipped_weapon[j]) {
			 Weapon* weapon = dynamic_cast<Weapon*>(_equipped_weapon[j]->GetData());
			 atkFromItems += weapon->Stats.Attack;
		 }
	 }

	 return _player_class->getTotalAttack() + atkFromItems;
 }
 [[nodiscard]] const statType PlayerCharacter::getTotalDefence()const noexcept {
	 statType defFromItems = 0;
	 //z pancerza
	 for (auto i = 0; i < (unsigned long long)ARMORSLOT::NUM_SLOTS; i++) {
		 if (_equipped_armor[i]) {
			 Armor* armor = dynamic_cast<Armor*>(_equipped_armor[i]->GetData());
			 defFromItems += armor->Stats.Defence;
		 }
	 }

	 //z broni
	 for (auto j = 0; j < (unsigned long long)WEAPONTYPE::NUM_SLOTS; j++) {
		 if (_equipped_weapon[j]) {
			 Weapon* weapon = dynamic_cast<Weapon*>(_equipped_weapon[j]->GetData());
			 defFromItems += weapon->Stats.Defence;
		 }
	 }
	 return _player_class->getTotalDefence() + defFromItems;
 }
 [[nodiscard]] const statType PlayerCharacter::getTotalAttunment()const noexcept {
	 statType atnFromItems = 0;
	 //z pancerza
	 for (auto i = 0; i < (unsigned long long)ARMORSLOT::NUM_SLOTS; i++) {
		 if (_equipped_armor[i]) {
			 Armor* armor = dynamic_cast<Armor*>(_equipped_armor[i]->GetData());
			 atnFromItems += armor->Stats.Attunment;
		 }
	 }
	 //z broni
	 for (auto j = 0; j < (unsigned long long)WEAPONTYPE::NUM_SLOTS; j++) {
		 if (_equipped_weapon[j]) {
			 Weapon* weapon = dynamic_cast<Weapon*>(_equipped_weapon[j]->GetData());
			 atnFromItems += weapon->Stats.Attunment;
		 }
	 }
	 return _player_class->getTotalAttunement() + atnFromItems;
 }
 [[nodiscard]] const statType PlayerCharacter::getTotalWarding()const noexcept {
	 statType wrdFromItems = 0;
	 //z pancerza
	 for (auto i = 0; i < (unsigned long long)ARMORSLOT::NUM_SLOTS; i++) {
		 if (_equipped_armor[i]) {
			 Armor* armor = dynamic_cast<Armor*>(_equipped_armor[i]->GetData());
			 wrdFromItems += armor->Stats.Warding;
		 }
	 }
	 //z broni
	 for (auto j = 0; j < (unsigned long long)WEAPONTYPE::NUM_SLOTS; j++) {
		 if (_equipped_weapon[j]) {
			 Weapon* weapon = dynamic_cast<Weapon*>(_equipped_weapon[j]->GetData());
			 wrdFromItems += weapon->Stats.Warding;
		 }
	 }
	 return _player_class->getTotalWarding() + wrdFromItems;
 }
 [[nodiscard]] const statType PlayerCharacter::getTotalSpeed()const noexcept {
	 statType spdFromItems = 0;
	 //z pancerza
	 for (auto i = 0; i < (unsigned long long)ARMORSLOT::NUM_SLOTS; i++) {
		 if (_equipped_armor[i]) {
			 Armor* armor = dynamic_cast<Armor*>(_equipped_armor[i]->GetData());
			 spdFromItems += armor->Stats.Speed;
		 }
	 }
	 //z broni
	 for (auto j = 0; j < (unsigned long long)WEAPONTYPE::NUM_SLOTS; j++) {
		 if (_equipped_weapon[j]) {
			 Weapon* weapon = dynamic_cast<Weapon*>(_equipped_weapon[j]->GetData());
			 spdFromItems += weapon->Stats.Speed;
		 }
	 }
	 return _player_class->getTotalSpeed() + spdFromItems;
 }


 [[nodiscard]] const std::vector<Effect> PlayerCharacter::getEffectList()const noexcept { return _player_class->Effects; }
 [[nodiscard]] const std::vector<Buff> PlayerCharacter::getBuffList()const noexcept { return _player_class->Buffs; }
 [[nodiscard]] const std::vector<Debuff> PlayerCharacter::getDebuffList()const noexcept { return _player_class->Debuffs; }

 [[nodiscard]] const std::vector<Item*> PlayerCharacter::getInventoryList()const noexcept{ return Inventory; }
 [[nodiscard]] const std::vector<Ability> PlayerCharacter::getAbilityList()const noexcept{ return _player_class->Abilities; }

 [[nodiscard]] const Armor* PlayerCharacter::get_equipped_armorAt(unsigned long long i) const noexcept {
	 if (!_equipped_armor[i]) return nullptr;
	 return (dynamic_cast<Armor*>(_equipped_armor[i]->GetData()));
 }


 [[nodiscard]] const Weapon* PlayerCharacter::get_equipped_weaponAt(unsigned long long i) const noexcept {
	 if (!_equipped_weapon[i]) return nullptr;
	 return (dynamic_cast<Weapon*>(_equipped_weapon[i]->GetData()));
 }


 //Modifiers
 void PlayerCharacter::gainEXP(expType amt)noexcept { _player_class->gainEXP(amt); }
 void PlayerCharacter::takeDamage(wellType amt)noexcept { _player_class->HP->reduceCurrent(amt); }
 void PlayerCharacter::heal(wellType amt) noexcept { _player_class->HP->increaseCurrent(amt); }
 void PlayerCharacter::restoreStamina(wellType amt)noexcept { _player_class->Stamina->increaseCurrent(amt); }
 void PlayerCharacter::restoreEnergy(wellType amt) noexcept { _player_class->Energy->increaseCurrent(amt); }
 
 void PlayerCharacter::ApplyEffect(Effect _efc)noexcept {
	 _player_class->Effects.push_back(_efc);
 }
 void PlayerCharacter::ApplyBuff(Buff _buff)noexcept { 
	 _player_class->Buffs.push_back(_buff);
 }
 void PlayerCharacter::ApplyDebuff(Debuff _debuff)noexcept {
	 _player_class->Debuffs.push_back(_debuff);
 }
 

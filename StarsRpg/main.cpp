#include <iostream>
#include "playerCharacter.h"
#include "item_manager.h"
using namespace std;

#define ITEMSTATS \
if (tmp->Stats.Attack > 0) {\
cout << "\n -Attack: " << tmp->Stats.Attack;}\
if (tmp->Stats.Defence > 0) {\
cout << "\n -Defence: " << tmp->Stats.Defence;}\
if (tmp->Stats.Attunment > 0) {\
	cout << "\n -Attunment: " << tmp->Stats.Attunment;}\
if (tmp->Stats.Speed > 0) {\
	cout << "\n -Speed: " << tmp->Stats.Speed;}\
if (tmp->Stats.Warding > 0) {\
	cout << "\n -Warding: " << tmp->Stats.Warding;}\
cout<<endl;




void PrintCharacter(PlayerCharacter & p1) {



	for (int i = 0; i < 4; i++) {
		cout << "===========================================================\nCHARACTER STATS|" << "\n///////////////\n";
		cout << p1.getClassName()
			<< " Level: " << p1.getLevel() << "(EXP:" << p1.getCurrentEXP() << "/" << p1.getEXPToNextLevel() << ")\n"
			<< "-HP: " << p1.getCurrentHP() << "/" << p1.getMaxHP()
			<< " Energy: " << p1.getCurrentEnergy() << "/" << p1.getMaxEnergy()
			<< " Stamina: " << p1.getCurrentStamina() << "/" << p1.getMaxStamina() << '\n'
			<< "-Attack: " << p1.getBaseAttack() << "->" << p1.getTotalAttack() << '\n'
			<< "-Defence: " << p1.getBaseDefence() << "->" << p1.getTotalDefence() << '\n'
			<< "-Attunment: " << p1.getBaseAttunment() << "->" << p1.getTotalAttunment() << '\n'
			<< "-Warding: " << p1.getBaseWarding() << "->" << p1.getTotalWarding() << '\n'
			<< "-Speed: " << p1.getBaseSpeed() << "->" << p1.getTotalSpeed() << '\n'
			<< "===========================================================\n";
		auto AllAbilities = p1.getAbilityList();

		cout << "\n-Abillity list:\n";
		for (auto& abl : AllAbilities) {
			cout << " " << abl.Name << '\n';
		}
		cout << "\n-Weapon:\n";
		for (unsigned long long i = 0; i < (int)WEAPONTYPE::NUM_SLOTS; i++) {
			const Weapon* tmp = dynamic_cast<Weapon*>(p1.getEquippedWeaponAt(i));
			if (tmp) {
				cout << tmp->Name<<"("<<tmp->MinDamage<<"-"<<tmp->MaxDamage<<")";
				ITEMSTATS
			}
		}

		cout << "\n-Armor:\n";
		for (unsigned long long i = 0; i < (int)ARMORSLOT::NUM_SLOTS; i++) {
			const Armor* tmp = dynamic_cast<Armor*>(p1.getEquippedArmorAt(i));

			if (tmp) {
				
				cout << tmp->Name;
				ITEMSTATS

			}
		}
		/*auto AllEffects = p1.get*/
		cout << "\n-Buffs:\n";
		




		cout << "\n-Debuffs:\n";

		cout << '\n';
		p1.gainEXP(100u);


	}
}



int main() {
	//PlayerCharacter p1(new Oracle());
	//PlayerCharacter p2(new Interlacer());
	//PlayerCharacter p3(new Unveiler());
	PlayerCharacter p4(new Justiciar()); 

	//KLATA
	{
		CoreStats plate_stats;
		plate_stats.Defence = 5;
		plate_stats.Warding = 10;
		
		Item* Mail = ItemManager::CreateArmor("Legion's Creed (chest)", plate_stats, ARMORSLOT::CHEST); 
		if (p4.equip(Mail)) {
			cout << "Equip success!\n";
		}
		else {
			cout << "Equip fail\n";
		}
	}
	//RÊKAWICE
	{
		CoreStats gauntlets_stats; 
		gauntlets_stats.Attack = 6; 
		gauntlets_stats.Speed = 1; 


		Item* Gauntlets = ItemManager::CreateArmor("Seraph's Wings (arms)", gauntlets_stats, ARMORSLOT::ARMS);
		if (p4.equip(Gauntlets)) {
			cout << "Equip success!\n";
		}
		else {
			cout << "Equip fail\n";
		}
	}
	//HE£M
	{
		CoreStats helmet_stats;
		helmet_stats.Defence = 7;
		helmet_stats.Warding = 4;
		helmet_stats.Attunment = 2;
		Item* Helm = ItemManager::CreateArmor("Knight's Pledge (hemlet)", helmet_stats, ARMORSLOT::HEAD);
		if (p4.equip(Helm)) { 
			cout << "Equip success!\n";
		}
		else {
			cout << "Equip fail\n";
		}
	}
	//BROÑ
	{
		CoreStats sword_stats;
		sword_stats.Attack = 12;
		sword_stats.Attunment = 3;
		Item* Sword = ItemManager::CreateWeapon("FlameCleaver", sword_stats, WEAPONTYPE::MELEE, 3, 9);
		if (p4.equip(Sword)){
			cout << "Equip success!\n";
		}
		else {
			cout << "Equip fail\n";
		}
	}



	



	

	//BUFF
	CoreStats over;
	over.Attack = 10;
	over.Warding = 4;

	Buff shield("Overshield", over, 3, false);
	p4.ApplyBuff(shield);
	 
	//PrintCharacter(p1); 
	//PrintCharacter(p2); 
	//PrintCharacter(p3);
	PrintCharacter(p4);
	
	cout << "\nHP before taking damage: " << p4.getCurrentHP() << "/" << p4.getMaxHP() << endl;
	p4.takeDamage(4);
	cout << "HP after damage: " << p4.getCurrentHP() << "/" << p4.getMaxHP() << endl;
	Item* healPotion = ItemManager::CreateConsumable("SmallPotion", 5u, 3u);
	p4.use(healPotion);
	cout << "HP after using potion: " << p4.getCurrentHP() << "/" << p4.getMaxHP() << endl;

	
	
	return 0;
}
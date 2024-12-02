//#include <iostream>
//#include "playerCharacter.h"
//#include "item_manager.h"
//using namespace std;
//
//#define ITEMSTATS \
//if (tmp->Stats.Attack > 0) {\
//cout << "\n -Attack: " << tmp->Stats.Attack;}\
//if (tmp->Stats.Defence > 0) {\
//cout << "\n -Defence: " << tmp->Stats.Defence;}\
//if (tmp->Stats.Attunment > 0) {\
//	cout << "\n -Attunment: " << tmp->Stats.Attunment;}\
//if (tmp->Stats.Speed > 0) {\
//	cout << "\n -Speed: " << tmp->Stats.Speed;}\
//if (tmp->Stats.Warding > 0) {\
//	cout << "\n -Warding: " << tmp->Stats.Warding;}\
//cout<<endl;
//
//
//
//
//void PrintCharacter(PlayerCharacter & p1) {
//
//
//
//	for (int i = 0; i < 4; i++) {
//		cout << "===========================================================\nCHARACTER STATS|" << "\n///////////////\n";
//		cout << p1.getClassName()
//			<< " Level: " << p1.getLevel() << "(EXP:" << p1.getCurrentEXP() << "/" << p1.getEXPToNextLevel() << ")\n"
//			<< "-HP: " << p1.getCurrentHP() << "/" << p1.getMaxHP()
//			<< " Energy: " << p1.getCurrentEnergy() << "/" << p1.getMaxEnergy()
//			<< " Stamina: " << p1.getCurrentStamina() << "/" << p1.getMaxStamina() << '\n'
//			<< "-Attack: " << p1.getBaseAttack() << "->" << p1.getTotalAttack() << '\n'
//			<< "-Defence: " << p1.getBaseDefence() << "->" << p1.getTotalDefence() << '\n'
//			<< "-Attunment: " << p1.getBaseAttunment() << "->" << p1.getTotalAttunment() << '\n'
//			<< "-Warding: " << p1.getBaseWarding() << "->" << p1.getTotalWarding() << '\n'
//			<< "-Speed: " << p1.getBaseSpeed() << "->" << p1.getTotalSpeed() << '\n'
//			<< "===========================================================\n";
//		auto AllAbilities = p1.getAbilityList();
//
//		cout << "\n-Abillity list:\n";
//		for (auto& abl : AllAbilities) {
//			cout << " " << abl.Name << '\n';
//		}
//		cout << "\n-Weapon:\n";
//		for (unsigned long long i = 0; i < (int)WEAPONTYPE::NUM_SLOTS; i++) {
//			const Weapon* tmp = dynamic_cast<Weapon*>(p1.get_equipped_weaponAt(i));
//			if (tmp) {
//				cout << tmp->Name<<"("<<tmp->MinDamage<<"-"<<tmp->MaxDamage<<")";
//				ITEMSTATS
//			}
//		}
//
//		cout << "\n-Armor:\n";
//		for (unsigned long long i = 0; i < (int)ARMORSLOT::NUM_SLOTS; i++) {
//			const Armor* tmp = dynamic_cast<Armor*>(p1.get_equipped_armorAt(i));
//
//			if (tmp) {
//				
//				cout << tmp->Name;
//				ITEMSTATS
//
//			}
//		}
//		/*auto AllEffects = p1.get*/
//		cout << "\n-Buffs:\n";
//		
//
//		cout << "\n-Debuffs:";
//
//		cout << '\n';
//		p1.gainEXP(100u);
//
//
//	}
//}
//
//
//
//int main() {
//	//PlayerCharacter p1(new Oracle());
//	//PlayerCharacter p2(new Interlacer());
//	//PlayerCharacter p3(new Unveiler());
//	PlayerCharacter p4(new Justiciar());
//
//
//	Item* Mail = ItemManager::CreateArmor("Legion's Creed (chest)", CoreStats(0, 0, 0, 5, 10), ARMORSLOT::CHEST);
//	Item* Gauntlets = ItemManager::CreateArmor("Seraph's Wings (chest)", CoreStats(6, 0, 1, 0, 0), ARMORSLOT::CHEST);
//	Item* Helm = ItemManager::CreateArmor("Knight's Pledge (hemlet)", CoreStats(0, 2, 0, 7, 4), ARMORSLOT::HEAD);
//
//	Item* Sword = ItemManager::CreateWeapon("FlameCleaver", CoreStats(), WEAPONTYPE::MELEE, 3, 9);
//
//	ItemManager::Equip(Mail, &p4);
//	ItemManager::Equip(Gauntlets, &p4);
//	ItemManager::Equip(Sword, &p4);
//
//
//	//BUFF
//	Buff shield("Overshield", CoreStats(10, 0, 0, 0, 4), 3);
//	p4.ApplyBuff(shield);
//
//	//PrintCharacter(p1); 
//	//PrintCharacter(p2); 
//	//PrintCharacter(p3);
//	PrintCharacter(p4);
//
///*
//	cout << "\nHP before taking damage: " << p4.getCurrentHP() << "/" << p4.getMaxHP() << endl;
//	p4.takeDamage(10);
//	cout << "HP after damage: " << p4.getCurrentHP() << "/" << p4.getMaxHP() << endl;
//	Item* healPotion = ItemManager::CreateConsumable("SmallPotion", 6u, 3u);
//	ItemManager::MoveToInventory(healPotion, &p4);
//
//	ItemManager::Use(healPotion, &p4);
//	cout << "HP after using potion: " << p4.getCurrentHP() << "/" << p4.getMaxHP() << endl;
//
//
//
//	ItemManager::MoveToInventory(
//		ItemManager::CreateWeapon("Comet's Trail", CoreStats(), WEAPONTYPE::MELEE, 5, 12),
//		&p4);
//	{
//		auto inv = p4.getInventoryList();
//		cout << "Inventory: \n  ";
//		for (auto it : inv) {
//			cout << " -" << *it << "  ";
//		}
//	}
//
//	ItemManager::Use(healPotion, &p4);
//	ItemManager::Use(healPotion, &p4);
//	cout << endl;
//	{
//		auto inv = p4.getInventoryList(); 
//		cout << "Inventory(after using other potions): \n  ";
//		for (auto it : inv) {
//			cout << " -" << *it << "  ";
//		}
//	}*/
//	cout << "HP after other potions: " << p4.getCurrentHP() << "/" << p4.getMaxHP() << endl;
//	
//	return 0;
//

int main() {
	return 0;
}
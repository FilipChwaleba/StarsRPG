#include "pch.h"
#include "CppUnitTest.h"
#include "StarsRpg/playerCharacter.h"
#include "StarsRpg/types.h"
#include "StarsRpg/item_manager.h"
#include "StarsRpg/playableclasses_fwd.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace RPGSystemsUnitTest
	
{
	TEST_CLASS(RPGSystemsUnitTest)
	{
	public:

		TEST_METHOD(Core_Abillities) {
			{
				Ability abil_default;
				Assert::AreEqual(std::string("unnamed"), abil_default.Name);
				Assert::AreEqual(1u, abil_default.HpEffect);
				Assert::IsNull(abil_default.GivenEffect);
				Assert::AreEqual(0u, abil_default.Cost);
				Assert::AreEqual(1u, abil_default.Cooldown);
				Assert::AreEqual((int)ABILITYTARGET::SELF, (int)abil_default.Target);
				Assert::AreEqual((int)ABILLITYSCALAR::NONE, (int)abil_default.Scalar);
			}
			{
				Ability constructed_abil(std::string("custom"), 2u, 3u,
					new Buff(std::string("Shining Moon"), 2, 0, 1, 0, 0, 2), ABILITYTARGET::ENEMY,
					5u, ABILLITYSCALAR::ATN);
				Assert::AreEqual(std::string("custom"), constructed_abil.Name);
				Assert::AreEqual(5u, constructed_abil.HpEffect); 
				Assert::IsNotNull(constructed_abil.GivenBuff);
				Assert::AreEqual(2u, constructed_abil.Cost);
				Assert::AreEqual(3u, constructed_abil.Cooldown);
				Assert::AreEqual((int)ABILITYTARGET::ENEMY, (int)constructed_abil.Target);
				Assert::AreEqual((int)ABILLITYSCALAR::ATN, (int)constructed_abil.Scalar); 
			}
		}
		TEST_METHOD(JusticiarTest)
		{
			PlayerCharacter p1(new Justiciar());
			Assert::AreEqual((int)Justiciar::BASEHP, (int)p1.getMaxHP()); //czy na lv1 maxHP jest równe baseHP

			p1.gainEXP(100u);

			Assert::AreEqual(2, (int)p1.getLevel()); //czy metoda gainEXP daje expa, i level siê zwiêksza
			Assert::AreEqual(string("Frozen Bulwark"), p1.getAbilityList().front().Name);//czy pierwsza zdolnoœæ dla justiciara to defalutowo "Frozen Bulwark"
			Assert::AreEqual((int)(Justiciar::BASEHP + Justiciar::BASEHP / 2.f), (int)p1.getMaxHP());//czy HP poprawnie wzrasta razem z wzrostem levelu

		}

		TEST_METHOD(InterlacerTest) { 
			PlayerCharacter p1(new Interlacer());
			Assert::AreEqual((int)Interlacer::BASEHP, (int)p1.getMaxHP());
			Assert::AreEqual((int)Interlacer::BASEENR, (int)p1.getMaxEnergy());
			p1.gainEXP(100);
			Assert::AreEqual(2, (int)p1.getLevel());
			Assert::AreEqual(string("Surge of Neptune"), p1.getAbilityList().front().Name);
			Assert::AreEqual((int)(Interlacer::BASEHP + Interlacer::BASEHP / 2.f), (int)p1.getMaxHP());
		}

		TEST_METHOD(OracleTest) {
			PlayerCharacter p1(new Oracle());
			Assert::AreEqual((int)Oracle::BASEHP, (int)p1.getMaxHP());
			Assert::AreEqual((int)Oracle::BASESTM, (int)p1.getMaxStamina()); 
			p1.gainEXP(100);
			Assert::AreEqual(2, (int)p1.getLevel());
			Assert::AreEqual(string("Mending Flames"), p1.getAbilityList().front().Name); 
			Assert::AreEqual((int)(Oracle::BASESTM + 1 + Oracle::BASESTM / 2.f), (int)p1.getMaxStamina());
		}

		TEST_METHOD(UnveilerTest) {
			PlayerCharacter p1(new Unveiler());
			Assert::AreEqual((int)Unveiler::BASEHP, (int)p1.getMaxHP());
			Assert::AreEqual((int)Unveiler::BASESTM, (int)p1.getMaxStamina());
			p1.gainEXP(100);
			Assert::AreEqual(2, (int)p1.getLevel());
			Assert::AreEqual(string("Prowl of the Storm"), p1.getAbilityList().front().Name);
		}

		TEST_METHOD(Effects_Buffs_and_Debuffs) {
			//EFFECTS
			{
				Effect a_effect("unnamed");
				Assert::AreEqual(std::string("unnamed"), a_effect.Name);//sprawdzenie pustego efektu do pustych zmian statów
				Assert::AreEqual(0, (int)a_effect.AffectedStats.Attack);
				Assert::AreEqual(0, (int)a_effect.AffectedStats.Attunment);
				Assert::AreEqual(0, (int)a_effect.AffectedStats.Speed);
				Assert::AreEqual(0, (int)a_effect.AffectedStats.Defence);
				Assert::AreEqual(0, (int)a_effect.AffectedStats.Warding);
				Assert::AreEqual(2, (int)a_effect.Duration);
				Assert::IsFalse(a_effect.isDebuff);
			}
			{
				Effect b_effect("somename", CoreStats(1, 2, 3, 4, 5), 3, true);//sprawdzenie uzupe³nionego efektu, jako pseduo-debuff, z u¿yciem konstruktora dla CoreStats()
				Assert::AreEqual(1, (int)b_effect.AffectedStats.Attack);
				Assert::AreEqual(2, (int)b_effect.AffectedStats.Attunment);
				Assert::AreEqual(3, (int)b_effect.AffectedStats.Speed);
				Assert::AreEqual(4, (int)b_effect.AffectedStats.Defence);
				Assert::AreEqual(5, (int)b_effect.AffectedStats.Warding);
				Assert::AreEqual(3, (int)b_effect.Duration);
				Assert::IsTrue(b_effect.isDebuff);
			}
			{
				Effect c_effect("somename", 1, 2, 3, 4, 5, 3, false);//sprawdzenie uzupe³nionego efektu, jako pseudo-buff, bez u¿ycia konstruktora dla CoreStats
				Assert::AreEqual(1, (int)c_effect.AffectedStats.Attack);
				Assert::AreEqual(2, (int)c_effect.AffectedStats.Attunment);
				Assert::AreEqual(3, (int)c_effect.AffectedStats.Speed);
				Assert::AreEqual(4, (int)c_effect.AffectedStats.Defence);
				Assert::AreEqual(5, (int)c_effect.AffectedStats.Warding);
				Assert::AreEqual(3, (int)c_effect.Duration);
				Assert::IsFalse(c_effect.isDebuff);
			}
			//BUFFS
			{
				Buff a_buff("unnamed");
				Assert::AreEqual(std::string("unnamed"), a_buff.Name);//pusty buff
				Assert::AreEqual(0, (int)a_buff.BuffedStats.Attack);
				Assert::AreEqual(0, (int)a_buff.BuffedStats.Attunment);
				Assert::AreEqual(0, (int)a_buff.BuffedStats.Speed);
				Assert::AreEqual(0, (int)a_buff.BuffedStats.Defence);
				Assert::AreEqual(0, (int)a_buff.BuffedStats.Warding);
				Assert::AreEqual(2, (int)a_buff.Duration);
				Assert::IsFalse(a_buff.isDebuff);
			}
			{
				Buff a_buff("somename", CoreStats(1, 2, 3, 4, 5), 3);//konstruktor CoreStats()
				Assert::AreEqual(1, (int)a_buff.BuffedStats.Attack);
				Assert::AreEqual(2, (int)a_buff.BuffedStats.Attunment);
				Assert::AreEqual(3, (int)a_buff.BuffedStats.Speed);
				Assert::AreEqual(4, (int)a_buff.BuffedStats.Defence);
				Assert::AreEqual(5, (int)a_buff.BuffedStats.Warding);
				Assert::AreEqual(3, (int)a_buff.Duration);
				Assert::IsFalse(a_buff.isDebuff);
			}
			{
				Buff b_buff("somename", 1, 2, 3, 4, 5, 3);//bez konstruktora
				Assert::AreEqual(1, (int)b_buff.BuffedStats.Attack);
				Assert::AreEqual(2, (int)b_buff.BuffedStats.Attunment);
				Assert::AreEqual(3, (int)b_buff.BuffedStats.Speed);
				Assert::AreEqual(4, (int)b_buff.BuffedStats.Defence);
				Assert::AreEqual(5, (int)b_buff.BuffedStats.Warding);
				Assert::AreEqual(3, (int)b_buff.Duration);
				Assert::IsFalse(b_buff.isDebuff);
			}
			//DEBUFFS
			{
				Debuff a_debuff("unnamed");
				Assert::AreEqual(std::string("unnamed"), a_debuff.Name);//pusty debuff
				Assert::AreEqual(0, (int)a_debuff.DebuffedStats.Attack);
				Assert::AreEqual(0, (int)a_debuff.DebuffedStats.Attunment);
				Assert::AreEqual(0, (int)a_debuff.DebuffedStats.Speed);
				Assert::AreEqual(0, (int)a_debuff.DebuffedStats.Defence);
				Assert::AreEqual(0, (int)a_debuff.DebuffedStats.Warding);
				Assert::AreEqual(2, (int)a_debuff.Duration);
				Assert::IsTrue(a_debuff.isDebuff);
			}
			{
				Debuff b_debuff("somename", CoreStats(1, 2, 3, 4, 5), 3);//konstruktor CoreStats()
				Assert::AreEqual(1, (int)b_debuff.DebuffedStats.Attack);
				Assert::AreEqual(2, (int)b_debuff.DebuffedStats.Attunment);
				Assert::AreEqual(3, (int)b_debuff.DebuffedStats.Speed);
				Assert::AreEqual(4, (int)b_debuff.DebuffedStats.Defence);
				Assert::AreEqual(5, (int)b_debuff.DebuffedStats.Warding);
				Assert::AreEqual(3, (int)b_debuff.Duration);
				Assert::IsTrue(b_debuff.isDebuff);
			}
			{
				Debuff c_debuff("somename", 1, 2, 3, 4, 5, 3);//bez konstruktora
				Assert::AreEqual(1, (int)c_debuff.DebuffedStats.Attack);
				Assert::AreEqual(2, (int)c_debuff.DebuffedStats.Attunment);
				Assert::AreEqual(3, (int)c_debuff.DebuffedStats.Speed);
				Assert::AreEqual(4, (int)c_debuff.DebuffedStats.Defence);
				Assert::AreEqual(5, (int)c_debuff.DebuffedStats.Warding);
				Assert::AreEqual(3, (int)c_debuff.Duration);
				Assert::IsTrue(c_debuff.isDebuff);
			}
		}
		TEST_METHOD(StatsTest) {
			CoreStats stats_default; //test na konstruktor defaultowy
			Assert::AreEqual(0, (int)stats_default.Attack);
			Assert::AreEqual(0, (int)stats_default.Attunment);
			Assert::AreEqual(0, (int)stats_default.Speed);
			Assert::AreEqual(0, (int)stats_default.Defence);
			Assert::AreEqual(0, (int)stats_default.Warding);
			CoreStats statsa(5); //test na konstruktor jednoargumentowy -> wszystkie staty na t¹ sam¹ liczbê
			Assert::AreEqual(5, (int)statsa.Attack);
			Assert::AreEqual(5, (int)statsa.Attunment);
			Assert::AreEqual(5, (int)statsa.Speed);
			Assert::AreEqual(5, (int)statsa.Defence);
			Assert::AreEqual(5, (int)statsa.Warding);
			CoreStats statsb(1, 2, 3, 4, 5); //test na konstruktor wieloargumentowy -> ka¿dy stat wprowadzony rêczne 
			Assert::AreEqual(1, (int)statsb.Attack);
			Assert::AreEqual(2, (int)statsb.Attunment);
			Assert::AreEqual(3, (int)statsb.Speed);
			Assert::AreEqual(4, (int)statsb.Defence);
			Assert::AreEqual(5, (int)statsb.Warding);
			stats_default += statsa;// operator dodawania
			Assert::AreEqual(5, (int)stats_default.Attack);
			Assert::AreEqual(5, (int)stats_default.Attunment);
			Assert::AreEqual(5, (int)stats_default.Speed);
			Assert::AreEqual(5, (int)stats_default.Defence);
			Assert::AreEqual(5, (int)stats_default.Warding);
			stats_default -= statsa;// operator odejmowania
			Assert::AreEqual(0, (int)stats_default.Attack);
			Assert::AreEqual(0, (int)stats_default.Attunment);
			Assert::AreEqual(0, (int)stats_default.Speed);
			Assert::AreEqual(0, (int)stats_default.Defence);
			Assert::AreEqual(0, (int)stats_default.Warding);
			stats_default = statsb;// operator przyrównania
			Assert::AreEqual(1, (int)statsb.Attack);
			Assert::AreEqual(2, (int)statsb.Attunment);
			Assert::AreEqual(3, (int)statsb.Speed);
			Assert::AreEqual(4, (int)statsb.Defence);
			Assert::AreEqual(5, (int)statsb.Warding);
		}

		TEST_METHOD(WeaponItem) {
			
			{		
				Item* a_magic_weapon = ItemManager::CreateWeapon("Mystic Implement", 5, WEAPONTYPE::MELEE, 2, 4);
				Assert::IsNotNull(a_magic_weapon);
				Assert::IsTrue(ItemManager::IsItemWeapon(a_magic_weapon));
				Assert::IsFalse(ItemManager::IsItemArmor(a_magic_weapon));
				Assert::IsFalse(ItemManager::IsItemConsumable(a_magic_weapon));

				Weapon* weapon = nullptr;
				ItemManager::CastItemToWeapon(a_magic_weapon, weapon);
				Assert::IsNotNull(weapon);
				Assert::AreEqual(std::string("Mystic Implement"), weapon->Name);
				Assert::AreEqual(5, (int)weapon->Stats.Attack);
				Assert::AreEqual(5, (int)weapon->Stats.Attunment);
				Assert::AreEqual(5, (int)weapon->Stats.Speed);
				Assert::AreEqual(5, (int)weapon->Stats.Defence);
				Assert::AreEqual(5, (int)weapon->Stats.Warding);
				Assert::AreEqual((int)WEAPONTYPE::MELEE, (int)weapon->Slot);
				Assert::AreEqual(2, (int)weapon->MinDamage);
				Assert::AreEqual(4, (int)weapon->MaxDamage);
				Assert::IsFalse(weapon->is2H);
				/*ItemManager::DeleteItem(a_magic_weapon);
				Assert::IsNull(a_magic_weapon);*/ //na koniec

				//MOOOOTS
				weapon->Name = "Stellar Implement";
				weapon->Stats.Attack += 1;
				weapon->Stats.Attunment += 1;
				weapon->Stats.Speed += 1;
				weapon->Stats.Defence += 1;
				weapon->Stats.Warding += 1;
				weapon->MinDamage += 1;
				weapon->MaxDamage += 1;
				//sprawdzenie czy dzia³a
				Assert::AreEqual(std::string("Stellar Implement"), weapon->Name);
				Assert::AreEqual(6, (int)weapon->Stats.Attack);
				Assert::AreEqual(6, (int)weapon->Stats.Attunment);
				Assert::AreEqual(6, (int)weapon->Stats.Speed);
				Assert::AreEqual(6, (int)weapon->Stats.Defence);
				Assert::AreEqual(6, (int)weapon->Stats.Warding);
				Assert::AreEqual((int)WEAPONTYPE::MELEE, (int)weapon->Slot);
				Assert::AreEqual(3, (int)weapon->MinDamage);
				Assert::AreEqual(5, (int)weapon->MaxDamage);
				Assert::IsFalse(weapon->is2H);

				ItemManager::DeleteItem(a_magic_weapon); 
				Assert::IsNull(a_magic_weapon); 
			}
			/*
			{ //modyfikowanie broni
				Item* a_magic_weapon = ItemManager::CreateWeapon("Mystic Implement", 5, WEAPONTYPE::MELEE, 2, 4);
				Assert::IsNotNull(a_magic_weapon);
				Assert::IsTrue(ItemManager::IsItemWeapon(a_magic_weapon));
				Assert::IsFalse(ItemManager::IsItemArmor(a_magic_weapon));
				Assert::IsFalse(ItemManager::IsItemConsumable(a_magic_weapon));

				Weapon* weapon_mod = nullptr;  
				ItemManager::CastItemToWeapon(a_magic_weapon, weapon_mod); 
				Assert::IsNull(weapon_mod); 
				Assert::AreEqual(std::string("Mystic Implement"), weapon_mod->Name); 
				Assert::AreEqual(5, (int)weapon_mod->Stats.Attack); 
				Assert::AreEqual(5, (int)weapon_mod->Stats.Attunment); 
				Assert::AreEqual(5, (int)weapon_mod->Stats.Speed); 
				Assert::AreEqual(5, (int)weapon_mod->Stats.Defence); 
				Assert::AreEqual(5, (int)weapon_mod->Stats.Warding); 
				Assert::AreEqual((int)WEAPONTYPE::MELEE, (int)weapon_mod->Slot); 
				Assert::AreEqual(2, (int)weapon_mod->MinDamage); 
				Assert::AreEqual(4, (int)weapon_mod->MaxDamage); 
				Assert::IsFalse(weapon_mod->is2H); 

				//MOOOOTS
				weapon_mod->Name = "Stellar Implement"; 
				weapon_mod->Stats.Attack += 1; 
				weapon_mod->Stats.Attunment += 1; 
				weapon_mod->Stats.Speed += 1;
				weapon_mod->Stats.Defence += 1;
				weapon_mod->Stats.Warding += 1;
				weapon_mod->MinDamage += 1;
				weapon_mod->MaxDamage += 1;
				//sprawdzenie czy dzia³a
				Assert::AreEqual(std::string("Stellar Implement"), weapon_mod->Name);
				Assert::AreEqual(6, (int)weapon_mod->Stats.Attack);
				Assert::AreEqual(6, (int)weapon_mod->Stats.Attunment);
				Assert::AreEqual(6, (int)weapon_mod->Stats.Speed);
				Assert::AreEqual(6, (int)weapon_mod->Stats.Defence);
				Assert::AreEqual(6, (int)weapon_mod->Stats.Warding);
				Assert::AreEqual((int)WEAPONTYPE::MELEE, (int)weapon_mod->Slot);
				Assert::AreEqual(3, (int)weapon_mod->MinDamage);
				Assert::AreEqual(5, (int)weapon_mod->MaxDamage);
				Assert::IsFalse(weapon_mod->is2H);
			}
			*/
			
			{		//const castowanie
				/*const Weapon* weapon = dynamic_cast<const Weapon*>(a_magic_weapon->GetData()); 
				Assert::IsNotNull(weapon);  
				Assert::AreEqual(std::string("Mystic Implement"), weapon->Name);   
				Assert::AreEqual(5, (int)weapon->Stats.Attack);  
				Assert::AreEqual(5, (int)weapon->Stats.Attunment);  
				Assert::AreEqual(5, (int)weapon->Stats.Speed);  
				Assert::AreEqual(5, (int)weapon->Stats.Defence);  
				Assert::AreEqual(5, (int)weapon->Stats.Warding);  
				Assert::AreEqual((int)WEAPONTYPE::MELEE, (int)weapon->Slot);  
				Assert::AreEqual(2, (int)weapon->MinDamage); 
				Assert::AreEqual(4, (int)weapon->MaxDamage);  
				Assert::IsFalse(weapon->is2H); */
			}

			

			
		}
		TEST_METHOD(ArmorItem) {
			Item* armor_item = ItemManager::CreateArmor("Steel Shouldercaps", CoreStats(1, 2, 3, 4, 5), ARMORSLOT::ARMS);
			Assert::IsNotNull(armor_item);
			Assert::IsFalse(ItemManager::IsItemWeapon(armor_item));
			Assert::IsTrue(ItemManager::IsItemArmor(armor_item));
			Assert::IsFalse(ItemManager::IsItemConsumable(armor_item));

			Armor* armor = nullptr;
			ItemManager::CastItemToArmor(armor_item, armor);
			Assert::AreEqual(std::string("Steel Shouldercaps"), armor->Name);
			Assert::AreEqual(1, (int)armor->Stats.Attack); 
			Assert::AreEqual(2, (int)armor->Stats.Attunment);
			Assert::AreEqual(3, (int)armor->Stats.Speed) ;
			Assert::AreEqual(4, (int)armor->Stats.Defence);
			Assert::AreEqual(5, (int)armor->Stats.Warding);
			Assert::AreEqual((int)ARMORSLOT::ARMS, (int)armor->Slot);
			ItemManager::DeleteItem(armor_item);
			Assert::IsNull(armor_item); 
		}
		TEST_METHOD(ConsumableItem) {
			Item* random_potion = ItemManager::CreateConsumable("Suspitious Brew", 3, 4);
			Assert::IsNotNull(random_potion);
			Assert::IsFalse(ItemManager::IsItemWeapon(random_potion)); 
			Assert::IsFalse(ItemManager::IsItemArmor(random_potion));
			Assert::IsTrue(ItemManager::IsItemConsumable(random_potion));
			Consumable* potion = nullptr;
			ItemManager::CastItemToConsumable(random_potion, potion);
			Assert::AreEqual(std::string("Suspitious Brew"), potion->Name);
			Assert::AreEqual(3, (int)potion->well);
			Assert::AreEqual(4, (int)potion->Quantity);
			ItemManager::DeleteItem(random_potion);
			Assert::IsNull(random_potion);
			
		}

		TEST_METHOD(Equip_Player) {
			PlayerCharacter unv(new Unveiler());

			Assert::IsTrue(ItemManager::Equip(ItemManager::CreateWeapon("Knife", CoreStats(), WEAPONTYPE::MELEE, 2, 5), &unv));
			Assert::IsTrue(ItemManager::Equip(ItemManager::CreateWeapon("Sword", CoreStats(), WEAPONTYPE::RANGED, 1, 5), &unv));
			Assert::IsTrue(ItemManager::Equip(ItemManager::CreateArmor("Helm", CoreStats(0,0,0,1,1),ARMORSLOT::HEAD), &unv));
			Assert::IsTrue(ItemManager::Equip(ItemManager::CreateArmor("Gloves", CoreStats(0,0,0,1,1),ARMORSLOT::ARMS), &unv));
			Assert::IsTrue(ItemManager::Equip(ItemManager::CreateArmor("Chest", CoreStats(0,0,0,1,1),ARMORSLOT::CHEST), &unv));
			Assert::IsTrue(ItemManager::Equip(ItemManager::CreateArmor("Legs", CoreStats(0,0,0,1,1),ARMORSLOT::BOOTS), &unv));
			Assert::IsTrue(ItemManager::Equip(ItemManager::CreateArmor("Cloak", CoreStats(2),ARMORSLOT::RELIC), &unv));


			Assert::IsNotNull(unv.get_equipped_weaponAt((unsigned long long)WEAPONTYPE::MELEE)); 
			Assert::IsNotNull(unv.get_equipped_weaponAt((unsigned long long)WEAPONTYPE::RANGED));
			Assert::IsNotNull(unv.get_equipped_armorAt((unsigned long long)ARMORSLOT::HEAD)); 
			Assert::IsNotNull(unv.get_equipped_armorAt((unsigned long long)ARMORSLOT::ARMS));
			Assert::IsNotNull(unv.get_equipped_armorAt((unsigned long long)ARMORSLOT::CHEST));
			Assert::IsNotNull(unv.get_equipped_armorAt((unsigned long long)ARMORSLOT::BOOTS)); 
			Assert::IsNotNull(unv.get_equipped_armorAt((unsigned long long)ARMORSLOT::RELIC));

			Assert::IsFalse(ItemManager::Equip(ItemManager::CreateConsumable("water", 0, 1, new Buff("Hydration", CoreStats(1, 2, 3, 4, 5), 3)), &unv));

			auto backpack = unv.getInventoryList();
			Assert::AreEqual(0, (int)backpack.size()); //pusty plecak, nic w ekwipunku
			//Assert::IsTrue(ItemManager::Equip(ItemManager::CreateArmor("Bond", CoreStats(3), ARMORSLOT::RELIC), &unv)); 
			//Assert::AreEqual(1, (int)backpack.size()); //dodany class item wy¿ej, ale slot jest pe³ny wiêc leci do plecaka

		}


		TEST_METHOD(EquipTest) { 
			PlayerCharacter unv(new Unveiler());
			Assert::IsTrue(ItemManager::Equip(//próbujemy z'equipowaæ broñ -> ma sie udaæ, obecnie postaæ nie ma ¿adnego Equipment'u na³o¿onego
				ItemManager::CreateWeapon("Prowl of Thunder", CoreStats(), WEAPONTYPE::MELEE, 4, 16)
				, &unv));

			Assert::IsNotNull(unv.get_equipped_weaponAt((unsigned long long)WEAPONTYPE::MELEE)); //sprawdzamy czy slot jest pe³ny po wy'Equipowaniu broni wy¿ej


			Assert::IsFalse(ItemManager::Equip( //próbujemy z'equipowaæ Consumable itemek jako broñ lub pancerz -> oczywiœcie niemo¿liwe
				ItemManager::CreateConsumable("Raindrops of the Spark", 0, 1, new Buff("Gift of the Storm", CoreStats(0, 0, 5, 0, 0), 3)) 
				, &unv));
		}


	};
}

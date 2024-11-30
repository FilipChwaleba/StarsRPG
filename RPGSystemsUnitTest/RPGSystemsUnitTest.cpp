#include "pch.h"
#include "CppUnitTest.h"
#include "StarsRpg/playerCharacter.h"
#include "StarsRpg/types.h"
#include "StarsRpg/item_manager.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace RPGSystemsUnitTest
	
{
	TEST_CLASS(RPGSystemsUnitTest)
	{
	public:
		
		TEST_METHOD(JusticiarTest)
		{
			PlayerCharacter p1(new Justiciar());
			Assert::AreEqual((int)Justiciar::BASEHP, (int)p1.getMaxHP()); //czy na lv1 maxHP jest równe baseHP

			p1.gainEXP(100u);

			Assert::AreEqual(2, (int)p1.getLevel()); //czy metoda gainEXP daje expa, i level siê zwiêksza
			Assert::AreEqual(string("Frozen Bulwark"), p1.getAbilityList().front().Name);//czy pierwsza zdolnoœæ dla justiciara to defalutowo "Frozen Bulwark"
			Assert::AreEqual((int)(Justiciar::BASEHP + Justiciar::BASEHP / 2.f), (int)p1.getMaxHP());//czy HP poprawnie wzrasta razem z wzrostem levelu

		}
		TEST_METHOD(Effects_Buffs_and_Debuffs) {
			//EFFECTS
			{
				Effect a_effect;
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
				Effect b_effect("somename", CoreStats(1, 2, 3, 4, 5), 3, true);//sprawdzenie uzupe³nionego efektu, jako pseduo-buff, z u¿yciem konstruktora dla CoreStats()
				Assert::AreEqual(1, (int)b_effect.AffectedStats.Attack);
				Assert::AreEqual(2, (int)b_effect.AffectedStats.Attunment);
				Assert::AreEqual(3, (int)b_effect.AffectedStats.Speed);
				Assert::AreEqual(4, (int)b_effect.AffectedStats.Defence);
				Assert::AreEqual(5, (int)b_effect.AffectedStats.Warding);
				Assert::AreEqual(3, (int)b_effect.Duration);
				Assert::IsTrue(b_effect.isDebuff);
			}
			{
				Effect c_effect("somename", 1, 2, 3, 4, 5, 3, false);//sprawdzenie uzupe³nionego efektu, jako pseudo-debuff, bez u¿ycia konstruktora dla CoreStats
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
				Buff a_buff;
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
				Debuff a_debuff;
				Assert::AreEqual(std::string("unnamed"), a_debuff.Name);//pusty buff
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
			Assert::AreEqual(5, (int)weapon->Stats.Speed  );
			Assert::AreEqual(5, (int)weapon->Stats.Defence);
			Assert::AreEqual(5, (int)weapon->Stats.Warding);
			Assert::AreEqual((int)WEAPONTYPE::MELEE, (int)weapon->Slot);
			Assert::AreEqual(2, (int)weapon->MinDamage); 
			Assert::AreEqual(4, (int)weapon->MaxDamage);
			Assert::IsFalse(weapon->is2H);
			ItemManager::DeleteItem(a_magic_weapon);		
			Assert::IsNull(a_magic_weapon);  
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



		TEST_METHOD(EquipTest) { 
			PlayerCharacter unv(new Unveiler());
			Assert::IsTrue(ItemManager::Equip(//próbujemy z'equipowaæ broñ -> ma sie udaæ, obecnie postaæ nie ma ¿adnego Equipment'u na³o¿onego
				ItemManager::CreateWeapon("Prowl of Thunder", CoreStats(), WEAPONTYPE::MELEE, 4, 16)
				, &unv));

			Assert::IsNotNull(unv.getEquippedWeaponAt((unsigned long long)WEAPONTYPE::MELEE)); //sprawdzamy czy slot jest pe³ny po wy'Equipowaniu broni wy¿ej


			Assert::IsFalse(ItemManager::Equip( //próbujemy z'equipowaæ Consumable itemek jako broñ lub pancerz -> oczywiœcie niemo¿liwe
				ItemManager::CreateConsumable("Raindrops of the Spark", 0, 1, new Buff("Gift of the Storm", CoreStats(0, 0, 5, 0, 0), 3))
				, &unv));
		}


	};
}

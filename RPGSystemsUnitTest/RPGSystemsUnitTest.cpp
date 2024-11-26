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
				Assert::AreEqual(std::string("unnamed"), a_effect.Name);
				Assert::AreEqual(0, (int)a_effect.AffectedStats.Attack);
				Assert::AreEqual(0, (int)a_effect.AffectedStats.Attunment);
				Assert::AreEqual(0, (int)a_effect.AffectedStats.Speed);
				Assert::AreEqual(0, (int)a_effect.AffectedStats.Defence);
				Assert::AreEqual(0, (int)a_effect.AffectedStats.Warding);
				Assert::AreEqual(2, (int)a_effect.Duration);
				Assert::IsFalse(a_effect.isDebuff);
			}
			{
				Effect b_effect("somename", CoreStats(1, 2, 3, 4, 5), 3, true);
				Assert::AreEqual(1, (int)b_effect.AffectedStats.Attack);
				Assert::AreEqual(2, (int)b_effect.AffectedStats.Attunment);
				Assert::AreEqual(3, (int)b_effect.AffectedStats.Speed);
				Assert::AreEqual(4, (int)b_effect.AffectedStats.Defence);
				Assert::AreEqual(5, (int)b_effect.AffectedStats.Warding);
				Assert::AreEqual(3, (int)b_effect.Duration);
				Assert::IsTrue(b_effect.isDebuff);
			}
			{
				Effect c_effect("somename", 1, 2, 3, 4, 5, 3, false);
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
				Assert::AreEqual(std::string("unnamed"), a_buff.Name);
				Assert::AreEqual(0, (int)a_buff.BuffedStats.Attack);
				Assert::AreEqual(0, (int)a_buff.BuffedStats.Attunment);
				Assert::AreEqual(0, (int)a_buff.BuffedStats.Speed);
				Assert::AreEqual(0, (int)a_buff.BuffedStats.Defence);
				Assert::AreEqual(0, (int)a_buff.BuffedStats.Warding);
				Assert::AreEqual(2, (int)a_buff.Duration);
				Assert::IsFalse(a_buff.isDebuff);
			}
			{
				Buff a_buff("somename", CoreStats(1, 2, 3, 4, 5), 3);
				Assert::AreEqual(1, (int)a_buff.BuffedStats.Attack);
				Assert::AreEqual(2, (int)a_buff.BuffedStats.Attunment);
				Assert::AreEqual(3, (int)a_buff.BuffedStats.Speed);
				Assert::AreEqual(4, (int)a_buff.BuffedStats.Defence);
				Assert::AreEqual(5, (int)a_buff.BuffedStats.Warding);
				Assert::AreEqual(3, (int)a_buff.Duration);
				Assert::IsFalse(a_buff.isDebuff);
			}
			{
				Buff b_buff("somename", 1, 2, 3, 4, 5, 3);
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
				Assert::AreEqual(std::string("unnamed"), a_debuff.Name);
				Assert::AreEqual(0, (int)a_debuff.DebuffedStats.Attack);
				Assert::AreEqual(0, (int)a_debuff.DebuffedStats.Attunment);
				Assert::AreEqual(0, (int)a_debuff.DebuffedStats.Speed);
				Assert::AreEqual(0, (int)a_debuff.DebuffedStats.Defence);
				Assert::AreEqual(0, (int)a_debuff.DebuffedStats.Warding);
				Assert::AreEqual(2, (int)a_debuff.Duration);
				Assert::IsTrue(a_debuff.isDebuff);
			}
			{
				Debuff b_debuff("somename", CoreStats(1, 2, 3, 4, 5), 3);
				Assert::AreEqual(1, (int)b_debuff.DebuffedStats.Attack);
				Assert::AreEqual(2, (int)b_debuff.DebuffedStats.Attunment);
				Assert::AreEqual(3, (int)b_debuff.DebuffedStats.Speed);
				Assert::AreEqual(4, (int)b_debuff.DebuffedStats.Defence);
				Assert::AreEqual(5, (int)b_debuff.DebuffedStats.Warding);
				Assert::AreEqual(3, (int)b_debuff.Duration);
				Assert::IsTrue(b_debuff.isDebuff);
			}
			{
				Debuff c_debuff("somename", 1, 2, 3, 4, 5, 3);
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
			CoreStats stats_default;
			Assert::AreEqual(0, (int)stats_default.Attack);
			Assert::AreEqual(0, (int)stats_default.Attunment);
			Assert::AreEqual(0, (int)stats_default.Speed);
			Assert::AreEqual(0, (int)stats_default.Defence);
			Assert::AreEqual(0, (int)stats_default.Warding);
			CoreStats statsa(5);
			Assert::AreEqual(5, (int)statsa.Attack);
			Assert::AreEqual(5, (int)statsa.Attunment);
			Assert::AreEqual(5, (int)statsa.Speed);
			Assert::AreEqual(5, (int)statsa.Defence);
			Assert::AreEqual(5, (int)statsa.Warding);
			CoreStats statsb(1, 2, 3, 4, 5);
			Assert::AreEqual(1, (int)statsb.Attack);
			Assert::AreEqual(2, (int)statsb.Attunment);
			Assert::AreEqual(3, (int)statsb.Speed);
			Assert::AreEqual(4, (int)statsb.Defence);
			Assert::AreEqual(5, (int)statsb.Warding);
			stats_default += statsa;
			Assert::AreEqual(5, (int)stats_default.Attack);
			Assert::AreEqual(5, (int)stats_default.Attunment);
			Assert::AreEqual(5, (int)stats_default.Speed);
			Assert::AreEqual(5, (int)stats_default.Defence);
			Assert::AreEqual(5, (int)stats_default.Warding);
			stats_default -= statsa;
			Assert::AreEqual(0, (int)stats_default.Attack);
			Assert::AreEqual(0, (int)stats_default.Attunment);
			Assert::AreEqual(0, (int)stats_default.Speed);
			Assert::AreEqual(0, (int)stats_default.Defence);
			Assert::AreEqual(0, (int)stats_default.Warding);
			stats_default = statsb;
			Assert::AreEqual(1, (int)statsb.Attack);
			Assert::AreEqual(2, (int)statsb.Attunment);
			Assert::AreEqual(3, (int)statsb.Speed);
			Assert::AreEqual(4, (int)statsb.Defence);
			Assert::AreEqual(5, (int)statsb.Warding);
		}

		TEST_METHOD(EquipTest) { 
			PlayerCharacter unv(new Unveiler());
			ItemManager::Equip(
				ItemManager::CreateWeapon("Prowl of Thunder", CoreStats(), WEAPONTYPE::MELEE, 4, 16)
				, &unv);

			Assert::IsNotNull(unv.getEquippedWeaponAt((unsigned long long)WEAPONTYPE::MELEE));
		}


	};
}

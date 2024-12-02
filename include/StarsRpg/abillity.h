#pragma once
#include "effect.h"
#include "buff.h"
#include "debuff.h"
#include <string>
#include <cstdint>

//struct AbillityEffect {
//}; will be used later

enum class ABILITYTARGET { NONE, SELF, ENEMY, ALLY, ENEMY_BLAST, ENEMY_AOE, ALLY_BLAST, ALLY_AOE };
enum class ABILLITYSCALAR { NONE, ATK, ATN, SPD, DEF, WRD, HP, ENR, STM}; 

struct Ability {
	Ability(std::string name, uint32_t cost, uint32_t cooldown, 
		ABILITYTARGET t = ABILITYTARGET::SELF, uint32_t hpe = 1u, ABILLITYSCALAR s = ABILLITYSCALAR::NONE);

	Ability(std::string name, uint32_t cost, uint32_t cooldown, 
		Effect* efc = nullptr, ABILITYTARGET t = ABILITYTARGET::SELF, uint32_t hpe = 1u, ABILLITYSCALAR s = ABILLITYSCALAR::NONE);

	Ability(std::string name, uint32_t cost, uint32_t cooldown,
		Buff* b = nullptr, ABILITYTARGET t = ABILITYTARGET::SELF, uint32_t hpe = 1u, ABILLITYSCALAR s = ABILLITYSCALAR::NONE);

	Ability(std::string name, uint32_t cost, uint32_t cooldown, 
		Debuff* d = nullptr, ABILITYTARGET t = ABILITYTARGET::SELF, uint32_t hpe = 1u, ABILLITYSCALAR s = ABILLITYSCALAR::NONE);

	Ability();

~Ability();


	std::string Name;
	uint32_t  Cost; // assume Stamina/Energy is used
	uint32_t  Cooldown ; //number of rounds
	Effect* GivenEffect ;
	Buff* GivenBuff ;
	Debuff* GivenDebuff ;
	ABILITYTARGET Target ;
	uint32_t HpEffect;
	ABILLITYSCALAR Scalar ; 
};
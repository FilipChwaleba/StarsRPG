#pragma once
#include <string>
#include <cstdint>
//struct AbillityEffect {
//}; will be used later

enum class ABILITYTARGET { NONE, SELF, ENEMY, ALLY, ENEMY_BLAST, ENEMY_AOE, ALLY_BLAST, ALLY_AOE };
enum class ABILLITYSCALAR { NONE, ATK, ATN, SPD, DEF, WRD, HP, ENR, STM}; 

struct Ability {
Ability(std::string name, uint32_t cost, uint32_t cooldown,ABILITYTARGET t, uint32_t hpe, ABILLITYSCALAR s) 
	: Name(name), Cost(cost), Cooldown(cooldown), Target(t), HpEffect(hpe), Scalar(s) {}

	std::string Name = "unnamed";
	uint32_t  Cost = 0u; // assume Stamina/Energy is used
	uint32_t  Cooldown = 1u; //number of rounds
	ABILITYTARGET Target = ABILITYTARGET::SELF;  
	uint32_t HpEffect = 1u;
	ABILLITYSCALAR Scalar = ABILLITYSCALAR::NONE;
};
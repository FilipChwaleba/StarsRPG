#pragma once
#include "types.h"
#include "corestats.h"
#include <string>

struct Debuff  {

	Debuff();

	Debuff(std::string name = "unnamed", statType attack = 0, statType attunment = 0,
		statType speed = 0, statType defence = 0, statType warding = 0, EffectType duration = 2u,
		bool isdebuff = true
	);

	Debuff(std::string name, CoreStats cs, EffectType duration = 1u, bool isdebuff = true);
	
	std::string Name;
	EffectType Duration;
	CoreStats DebuffedStats;
	bool isDebuff = true;

	Debuff& operator=(std::string name);
};

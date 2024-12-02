#pragma once
#include"types.h"
#include "corestats.h"
#include <string>

struct Buff  { 
	Buff();

	Buff(std::string name = "unnamed", statType attack = 0, statType attunment = 0,
		statType speed = 0, statType defence = 0, statType warding = 0, EffectType duration = 2u);
		

	Buff(std::string name, CoreStats cs, EffectType duration = 2u);
	
	std::string Name;
	EffectType Duration;
	CoreStats BuffedStats;
	bool isDebuff = false;

	Buff& operator=(std::string name);
};



#pragma once
#include "types.h"
#include "corestats.h"
#include <string> 
struct Effect {

	Effect();

	Effect(std::string name = "unnamed", statType attack =0, statType attunment =0,
		statType speed =0, statType defence =0, statType warding =0, EffectType duration =2u,
		bool isdebuff = false);

	Effect(std::string name, CoreStats cs, EffectType duration = 2u , bool isdebuff = false );

	std::string Name;
	EffectType Duration;
	CoreStats AffectedStats;
	bool isDebuff;

	Effect& operator=(std::string name);
};
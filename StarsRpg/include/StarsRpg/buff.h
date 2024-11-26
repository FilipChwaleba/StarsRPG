#pragma once
#include"types.h"
#include "corestats.h"
#include <string>



struct Effect {

Effect(std::string name = "unnamed", statType attack = 0, statType attunment = 0,
	statType speed = 0, statType defence = 0, statType warding = 0, EffectType duration = 2u,
	bool isdebuff = false)
	:Name(name), Duration(duration), isDebuff(isdebuff) 
	{
	AffectedStats.Attack = attack; 
	AffectedStats.Attunment = attunment;
	AffectedStats.Speed = speed; 
	AffectedStats.Defence = defence; 
	AffectedStats.Warding = warding;
	} 

Effect(std::string name, CoreStats cs, EffectType duration = 1u, bool isdebuff = false)
	:Name(name), Duration(duration), isDebuff(isdebuff) 
	{
	AffectedStats = cs;
	}

	
	std::string Name; 
	EffectType Duration;

	CoreStats AffectedStats;
	bool isDebuff;


};

struct Buff : public Effect { 
	Buff(std::string name = "unnamed", statType attack = 0, statType attunment = 0,
		statType speed = 0, statType defence = 0, statType warding = 0, EffectType duration = 2u
		) 
		:Name(name), Duration(duration), isDebuff(false) 
	{
		BuffedStats.Attack = attack;
		BuffedStats.Attunment = attunment;
		BuffedStats.Speed = speed;
		BuffedStats.Defence = defence;
		BuffedStats.Warding = warding;
	}

	Buff(std::string name, CoreStats cs, EffectType duration = 1u)
	: Name(name), Duration(duration), isDebuff(false)
	{
		BuffedStats = cs;
	}
	std::string Name;
	EffectType Duration;

	CoreStats BuffedStats;

	bool isDebuff = false;
};

struct Debuff : public Effect { 

	Debuff(std::string name = "unnamed", statType attack = 0, statType attunment = 0,
		statType speed = 0, statType defence = 0, statType warding = 0, EffectType duration = 2u
		) 
		:Name(name), Duration(duration), isDebuff(true)  
	{
		DebuffedStats.Attack = attack; 
		DebuffedStats.Attunment = attunment;
		DebuffedStats.Speed = speed;
		DebuffedStats.Defence = defence;
		DebuffedStats.Warding = warding;
	}

	Debuff(std::string name, CoreStats cs, EffectType duration = 1u)
	: Name(name), Duration(duration), isDebuff(true)
	{
		DebuffedStats = cs;
	}
	std::string Name; 
	EffectType Duration;

	CoreStats DebuffedStats;

	bool isDebuff = true;
};

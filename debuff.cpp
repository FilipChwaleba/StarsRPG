#include "debuff.h"

Debuff::Debuff() {
	Name = "unnamed";
	Duration = 2u;
	DebuffedStats = CoreStats();
	isDebuff = true;
}

Debuff::Debuff(std::string name, statType attack, statType attunment, statType speed,
	statType defence, statType warding, EffectType duration, bool isdebuff)
	:Name(name), DebuffedStats(attack, attunment, speed, defence, warding),
	Duration(duration), isDebuff(isdebuff){}

Debuff::Debuff(std::string name, CoreStats cs, EffectType duration, bool isdebuff)
	:Name(name), DebuffedStats(cs), Duration(duration), isDebuff(isdebuff){}

Debuff& Debuff::operator=(std::string name) {
	this->Name = name;
	this->Duration = 2u;
	this->DebuffedStats = CoreStats();
	this->isDebuff = true;
	return *this;
}
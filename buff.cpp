#include "buff.h"

Buff::Buff() {
	Name = "unnamed";
	Duration = 2u;
	BuffedStats = CoreStats();
	isDebuff = false;
}

Buff::Buff(std::string name, statType attack, statType attunment,
	statType speed, statType defence, statType warding, EffectType duration)
	: Name(name), BuffedStats(attack, attunment, speed, defence, warding),
	Duration(duration){}

Buff::Buff(std::string name, CoreStats cs, EffectType duration)
	:Name(name), BuffedStats(cs),Duration(duration){}

Buff& Buff::operator=(std::string name) {
	this->Name = name;
	this->Duration = 2u;
	this->BuffedStats = CoreStats();
	this->isDebuff = false;
	return *this;
}
	
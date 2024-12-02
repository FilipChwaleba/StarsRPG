#include "effect.h"

Effect::Effect() {
	Name = "unnamed";
	Duration = 2u;
	AffectedStats = CoreStats();
	isDebuff = false;
}

Effect::Effect(std::string name , statType attack , statType attunment ,
statType speed , statType defence , statType warding , EffectType duration ,
bool isdebuff ) :Name(name),AffectedStats(attack, attunment, speed, defence, warding),
Duration(duration), isDebuff(isdebuff)
{}

Effect::Effect(std::string name, CoreStats cs, EffectType duration , bool isdebuff )
	:Name(name), AffectedStats(cs), Duration(duration), isDebuff(isdebuff)
{}
	
Effect& Effect::operator=(std::string name) {
	this->Name = name;
	this->Duration = 2u;
	this->AffectedStats = CoreStats();
	this->isDebuff = false;
	return *this;
}


#include "corestats.h"

CoreStats::CoreStats() {
	Attack = 0;
	Attunment = 0;
	Speed = 0;
	Defence = 0;
	Warding = 0;
}

CoreStats::CoreStats(statType x)
	:Attack(x), Attunment(x), Speed(x), Defence(x), Warding(x) {}

CoreStats::CoreStats(statType atk, statType atn, statType spd, statType def, statType wrd)
	: Attack(atk), Attunment(atn), Speed(spd), Defence(def), Warding(wrd) {}

CoreStats& CoreStats::operator+=(const CoreStats& rhs) {
	this->Attack += rhs.Attack;
	this->Attunment += rhs.Attunment;
	this->Speed += rhs.Speed;
	this->Defence += rhs.Defence;
	this->Warding += rhs.Warding;
	return *this;
};

CoreStats& CoreStats:: operator-=(const CoreStats& rhs) {
	CoreStats tmp = *this;

	this->Attack -= rhs.Attack;
	this->Attunment -= rhs.Attunment;
	this->Speed -= rhs.Speed;
	this->Defence -= rhs.Defence;
	this->Warding -= rhs.Warding;

	if (this->Attack > tmp.Attack)this->Attack = 0u;
	if (this->Attunment > tmp.Attunment)this->Attunment = 0u;
	if (this->Speed > tmp.Speed)this->Speed = 0u;
	if (this->Defence > tmp.Defence)this->Defence = 0u;
	if (this->Warding > tmp.Warding)this->Warding = 0u;

	return *this;
};

CoreStats& CoreStats::operator=(const statType& rhs) {
	this->Attack = rhs;
	this->Attunment = rhs;
	this->Speed = rhs;
	this->Defence = rhs;
	this->Warding = rhs;
	return *this;
}


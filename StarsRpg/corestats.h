#pragma once
#include"types.h"
struct CoreStats {
	statType Attack = 0;
	statType Attunment = 0;
	statType Speed = 0;
	statType Defence = 0;
	statType Warding = 0;

	CoreStats& operator+=(const CoreStats& rhs) {
		this->Attack += rhs.Attack;
		this->Attunment += rhs.Attunment;
		this->Speed += rhs.Speed;
		this->Defence += rhs.Defence;
		this->Warding += rhs.Warding;
		return *this;
	};
	CoreStats& operator-=(const CoreStats& rhs) {
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

	CoreStats& operator=(const statType& rhs) {
		this->Attack = rhs;
		this->Attunment = rhs;
		this->Speed = rhs;
		this->Defence = rhs;
		this->Warding = rhs;
		return *this;
	}
};

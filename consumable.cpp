#include "consumable.h"

const Effect* Consumable::GetEffect()const { return _efc; }
void Consumable::SetEffect(Effect* new_efc) {
	if (_efc) {
		delete _efc;
		_efc = nullptr;
	}
	_efc = new_efc;
}

const Buff* Consumable::GetBuff()const { return _b; }
void Consumable::SetBuff(Buff* new_b) {
	if (_b) {
		delete _b;
		_b = nullptr;
	}
	_b = new_b;
}


const Debuff* Consumable::GetDebuff()const { return _d; }
void Consumable::SetDebuff(Debuff* new_d) {
	if (_d) {
		delete _d;
		_d = nullptr;
	}
	_d = new_d;
}

Consumable::Consumable(std::string name, wellType w , itemcount q , Effect* efc)
	:ItemDelegate(name), well(w), Quantity(q), _efc(efc) {}

Consumable::Consumable(std::string name, wellType w , itemcount q , Debuff* d )
	: ItemDelegate(name), well(w), Quantity(q), _d(d) {}

Consumable::Consumable(std::string name, wellType w , itemcount q, Buff* b )
	:ItemDelegate(name), well(w), Quantity(q), _b(b) {}

Consumable::~Consumable() {
	if (_efc) {
		delete _efc;
		_efc = nullptr;
	}
	if (_b) {
		delete _b;
		_b = nullptr;
	}
	if (_d) {
		delete _d;
		_d = nullptr;
	}
}
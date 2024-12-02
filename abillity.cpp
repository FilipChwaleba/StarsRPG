#include "abillity.h"

Ability::Ability(std::string name, uint32_t cost, uint32_t cooldown, ABILITYTARGET t, uint32_t hpe, ABILLITYSCALAR s)
	: Name(name), Cost(cost), Cooldown(cooldown), Target(t), HpEffect(hpe), Scalar(s),
		GivenBuff(nullptr),GivenDebuff(nullptr),GivenEffect(nullptr){}

Ability::Ability(std::string name, uint32_t cost, uint32_t cooldown, Effect* efc, ABILITYTARGET t, uint32_t hpe, ABILLITYSCALAR s)
	: Name(name), Cost(cost), Cooldown(cooldown), GivenEffect(efc), Target(t), HpEffect(hpe), Scalar(s)
		,GivenBuff(nullptr), GivenDebuff(nullptr){}

Ability::Ability(std::string name, uint32_t cost, uint32_t cooldown, Buff* b, ABILITYTARGET t, uint32_t hpe, ABILLITYSCALAR s)
	: Name(name), Cost(cost), Cooldown(cooldown), GivenBuff(b), Target(t), HpEffect(hpe), Scalar(s),
		GivenDebuff(nullptr), GivenEffect(nullptr){}

Ability::Ability(std::string name, uint32_t cost, uint32_t cooldown, Debuff* d, ABILITYTARGET t, uint32_t hpe, ABILLITYSCALAR s)
	: Name(name), Cost(cost), Cooldown(cooldown), GivenDebuff(d), Target(t), HpEffect(hpe), Scalar(s),
		GivenBuff(nullptr), GivenEffect(nullptr){}

Ability::Ability()
{
	Name = "unnamed";
	Cost = 0u;
	Cooldown = 1u;
	GivenBuff = nullptr;
	GivenEffect = nullptr;
	GivenDebuff = nullptr;
	Target = ABILITYTARGET::NONE;
	HpEffect = 1u;
	Scalar = ABILLITYSCALAR::NONE;
}



Ability::~Ability() {
	if (GivenEffect) {
		delete GivenEffect;
		GivenEffect = nullptr;
	}
	if (GivenBuff) {
		delete GivenBuff;
		GivenBuff = nullptr;
	}
	if (GivenDebuff) {
		delete GivenDebuff;
		GivenDebuff = nullptr;
	}
}
#pragma once
#include "types.h"
#include "effect.h"
#include "buff.h"
#include "debuff.h"
#include "item.h"

class Consumable final : public ItemDelegate {
public:
	
	wellType well;
	itemcount Quantity;
	const Effect* GetEffect()const;
	void SetEffect(Effect* new_efc);

	const Buff* GetBuff()const;
	void SetBuff(Buff* new_b);

	const Debuff* GetDebuff()const;
	void SetDebuff(Debuff* new_d);
	
	//GETTYPE
private:
	Effect* _efc;
	Buff* _b;
	Debuff* _d;
	Consumable(std::string name, wellType w = 1u, itemcount q = 1, Effect* efc = nullptr);
	Consumable(std::string name, wellType w = 1u, itemcount q = 1, Debuff* d = nullptr);
	Consumable(std::string name, wellType w = 1u, itemcount q = 1, Buff* b = nullptr);
	~Consumable();
	friend class ItemManager;
};
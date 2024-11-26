#pragma once
#include "types.h"
#include "buff.h"
#include <vector>



class StatBlock{
	CoreStats base;
	CoreStats fromBuffs;
public:
	
	//only accepts statType type variables -> explicit
	explicit StatBlock(statType atk = (statType)1, statType def = (statType)0, statType atn = (statType)1, statType wrd = (statType)0, statType spd = (statType)1){
		base.Attack = atk;
		base.Defence = def;
		base.Attunment = atn; 
		base.Warding = wrd; 
		base.Speed = spd;  
	}

	statType getBaseAttack() const { return     base.Attack; }
	statType getBaseDefence() const { return    base.Defence; }
	statType getBaseAttunement() const { return base.Attunment; }
	statType getBaseWarding() const { return    base.Warding; } 
	statType getBaseSpeed() const { return      base.Speed; } 

	statType getTotalAttack() const { return     base.Attack +    fromBuffs.Attack; }
	statType getTotalDefence() const { return    base.Defence +   fromBuffs.Defence; }
	statType getTotalAttunement() const { return base.Attunment + fromBuffs.Attunment; }
	statType getTotalWarding() const { return    base.Warding +   fromBuffs.Warding; }
	statType getTotalSpeed() const { return      base.Speed +     fromBuffs.Speed; }

	
	
protected:
	std::vector<Effect>Effects; 
	std::vector<Buff>Buffs;
	std::vector<Debuff>Debuffs;

	void AddNewEffect(Effect efc) { 
		for (auto& effect : Effects) {
			if (efc.Name == effect.Name) {
				effect.Duration = efc.Duration;
				return;
			}
		}
		Effects.push_back(efc);
		recalculate_effects();
	} 

	void AddNewBuff(Buff b) {  
		for (auto& buff : Buffs) { 
			if (b.Name == buff.Name) { 
				buff.Duration = b.Duration;  
				return;
			}
		}
		Buffs.push_back(b);  
		recalculate_buffs(); 
	} 

	void AddNewDebuff(Debuff d) {
		for (auto& debuff : Debuffs) {
			if (d.Name == debuff.Name) { 
				debuff.Duration = d.Duration;
				return;
			}
		}
		Debuffs.push_back(d);  
		recalculate_debuffs();  
	}

	//attack, attunment, speed, defence, warding
	void statBoost(statType atk = 0, statType atn = 0, statType spd = 0,
		statType def = 0, statType wrd = 0) {
		base.Attack += atk;
		base.Defence += def;
		base.Attunment += atn;
		base.Warding += wrd;
		base.Speed += spd; 
	}
	void statBoost(CoreStats cs) {
		base += cs;
	}
private:
	void recalculate_effects() { 
		CoreStats tmp_total;
		for (const auto& e : Effects) {
			if (e.isDebuff) {
				tmp_total -= e.AffectedStats;
			} else {
				tmp_total += e.AffectedStats;
			}
		}
		fromBuffs = tmp_total;
	}
	void recalculate_buffs() { 
		CoreStats tmp_total;
		for (const auto& b : Buffs) {
			tmp_total += b.BuffedStats;
		}
		fromBuffs = tmp_total;
	}
	void recalculate_debuffs() {
		CoreStats tmp_total;
		for (const auto& d : Debuffs) {
			tmp_total -= d.DebuffedStats;
		}
		fromBuffs = tmp_total;
	}


};
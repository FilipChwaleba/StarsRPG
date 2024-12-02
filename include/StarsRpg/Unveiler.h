#pragma once
#include "types.h"
#include "playerCharacter.h"

class Unveiler : public PlayerCharacterDelegate {
public:
	static const wellType BASEHP = (wellType)10u;
	static const statType BASEATK = (statType)14u;
	static const statType BASEATN = (statType)6u;
	static const statType BASESPD = (statType)12u;
	static const wellType BASEENR = (wellType)8u;
	static const wellType BASESTM = (wellType)10u;
	Unveiler();
private:
	void LevelUp()noexcept override;
};
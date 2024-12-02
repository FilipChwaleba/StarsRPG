#pragma once
#include "types.h"
#include "playerCharacter.h"


class Justiciar : public PlayerCharacterDelegate {
public:
	static const wellType BASEHP = (wellType)18u;
	static const statType BASEATK = (statType)10u;
	static const statType BASEATN = (statType)2u;
	static const statType BASESPD = (statType)3u;
	static const wellType BASEENR = (wellType)8u;
	static const wellType BASESTM = (wellType)12u;
	Justiciar();
private:
	void LevelUp()noexcept override;
};
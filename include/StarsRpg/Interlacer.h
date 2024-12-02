#pragma once
#include "types.h"
#include "playerCharacter.h"

class Interlacer : public PlayerCharacterDelegate {
public:
	static const wellType BASEHP = (wellType)9u;
	static const statType BASEATK = (statType)3u;
	static const statType BASEATN = (statType)18u;
	static const statType BASESPD = (statType)5u;
	static const wellType BASEENR = (wellType)14u;
	static const wellType BASESTM = (wellType)8u;
	Interlacer();
private:
	void LevelUp()noexcept override;
};
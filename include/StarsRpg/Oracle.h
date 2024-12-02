#pragma once
#include "types.h"
#include "playerCharacter.h"

class Oracle : public PlayerCharacterDelegate{
 public:
	static const wellType BASEHP = (wellType)15u;
	static const statType BASEATK = (statType)6u;
	static const statType BASEATN = (statType)9u;
	static const statType BASESPD = (statType)7u;
	static const wellType BASEENR = (wellType)8u;
	static const wellType BASESTM = (wellType)14u;
	Oracle();

private:
	void LevelUp()noexcept override;
};

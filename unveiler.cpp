#include "Unveiler.h"
#include "pc_macros.h"

Unveiler::Unveiler() :PlayerCharacterDelegate() {
	PCCONSTRUCT
		Abilities.emplace_back("Prowl of the Storm", 2u, 1u, ABILITYTARGET::ALLY, 3u, ABILLITYSCALAR::SPD);
}

void Unveiler::LevelUp() noexcept { 
	LEVELUP
		if (CurrentLevel == 2) {
			Abilities.emplace_back("Jaged Thunder", 4u, 1u, ABILITYTARGET::ENEMY, 5u, ABILLITYSCALAR::ATK);

			//statBoost(1, 0, 2, 0, 0);
		}
}
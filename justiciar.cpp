#include "Justiciar.h"
#include "pc_macros.h"

Justiciar::Justiciar() :PlayerCharacterDelegate() {

	PCCONSTRUCT

		Abilities.emplace_back("Frozen Bulwark", 3u, 1u, ABILITYTARGET::ALLY, 7u, ABILLITYSCALAR::DEF);
}

void Justiciar::LevelUp() noexcept {
	LEVELUP
		if (getLevel() == 2) {
			Abilities.emplace_back("Gnawing Glacier", 4u, 2u, ABILITYTARGET::ENEMY, 6u, ABILLITYSCALAR::ATK);
			statBoost(0, 0, 0, 2, 2);
		}
}
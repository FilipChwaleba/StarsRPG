#include "Oracle.h"
#include "pc_macros.h"

Oracle::Oracle() :PlayerCharacterDelegate() {

	PCCONSTRUCT

		Abilities.emplace_back("Mending Flames", 2u, 1u, ABILITYTARGET::ALLY, 2u, ABILLITYSCALAR::STM);
}

void Oracle::LevelUp() noexcept {
	LEVELUP
		if (getLevel() == 2) {
			Abilities.emplace_back("Blazing Chains", 3u, 2u, ABILITYTARGET::ENEMY, 5u, ABILLITYSCALAR::ATN);

			Stamina->setMax(1u + Stamina->getMax());
			Stamina->increaseCurrent(1u);
		}
}
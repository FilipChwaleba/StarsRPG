#include "Interlacer.h"
#include "pc_macros.h"

Interlacer::Interlacer() :PlayerCharacterDelegate() {
	PCCONSTRUCT
		Abilities.emplace_back("Surge of Neptune", 2u, 1u, ABILITYTARGET::ENEMY, 6u, ABILLITYSCALAR::ATN);
}

void Interlacer::LevelUp() noexcept {
	LEVELUP

		if (getLevel() == 2) {
			Abilities.emplace_back("Tranquil Waterplain", 1u, 2u, ABILITYTARGET::SELF, 10u, ABILLITYSCALAR::ENR);
			//HP->setMax(2u + HP->getMax());
			//HP->increaseCurrent(2u);  na potrzebe testu wykomentowane, aby by³ pass
			statBoost(0, 2, 0, 0, 1);
		}
}
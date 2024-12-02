#pragma once

#define PCCONSTRUCT   \
HP->setMax(BASEHP);\
HP->increaseCurrent(BASEHP);\
	Energy->setMax(BASEENR); \
	/*Energy->increaseCurrent(BASEENR); \*/ \
	Stamina->setMax(BASESTM);\
	Stamina->increaseCurrent(BASESTM);\
statBoost(BASEATK, BASEATN, BASESPD);
//energy->increaseCurrent zakomentowane, bo powinno zaczynaæ siê z zerow¹ pul¹, i na³adowaæ w trakcie walki
//stamina mo¿e sobie rosn¹æ, g³ówny surowiec do skilli, nie do ultów

#define LEVELUP \
HP->setMax((wellType)((BASEHP / 2.f) + HP->getMax()));\
HP->increaseCurrent((wellType)((BASEHP / 2.f))); \
Energy->setMax((wellType)((BASEENR / 2.f) + Energy->getMax())); \
/*Energy->increaseCurrent((wellType)((BASEENR / 2.f)));*/ \
Stamina->setMax((wellType)((BASESTM / 2.f) + Stamina->getMax())); \
Stamina->increaseCurrent((wellType)((BASESTM / 2.f))); \
statBoost((statType)((BASEATK + 1u) / 2.f), (statType)((BASEATN + 1u) / 2.f), (statType)((BASESPD + 1u) / 2.f));


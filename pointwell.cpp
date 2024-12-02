#include "pointwell.h"


[[nodiscard]] const wellType PointWell::getMax()const noexcept {
	return Max;
}

[[nodiscard]] const wellType PointWell::getCur()const noexcept {
	return Current;
}

[[nodiscard]] const bool PointWell::isFull()const noexcept {
	return (Current == Max);
}

void PointWell::setMax(wellType newMax)noexcept {
	if (newMax < 1)
		Max = 1;
	else
		Max = newMax;

	if (Current > Max)
		Current = Max;
}

void PointWell::reduceCurrent(wellType damage)noexcept {
	if (damage > Current) {
		Current = 0;
		return;
	}
	Current -= damage;
}

void PointWell::increaseCurrent(wellType ammount)noexcept {
	if (ammount + Current > Max) {
		Current = Max;
		return;
	}
	Current += ammount;
}

PointWell::PointWell() { Current = 1; Max = 1; }

PointWell::PointWell(wellType c, wellType m) {
	Current = c;
	Max = m;
	if (Current > Max) {
		Current = Max;
	}
}
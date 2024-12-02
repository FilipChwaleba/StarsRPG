#pragma once
#include"types.h"

class PointWell {
public:
	[[nodiscard]] const wellType getMax() const noexcept;
	[[nodiscard]] const wellType getCur() const noexcept;
	[[nodiscard]] const bool isFull()const noexcept;

	void setMax(wellType newMax)noexcept;
	void reduceCurrent(wellType damage)noexcept;
	void increaseCurrent(wellType ammount)noexcept;

	PointWell();
	PointWell(wellType c, wellType m);
	
private:
	wellType Current; 
	wellType Max;
	
};
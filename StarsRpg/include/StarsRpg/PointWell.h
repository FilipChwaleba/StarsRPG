#pragma once
#include"types.h"

class PointWell {
public:
	
	bool setMax(wellType newMax) {
		if (newMax < 1)
			return false;

		Max = newMax; 

		if (Current > Max)
			Current = Max;

		return true;
	}

	wellType getMax() { return Max; } 
	wellType getCur() { return Current; } 


	bool isFull() { return (Current == Max); }



	void reduceCurrent(wellType damage) { 
		if (damage > Current) {
			Current = 0;
			return;
		}
		Current -= damage;
	}		

	void increaseCurrent(wellType ammount) {
		if (ammount + Current > Max) {
			Current = Max;
			return;
		}
		Current += ammount;
	}


	PointWell() { Current = 1; Max = 1; }

	PointWell(wellType c, wellType m) {
		Current = c; 
		Max = m; 
		if (Current > Max) {
			Current = Max;
		}
	}
	
private:
	wellType Current; 
	wellType Max;
	
};
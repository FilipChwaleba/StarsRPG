#pragma once
#include"types.h"
struct CoreStats {
	statType Attack ;
	statType Attunment;
	statType Speed ;
	statType Defence ;
	statType Warding ;

	CoreStats();

	CoreStats(statType x);

	CoreStats(statType atk, statType atn, statType spd, statType def, statType wrd);

	CoreStats& operator+=(const CoreStats& rhs);
	CoreStats& operator-=(const CoreStats& rhs);
	CoreStats& operator=(const statType& rhs);
};

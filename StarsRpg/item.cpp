#include "item.h"
//don't change this, only the EquipmentDelegate constructor should be
//touching this 
static std::uint32_t EQUIPMENT_ID_ITERATOR = 0u;

EquipmentDeletage::EquipmentDeletage(std::string name, CoreStats cstats)
	: ItemDelegate(name), Stats(cstats), UniqueId(++EQUIPMENT_ID_ITERATOR){}

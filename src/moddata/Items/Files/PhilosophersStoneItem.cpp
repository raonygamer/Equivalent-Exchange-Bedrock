#include "PhilosophersStoneItem.h"
#include "minecraft/item/ItemStack.h"
#include "moddata/Managers/TickRuntime.h"

PhilosophersStoneItem::PhilosophersStoneItem(const std::string& name, short id) : Item(name, id), textureItem() {
	setMaxStackSize(1);
	setMaxDamage(1005);
	setCategory(CreativeItemCategory::ITEMS);
};

bool PhilosophersStoneItem::showsDurabilityInCreative() const {
	return true;
}

short PhilosophersStoneItem::getMaxDamage() const
{
	return 1005;
}
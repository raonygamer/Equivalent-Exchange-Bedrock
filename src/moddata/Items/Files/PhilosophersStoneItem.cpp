#include "PhilosophersStoneItem.h"
#include "minecraft/item/ItemStack.h"

PhilosophersStoneItem::PhilosophersStoneItem(const std::string& name, short id) : Item(name, id), textureItem() {
	setMaxStackSize(1);
	setMaxDamage(1005);
	setCategory(CreativeItemCategory::ITEMS);
};

const TextureUVCoordinateSet& PhilosophersStoneItem::getIcon(const ItemStackBase& itemStack, int frame, bool isInventoryPane) const {
	return getIconTextureUVSet(textureItem, 0, 0);
}

Item& PhilosophersStoneItem::setIcon(const std::string& name, int id) {
	Item::setIcon(name, id);
	textureItem = getTextureItem(name);
	return *this;
}

bool PhilosophersStoneItem::showsDurabilityInCreative() const {
	return true;
}

bool PhilosophersStoneItem::isDestructive(int) const {
	return true;
}

int PhilosophersStoneItem::getDamageChance(int) const {
	return -1;
}

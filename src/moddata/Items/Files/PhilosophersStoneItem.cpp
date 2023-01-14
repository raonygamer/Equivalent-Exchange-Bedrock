#include "PhilosophersStoneItem.h"

PhilosophersStoneItem::PhilosophersStoneItem(const std::string& name, short id) : Item(name, id), textureItem() {};

const TextureUVCoordinateSet& PhilosophersStoneItem::getIcon(const ItemStackBase& itemStack, int frame, bool isInventoryPane) const {
	return getIconTextureUVSet(textureItem, 0, 0);
}

Item& PhilosophersStoneItem::setIcon(const std::string& name, int id) {
	Item::setIcon(name, id);
	textureItem = getTextureItem(name);
	return *this;
}
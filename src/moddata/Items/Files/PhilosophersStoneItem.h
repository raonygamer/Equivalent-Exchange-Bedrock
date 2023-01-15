#pragma once
#include "minecraft/item/Item.h"
#include "minecraft/client/TextureAtlasItem.h"

class PhilosophersStoneItem : public Item {
private:
	TextureAtlasItem textureItem;
public:
	PhilosophersStoneItem(const std::string&, short);
	virtual const TextureUVCoordinateSet& getIcon(const ItemStackBase&, int, bool) const;
	virtual Item& setIcon(const std::string&, int);
	virtual bool showsDurabilityInCreative() const;
	virtual bool isDestructive(int) const;
	virtual int getDamageChance(int) const;
};
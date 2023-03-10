#pragma once
#include "minecraft/item/Item.h"
#include "minecraft/client/TextureAtlasItem.h"
#include "minecraft/item/ItemStack.h"
#include "Zenova.h"

class PhilosophersStoneItem : public Item {
private:
	TextureAtlasItem textureItem;
public:
	PhilosophersStoneItem(const std::string&, short);
	virtual bool showsDurabilityInCreative() const;
	virtual short getMaxDamage() const;
};
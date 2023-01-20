#pragma once
#include "Base/FurnaceBlockActor.h"
#include "EquivalentExchange.h"
class DMFurnaceBlockActor : public FurnaceBlockActor {
public:
	std::vector<ItemStack> furnace_ingredient_items_pack;
	std::vector<ItemStack> furnace_output_items_pack;

	DMFurnaceBlockActor(BlockActorType type, const BlockPos& pos, const Util::HashString& hashString, LevelSoundEvent sound, ContainerType containerType, int burnInterval, const Block& normal, const Block& lit);
	virtual void tick(BlockSource&);

	virtual const ItemStack& getItem(int) const;
	virtual void setItem(int, const ItemStack&);

	virtual int getContainerSize() const;
	virtual int getMaxStackSize() const;
};
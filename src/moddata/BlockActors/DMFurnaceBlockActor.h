#pragma once
#include "Base/FurnaceBlockActor.h"
class DMFurnaceBlockActor : public FurnaceBlockActor {
public:
	ItemStack inputItemStack;
	ItemStack fuelItemStack;
	ItemStack outputItemStack;
	ItemInstance itemInstanceIDK;

	std::vector<ItemStack> inputItemPack;
	std::vector<ItemStack> outputItemPack;

	DMFurnaceBlockActor(const BlockPos& pos, const Block& normal, const Block& lit);
	virtual ~DMFurnaceBlockActor();
	virtual std::string getName() const;
	virtual Container* getContainer();
	virtual const ItemStack& getItem(int slotId) const;
	virtual void setItem(int slotId, const ItemStack& stack);
	virtual int getContainerSize() const;
	virtual int getMaxStackSize() const;
};
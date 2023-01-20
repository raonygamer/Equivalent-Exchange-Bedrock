#include "DMFurnaceBlockActor.h"

DMFurnaceBlockActor::DMFurnaceBlockActor(BlockActorType type, const BlockPos& pos, const Util::HashString& hashString, LevelSoundEvent sound, ContainerType containerType, int burnInterval, const Block& normal, const Block& lit) : FurnaceBlockActor(type, pos, hashString, sound, containerType, burnInterval, normal, lit)
{
	for (int i = 0; i < 8; i++) {
		furnace_ingredient_items_pack[i] = ItemStack();
		furnace_output_items_pack[i] = ItemStack();
	}
}

void DMFurnaceBlockActor::tick(BlockSource& blockSource)
{
	FurnaceBlockActor::tick(blockSource);

	auto& inputStack = (ItemStack&)getItem(0);
	auto& outputStack = (ItemStack&)getItem(3);
	{
		if (inputStack.getStackSize() < 64) {
			for (int i = 0; i < 8; i++) {
				if (!furnace_ingredient_items_pack[i].isEmptyStack()) {
					furnace_ingredient_items_pack[i].remove(1);
					inputStack.add(1);
				}
			}
		}
	}
	{
		if (!outputStack.isEmptyStack()) {
			for (int i = 0; i < 8; i++) {
				if (furnace_output_items_pack[i].getStackSize() < 64) {
					outputStack.remove(1);
					furnace_output_items_pack[i].add(1);
				}
			}
		}
	}
}

const ItemStack& DMFurnaceBlockActor::getItem(int slotId) const
{
	if (slotId >= 3) {
		int fixedId = slotId - 3;
		if (fixedId <= 7) {
			return furnace_ingredient_items_pack[fixedId % 8];
		}
		else if (fixedId <= 15) {
			return furnace_output_items_pack[fixedId % 8];
		}
		else {
			return ItemStack();
		}
	}
	else {
		return FurnaceBlockActor::getItem(slotId);
	}
}

void DMFurnaceBlockActor::setItem(int slotId, const ItemStack& stack)
{
	if (slotId >= 3) {
		int fixedId = slotId - 3;
		if (fixedId <= 7) {
			furnace_ingredient_items_pack[fixedId % 8] = stack;
		}
		else if (fixedId <= 15) {
			furnace_output_items_pack[fixedId % 8] = stack;
		}
		else {
			return;
		}
	}
	else {
		FurnaceBlockActor::setItem(slotId, stack);
	}
}

int DMFurnaceBlockActor::getContainerSize() const
{
	return 19;
}

int DMFurnaceBlockActor::getMaxStackSize() const
{
	return 64;
}

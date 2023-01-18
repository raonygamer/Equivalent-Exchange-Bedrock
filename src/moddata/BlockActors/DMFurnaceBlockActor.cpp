#include "DMFurnaceBlockActor.h"

ItemStack inputItemStack;
ItemStack fuelItemStack;
ItemStack outputItemStack;
ItemInstance itemInstanceIDK;
std::vector<ItemStack> inputItemPack;
std::vector<ItemStack> outputItemPack;

DMFurnaceBlockActor::DMFurnaceBlockActor(const BlockPos& pos, const Block& normal, const Block& lit) : FurnaceBlockActor(BlockActorType::DarkMatterFurnaceBlockActor, pos, HashedString("DMFurnaceBlockActor"), "DMFurnace", ContainerType::FURNACE, 0, normal, lit) {
	inputItemStack = ItemStack::ItemStack();
	fuelItemStack = ItemStack::ItemStack();
	outputItemStack = ItemStack::ItemStack();

	for (int i = 0; i < 16; i++) {
		if (i <= 8) {
			inputItemPack[i % 8] = ItemStack::ItemStack();
		}
		else {
			outputItemPack[i % 8] = ItemStack::ItemStack();
		}
	}

	setCustomName("DMFurnace");
	itemInstanceIDK = ItemInstance();
}
DMFurnaceBlockActor::~DMFurnaceBlockActor() {};
std::string DMFurnaceBlockActor::getName() const {
	return "DMFurnace";
}
Container* DMFurnaceBlockActor::getContainer() {
	return this;
};
const ItemStack& DMFurnaceBlockActor::getItem(int slotId) const {
	if (slotId <= 2) {
		switch (slotId) {
			case 0: return inputItemStack; break;
			case 1: return fuelItemStack; break;
			case 2: return outputItemStack; break;
		}
	}
	else {
		if (slotId <= 10) {
			return inputItemPack[slotId % 10];
		}
		else if (slotId <= 18) {
			return outputItemPack[slotId % 18];
		}
	}
}
void DMFurnaceBlockActor::setItem(int slotId, const ItemStack& stack) {
	if (slotId <= 2) {
		switch (slotId) {
			case 0: inputItemStack = stack; break;
			case 1: fuelItemStack = stack; break;
			case 2: outputItemStack = stack; break;
		}
	}
	else {			
		if (slotId <= 10) {
			inputItemPack[slotId % 10] = stack;
		}
		else if (slotId <= 18) {
			outputItemPack[slotId % 18] = stack;
		}
	}
}
int DMFurnaceBlockActor::getContainerSize() const {
	return 19;
}
int DMFurnaceBlockActor::getMaxStackSize() const {
	return 64;
}
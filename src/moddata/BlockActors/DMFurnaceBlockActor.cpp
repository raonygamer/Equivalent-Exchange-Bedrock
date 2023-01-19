#include "DMFurnaceBlockActor.h"

DMFurnaceBlockActor::DMFurnaceBlockActor(const BlockPos& pos, const Block& normal, const Block& lit) : FurnaceBlockActor(BlockActorType::DarkMatterFurnaceBlockActor, pos, Util::HashString(), LevelSoundEvent::AddChest, ContainerType::FURNACE, normal, lit) {
	setCustomName("DMFurnace");
}
DMFurnaceBlockActor::~DMFurnaceBlockActor() {};
std::string DMFurnaceBlockActor::getName() const {
	return "DMFurnace";
}

int DMFurnaceBlockActor::getContainerSize() const
{
	return 3;
}

int DMFurnaceBlockActor::getMaxStackSize() const
{
	return 64;
}

#include "DMFurnaceBlockActor.h"

DMFurnaceBlockActor::DMFurnaceBlockActor(BlockActorType type, const BlockPos& pos, const Util::HashString& hashString, LevelSoundEvent sound, ContainerType containerType, int idk, const Block& normal, const Block& lit) : FurnaceBlockActor(type, pos, hashString, sound, containerType, idk, normal, lit) {}
DMFurnaceBlockActor::~DMFurnaceBlockActor() {};
std::string DMFurnaceBlockActor::getName() const {
	return "Furnace";
}

int DMFurnaceBlockActor::getContainerSize() const
{
	return 3;
}

int DMFurnaceBlockActor::getMaxStackSize() const
{
	return 64;
}

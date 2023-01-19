#include "DMFurnaceBlockActor.h"

DMFurnaceBlockActor::DMFurnaceBlockActor(BlockActorType type, const BlockPos& pos, const Util::HashString& hashString, LevelSoundEvent sound, ContainerType containerType, int burnIterval, const Block& normal, const Block& lit) : FurnaceBlockActor(type, pos, hashString, sound, containerType, burnIterval, normal, lit) {
	mRendererId = TR_DEFAULT_RENDERER;
}

int DMFurnaceBlockActor::getContainerSize() const
{
	return 3;
}

int DMFurnaceBlockActor::getMaxStackSize() const
{
	return 64;
}

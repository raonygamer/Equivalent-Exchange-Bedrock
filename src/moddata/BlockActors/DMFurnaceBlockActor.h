#pragma once
#include "Base/FurnaceBlockActor.h"
#include "Zenova.h"
class DMFurnaceBlockActor : public FurnaceBlockActor {
public:
	DMFurnaceBlockActor(BlockActorType type, const BlockPos& pos, const Util::HashString& hashString, LevelSoundEvent sound, ContainerType containerType, int burnInterval, const Block& normal, const Block& lit);
	virtual int getContainerSize() const;
	virtual int getMaxStackSize() const;
};
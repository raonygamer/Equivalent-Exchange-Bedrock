#pragma once
#include "Base/FurnaceBlockActor.h"
class DMFurnaceBlockActor : public FurnaceBlockActor {
public:
	DMFurnaceBlockActor(BlockActorType type, const BlockPos& pos, const Util::HashString& hashString, LevelSoundEvent sound, ContainerType containerType, int idk, const Block& normal, const Block& lit);
	virtual ~DMFurnaceBlockActor();
	virtual std::string getName() const;
	virtual int getContainerSize() const;
	virtual int getMaxStackSize() const;
};
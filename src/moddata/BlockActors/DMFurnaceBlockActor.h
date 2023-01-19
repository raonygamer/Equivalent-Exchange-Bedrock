#pragma once
#include "Base/FurnaceBlockActor.h"
class DMFurnaceBlockActor : public FurnaceBlockActor {
public:
	DMFurnaceBlockActor(const BlockPos& pos, const Block& normal, const Block& lit);
	virtual ~DMFurnaceBlockActor();
	virtual std::string getName() const;
	virtual int getContainerSize() const;
	virtual int getMaxStackSize() const;
};
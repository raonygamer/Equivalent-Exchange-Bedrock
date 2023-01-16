#pragma once
#include "minecraft/block/ActorBlock.h"

class DarkMatterFurnaceBlock : public ActorBlock {
public:
	DarkMatterFurnaceBlock(const std::string& nameId, int id);
	virtual std::shared_ptr<BlockActor> newBlockEntity(const BlockPos&) const {
		return nullptr;
	};
};
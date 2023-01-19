#pragma once
#include "minecraft/block/ActorBlock.h"
#include "Zenova.h"
#include "minecraft/blockactor/BlockActorFactory.h"
#include "minecraft/blockactor/BlockActorRegistry.h"
#include "moddata/BlockActors/DMFurnaceBlockActor.h"

class DMFurnace : public ActorBlock {
public:
	DMFurnace(const std::string&, int);
	virtual bool isContainerBlock() const;
	virtual bool isCraftingBlock() const;
	virtual void onPlace(BlockSource&, const BlockPos&) const;
	virtual void onRemove(BlockSource&, const BlockPos&) const;
	virtual bool use(Player&, const BlockPos&) const;
	virtual std::shared_ptr<BlockActor> newBlockEntity(const BlockPos&) const;
};
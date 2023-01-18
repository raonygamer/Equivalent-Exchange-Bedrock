#pragma once
#include "minecraft/block/ActorBlock.h"
#include "minecraft/blockactor/BlockActorFactory.h"

class FurnaceBlock : public ActorBlock {
public:
	FurnaceBlock::FurnaceBlock(const std::string&, int, bool);
	virtual ~FurnaceBlock();
	virtual bool isContainerBlock(void) const;
	virtual bool isCraftingBlock(void) const;
	virtual bool isInteractiveBlock(void) const;
	virtual void onPlace(BlockSource&, BlockPos const&) const;
	virtual void onRemove(BlockSource&, BlockPos const&) const;
	virtual ItemInstance getResourceItem(Random&, Block const&, int) const;
	virtual ItemInstance asItemInstance(BlockSource&, BlockPos const&, Block const&) const;
	virtual bool use(Player&, BlockPos const&) const;
	virtual const Block& getPlacementBlock(Actor&, BlockPos const&, FacingID, Vec3 const&, int) const;
	virtual bool hasComparatorSignal(void) const;
	virtual int getComparatorSignal(BlockSource&, BlockPos const&, Block const&, FacingID) const;
	virtual FacingID getMappedFace(FacingID, Block const&) const;
	virtual void animateTick(BlockSource&, BlockPos const&, Random&) const;
	virtual ItemInstance getSilkTouchItemInstance(Block const&) const;
	virtual std::shared_ptr<BlockActor> newBlockEntity(const BlockPos& pos) const {
		return BlockActorFactory::createBlockEntity(BlockActorType::Furnace, pos, *this);
	}
};
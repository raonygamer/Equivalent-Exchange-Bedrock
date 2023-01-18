#pragma once
#include "minecraft/blockactor/BlockActor.h"
#include "minecraft/world/Container.h"
#include "minecraft/util/StringHash.h"
#include "minecraft/item/ItemStack.h"
#include "minecraft/actor/Player.h"

class FurnaceBlockActor : public BlockActor, public Container {
public:
	FurnaceBlockActor(BlockActorType, BlockPos const&, HashedString const&, std::string, ContainerType, int, Block const&, Block const&);
	virtual ~FurnaceBlockActor();
	virtual void load(Level&, const CompoundTag&, DataLoadHelper&);
	virtual bool save(CompoundTag&) const;
	virtual void onCustomTagLoadDone(BlockSource&);
	virtual void tick(BlockSource&);
	virtual void onChanged(BlockSource&);
	virtual void onPlace(BlockSource&);
	virtual std::string getName() const;
	virtual Container* getContainer();
	virtual const ItemStack& getItem(int) const;
	virtual void setItem(int, const ItemStack&);
	virtual int getContainerSize() const;
	virtual int getMaxStackSize() const;
	//virtual bool canPushInItem(BlockSource&, int, int, const ItemInstance&) const;
	virtual bool canPullOutItem(BlockSource&, int, int, const ItemInstance&) const;
};
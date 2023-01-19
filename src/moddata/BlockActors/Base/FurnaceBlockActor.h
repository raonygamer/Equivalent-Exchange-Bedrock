#pragma once
#include "minecraft/blockactor/BlockActor.h"
#include "minecraft/world/Container.h"
#include "minecraft/util/StringHash.h"
#include "minecraft/item/ItemStack.h"
#include "minecraft/actor/Player.h"

class FurnaceBlockActor : public BlockActor, public Container {
public:
	FurnaceBlockActor(BlockActorType, const BlockPos&, const Util::HashString&, LevelSoundEvent, ContainerType, const Block&, const Block&); //0x1629340
	virtual ~FurnaceBlockActor(); //0x160EF40

	//FurnaceBlockActor::`vftable'{for `Container'}
	virtual const ItemStack& getItem(int) const; //0x16170E0
	virtual void setItem(int, const ItemStack&); //0x1629540
	virtual void startOpen(Player&); //0x1629750
	virtual void stopOpen(Player&); //0x16297A0
	virtual bool canPushInItem(BlockSource&, int, int, const ItemInstance&) const; //0x1629820
	virtual bool canPushOutItem(BlockSource&, int, int, const ItemInstance&) const; //0x1629870

	//FurnaceBlockActor::`vftable'{for `BlockActor'}
	virtual void load(Level&, const CompoundTag&, DataLoadHelper&); //0x162CF10
	virtual bool save(CompoundTag&) const; //0x162D2C0
	virtual void onCustomTagLoadDone(BlockSource&); //0x1629FC0
	virtual void tick(BlockSource&); //0x162A4A0
	virtual bool isFinished(); //0x162A480
	virtual std::unique_ptr<Packet> getUpdatePacket(BlockSource&); //0x162BC70
	virtual void onNeighborChanged(BlockSource&, const BlockPos&); //0x162B6D0
	virtual std::string getName() const; //0x16296C0
	virtual void _onUpdatePacket(const CompoundTag&, BlockSource&); //0x162BF20
};
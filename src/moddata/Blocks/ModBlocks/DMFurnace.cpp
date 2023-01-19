#include "DMFurnace.h"
#include "minecraft/block/VanillaBlockRegistry.h"
#include "minecraft/block/BlockRegistry.h"
#include "../BlockManager.h"

DMFurnace::DMFurnace(const std::string& name, int id) : ActorBlock(name, id, Material::getMaterial(MaterialType::Stone))
{
	mBlockEntityType = BlockActorType::DarkMatterFurnaceBlockActor;
	setSolid(true);
	setIsInteraction(true);
	setCategory(CreativeItemCategory::ITEMS);
}

bool DMFurnace::isContainerBlock() const
{
	return true;
}

bool DMFurnace::isCraftingBlock() const
{
	return true;
}

bool DMFurnace::use(Player& player, const BlockPos& pos) const
{
	BlockSource& blockSource = player.getRegion();
	BlockActor* blockEntity = blockSource.getBlockEntity(pos);
	if (blockEntity != nullptr) {
		player.openFurnace(pos);
		return true;
	}
	else {
		return false;
	}
}

std::shared_ptr<BlockActor> DMFurnace::newBlockEntity(const BlockPos& pos) const
{
	Zenova_Info("New block entity, executed.");
	return std::make_shared<DMFurnaceBlockActor>(BlockActorType::DarkMatterFurnaceBlockActor, pos, Util::HashString("dm_furnace"), LevelSoundEvent::Undefined, ContainerType::FURNACE, 1, *VanillaBlocks::mGrass, *VanillaBlocks::mCobblestone);
}
//
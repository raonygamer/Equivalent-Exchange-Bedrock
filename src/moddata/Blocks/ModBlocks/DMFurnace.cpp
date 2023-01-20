#include "DMFurnace.h"
#include "minecraft/block/VanillaBlockRegistry.h"
#include "minecraft/block/BlockRegistry.h"
#include "../BlockManager.h"

DMFurnace::DMFurnace(const std::string& name, int id) : ActorBlock(name, id, Material::getMaterial(MaterialType::Metal))
{
	mBlockEntityType = BlockActorType::DarkMatterFurnaceBlockActor; //this triggers BlockActorFactory::createBlockEntity from vanilla game
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
	return std::make_shared<DMFurnaceBlockActor>(BlockActorType::Furnace, pos, Util::HashString("furnace"), LevelSoundEvent::Undefined, ContainerType::FURNACE, 10, this->getDefaultState(), this->getDefaultState());
}
//this is the block
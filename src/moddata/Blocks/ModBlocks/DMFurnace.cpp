#include "DMFurnace.h"

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

void DMFurnace::onPlace(BlockSource&, const BlockPos& pos) const
{
	
}

void DMFurnace::onRemove(BlockSource&, const BlockPos&) const
{

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
	Zenova_Info("New Block Entity created!");
	return std::make_shared<DMFurnaceBlockActor>(pos, this->getDefaultState(), this->getDefaultState());
}

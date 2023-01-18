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

bool DMFurnace::use(Player&, const BlockPos&) const
{
	return false;
}

std::shared_ptr<BlockActor> DMFurnace::newBlockEntity(const BlockPos& pos) const
{
	Zenova_Info("New Block Entity created!");
	return nullptr;//std::make_shared<DMFurnaceBlockActor>(pos, this->getDefaultState(), this->getDefaultState());
}

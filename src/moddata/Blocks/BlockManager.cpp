#include "BlockManager.h"

void BlockManager::Initialize()
{
	dmFurnace = Zenova::BlockRegistry::registerBlock<DMFurnace>("equivalentexchange:dm_furnace", BlockShape::BLOCK);
	Zenova::BlockActorRegistry::registerBlockActor("DMFurnace", BlockActorType::DarkMatterFurnaceBlockActor, dmFurnace);
}

void BlockManager::InitializeBlockItems()
{
	ItemRegistry::registerBlockItem<BlockItem>(dmFurnace->get()->getDescriptionId(), *dmFurnace->get());
}

void BlockManager::InitializeCreativeBlocks() 
{
	Item::beginCreativeGroup("itemGroup.name.eeFurnaces", &dmFurnace->get()->getDefaultState(), nullptr);
	Item::addCreativeItem(dmFurnace->get()->getDefaultState());
	Item::endCreativeGroup();
}
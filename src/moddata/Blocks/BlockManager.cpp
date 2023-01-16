#include "BlockManager.h"

WeakPtr<BlockLegacy>* BlockManager::darkMatterFurnace;

void BlockManager::Initialize()
{
	darkMatterFurnace = Zenova::BlockRegistry::registerBlock<DarkMatterFurnaceBlock>("equivalentexchange:dark_matter_furnace", BlockShape::BLOCK);
}

void BlockManager::InitializeBlockItems()
{
	ItemRegistry::registerBlockItem<BlockItem>(darkMatterFurnace->get()->getDescriptionId(), *darkMatterFurnace->get());
}

void BlockManager::InitializeCreativeBlocks()
{
	Item::beginCreativeGroup("itemGroup.name.eeFurnaces", &darkMatterFurnace->get()->getDefaultState(), nullptr);
	Item::addCreativeItem(darkMatterFurnace->get()->getDefaultState());
	Item::endCreativeGroup();
}

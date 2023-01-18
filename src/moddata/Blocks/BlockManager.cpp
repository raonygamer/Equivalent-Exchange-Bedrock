#include "BlockManager.h"

void BlockManager::Initialize()
{
	furnaceTemplate = Zenova::BlockRegistry::registerBlock<DMFurnace>("equivalentexchange:furnace_template", BlockShape::BLOCK);
}

void BlockManager::InitializeBlockItems()
{
	ItemRegistry::registerBlockItem<BlockItem>("equivalentexchange:furnace_template", *furnaceTemplate->get());
}

void BlockManager::InitializeCreativeBlocks()
{
}

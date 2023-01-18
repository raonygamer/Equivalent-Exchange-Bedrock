#include "BlockManager.h"

void BlockManager::Initialize()
{
	furnaceTemplate = Zenova::BlockRegistry::registerBlock<FurnaceBlock>("equivalentexchange:furnace_template", BlockShape::BLOCK, false);
}

void BlockManager::InitializeBlockItems()
{

}

void BlockManager::InitializeCreativeBlocks()
{
}

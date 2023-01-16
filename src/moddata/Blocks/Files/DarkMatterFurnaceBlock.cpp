#include "DarkMatterFurnaceBlock.h"

DarkMatterFurnaceBlock::DarkMatterFurnaceBlock(const std::string& nameId, int id) : ActorBlock(nameId, id, Material::getMaterial(MaterialType::Metal))
{
	setSolid(true);
	setCategory(CreativeItemCategory::ITEMS);
}

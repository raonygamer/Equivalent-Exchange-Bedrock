#include "DMFurnace.h"

DMFurnace::DMFurnace(const std::string& name, int id) : FurnaceBlock(name, id, false)
{
	setSolid(true);
	setIsInteraction(true);
	setIsVanillaBlock(false);
}

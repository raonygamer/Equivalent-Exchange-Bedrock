#pragma once
#include "minecraft/block/BlockRegistry.h"
#include "minecraft/block/BlockLegacy.h"
#include "Files/DarkMatterFurnaceBlock.h"
#include "minecraft/item/ItemRegistry.h"
#include "minecraft/item/BlockItem.h"

namespace Json { class Value; }

class BlockManager {
public:
	static WeakPtr<BlockLegacy>* darkMatterFurnace;

	static void Initialize();
	static void InitializeBlockItems();
	static void InitializeCreativeBlocks();
};
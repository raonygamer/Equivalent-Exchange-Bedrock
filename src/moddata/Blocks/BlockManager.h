#pragma once
#include "minecraft/block/BlockRegistry.h"
#include "minecraft/block/BlockLegacy.h"
#include "minecraft/item/ItemRegistry.h"
#include "minecraft/item/BlockItem.h"
#include "minecraft/blockactor/BlockActorRegistry.h"
#include "Zenova.h"
#include "Base/FurnaceBlock.h"

namespace Json { class Value; }

class BlockManager {
public:
	inline static WeakPtr<BlockLegacy>* furnaceTemplate;

	static void Initialize();
	static void InitializeBlockItems();
	static void InitializeCreativeBlocks();
};
#pragma once

#include "ItemInclude.h"
#include "minecraft/util/SharedPtr.h"
#include "minecraft/item/ItemRegistry.h"
#include <string>

class ItemManager {
public:
	static WeakPtr<PhilosophersStoneItem> philosophersStoneItem;

	static void Initialize();
	static void Deinitialize();
	static void InitializeCreative();
	static void InitializeTextures();
};
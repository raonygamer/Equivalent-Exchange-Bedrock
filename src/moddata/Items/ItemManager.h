#pragma once

#include "ItemInclude.h"
#include "minecraft/util/SharedPtr.h"
#include "minecraft/item/ItemRegistry.h"
#include <string>

class ItemManager {
public:
	static std::map<std::string, WeakPtr<Item>> Items;

	static void Initialize();
	static void InitializeCreative();
	static void InitializeTextures();
	template<typename T>
	static WeakPtr<T> GetItem(const std::string& name) {
		auto iterator = Items.find(name);
		if (iterator == Items.end())
			return nullptr;
		else
			return iterator->second;
	}
};
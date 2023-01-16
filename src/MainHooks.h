#pragma once

#include "moddata/Items/ItemManager.h"
#include "minecraft/world/ContentLog.h"
#include "minecraft/item/Recipes.h"
#include "minecraft/block/BlockRegistry.h"
#include "minecraft/block/BlockTessellatorRegistry.h"
#include "moddata/Blocks/BlockManager.h"

class MainHooks {
public:
	inline static void (*RegisterItemsTrampoline)(bool flag);
	static void RegisterItemsHook(bool flag) {
		RegisterItemsTrampoline(flag);
		ItemManager::Initialize();
		BlockManager::InitializeBlockItems();
	}

	inline static void (*InitializeCreativeItemsTrampoline)(class ActorInfoRegistry*, class BlockDefinitionGroup*, bool);
	static void InitializeCreativeItemsHook(class ActorInfoRegistry* actorInfoRegistry, class BlockDefinitionGroup* blockDefinitionGroup, bool flag) {
		InitializeCreativeItemsTrampoline(actorInfoRegistry, blockDefinitionGroup, flag);
		ItemManager::InitializeCreative();
		BlockManager::InitializeCreativeBlocks();
	}

	inline static void (*InitializeClientTrampoline)();
	static void InitializeClientHook() {
		InitializeClientTrampoline();
		ItemManager::InitializeTextures();	
	}

	inline static void (*UnregisterItemsTrampoline)();
	static void UnregisterItemsHook() {
		UnregisterItemsTrampoline();
		ItemManager::Deinitialize();
	}

	inline static void (*ItemStackReinitTrampoline)(ItemStack*, const Item&, int, int);
	static void ItemStackReinitHook(ItemStack* self, const Item& item, int id, int aux) {
		if (item.getCommandName() == "equivalentexchange:philosophers_stone")
			item.setDamageValue(*self, 1000);
		ItemStackReinitTrampoline(self, item, id, aux);
	}

	inline static int (*ContentLogTrampoline)(ContentLog*, LogLevel, LogArea, std::string&);
	static int ContentLogHook(ContentLog* self, LogLevel level, LogArea area, std::string& str) {
		Zenova_Info(str);
		return ContentLogTrampoline(self, level, area, str);
	}

	inline static void (*RegisterBlocksTrampoline)(BlockDefinitionGroup*);
	static void RegisterBlocksHook(BlockDefinitionGroup* defGroup) {
		for (auto block : Zenova::BlockRegistry::BlockRegistryList)
			block->initBlock(defGroup);

		RegisterBlocksTrampoline(defGroup);
	}

	inline static void (*RegisterLooseBlockGraphicsTrampoline)(std::vector<Json::Value>&, const BlockPalette&);
	static void RegisterLooseBlockGraphicsHook(std::vector<Json::Value>& json, const BlockPalette& palette) {
		for (auto block : Zenova::BlockRegistry::BlockRegistryList)
			block->initBlockGraphics(json);

		RegisterLooseBlockGraphicsTrampoline(json, palette);
	}

	inline static bool (*TessellateInWorldTrampoline)(BlockTessellator*, Tessellator&, const Block&, const BlockPos&, void*);
	static bool TessellateInWorldHook(BlockTessellator* self, Tessellator& tessellator, const Block& block, const BlockPos& pos, void* idk) {
		if (!Zenova::BlockTessellatorRegistry::tessellateInWorld(self, tessellator, block, pos))
			return TessellateInWorldTrampoline(self, tessellator, block, pos, idk);
		return true;
	}

	inline static bool (*CanRenderBlockInGuiTrampoline)(BlockShape);
	static bool CanRenderBlockInGuiHook(BlockShape shape) {
		if (!Zenova::BlockTessellatorRegistry::canRender(shape))
			return CanRenderBlockInGuiTrampoline(shape);
		return true;
	}
};
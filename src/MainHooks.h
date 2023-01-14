#pragma once

#include "moddata/Items/ItemManager.h"

class MainHooks {
public:
	static void (*RegisterItemsTrampoline)(bool flag);
	static void RegisterItemsHook(bool flag) {
		RegisterItemsTrampoline(flag);
		ItemManager::Initialize();
	}

	static void (*InitializeCreativeItemsTrampoline)(class ActorInfoRegistry*, class BlockDefinitionGroup*, bool);
	static void (InitializeCreativeItemsHook)(class ActorInfoRegistry* actorInfoRegistry, class BlockDefinitionGroup* blockDefinitionGroup, bool flag) {
		InitializeCreativeItemsTrampoline(actorInfoRegistry, blockDefinitionGroup, flag);
		ItemManager::InitializeCreative();
	}

	static void (*InitializeClientTrampoline)();
	static void (InitializeClientHook)() {
		InitializeClientTrampoline();
		ItemManager::InitializeTextures();
	}
};
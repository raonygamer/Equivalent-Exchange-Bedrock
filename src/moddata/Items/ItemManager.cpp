#include "ItemManager.h"

bool ItemManager::InitializedClientData = false;
WeakPtr<PhilosophersStoneItem> ItemManager::philosophersStoneItem;



void ItemManager::Initialize() {
	philosophersStoneItem = ItemRegistry::registerItem<PhilosophersStoneItem>("equivalentexchange:philosophers_stone", ItemRegistry::getMaxItemID());
}

void ItemManager::Deinitialize() {
	InitializedClientData = false;
}

void ItemManager::InitializeCreative() {
	Item::beginCreativeGroup("itemGroup.name.exchangeItems", philosophersStoneItem.get(), 0, nullptr);
	Item::addCreativeItem(philosophersStoneItem.get(), 0);
	Item::endCreativeGroup();
}

void ItemManager::InitializeTextures() {
	InitializedClientData = true;
	philosophersStoneItem->setIcon("philosophers_stone", 0);
}
#include "ItemManager.h"

WeakPtr<PhilosophersStoneItem> ItemManager::philosophersStoneItem;

void ItemManager::Initialize() {
	philosophersStoneItem = ItemRegistry::registerItem<PhilosophersStoneItem>("equivalentexchange:philosophers_stone", ItemRegistry::getMaxItemID());
}

void ItemManager::Deinitialize() {}

void ItemManager::InitializeCreative() {
	Item::beginCreativeGroup("itemGroup.name.exchangeItems", philosophersStoneItem.get(), 0, nullptr);
	Item::addCreativeItem(philosophersStoneItem.get(), 0);
	Item::endCreativeGroup();
}

void ItemManager::InitializeTextures() {
	philosophersStoneItem->setIcon("philosophers_stone", 0);
}
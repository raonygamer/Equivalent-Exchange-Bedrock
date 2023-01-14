#include "ItemManager.h"

std::map<std::string, WeakPtr<Item>> ItemManager::Items;

void ItemManager::Initialize() {
	Items.insert(std::pair<std::string, WeakPtr<PhilosophersStoneItem>>("philosophers_stone", ItemRegistry::registerItem<PhilosophersStoneItem>("equivalentexchange:philosophers_stone", ItemRegistry::getMaxItemID())));
}

void ItemManager::InitializeCreative() {
	auto& philosophersStone = GetItem<PhilosophersStoneItem>("philosophers_stone");

	Item::beginCreativeGroup("itemGroup.name.exchangeItems", philosophersStone.get(), 0, nullptr);
	Item::addCreativeItem(philosophersStone.get(), 0);
	Item::endCreativeGroup();
}

void ItemManager::InitializeTextures() {
	auto& philosophersStone = GetItem<PhilosophersStoneItem>("philosophers_stone");

	philosophersStone->setIcon("philosophers_stone", 0);
}
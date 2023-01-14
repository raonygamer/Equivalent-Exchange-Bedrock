#include "ItemManager.h"

std::map<std::string, WeakPtr<Item>> ItemManager::Items;

void ItemManager::Initialize() {
	Items.insert(std::pair<std::string, WeakPtr<Item>>("tsunami_bow", ItemRegistry::registerItem<BowItem>("eexchange:tsunami_bow", ItemRegistry::getMaxItemID())));
}

void ItemManager::InitializeCreative() {
	auto& tsunamiBow = GetItem<BowItem>("tsunami_bow");

	Item::beginCreativeGroup("itemGroup.name.modbows", tsunamiBow.get(), 0, nullptr);
	Item::addCreativeItem(tsunamiBow.get(), 0);
	Item::endCreativeGroup();
}

void ItemManager::InitializeTextures() {
	
}
#include "EquivalentExchange.h"

void EquivalentExchange::Start() {
	if (Zenova::Minecraft::version() == Zenova::Version("1.14.60.5"))
	{
		Zenova_Info("Equivalent Exchange loaded successfully, creating hooks and instantiating content.");
		CreateHooks();
	}
	else
	{
		Zenova_Info("Unable to load Equivalent Exchange, wrong version.");
		Stop();
	}
}

void EquivalentExchange::CreateHooks() {
	Zenova_Hook(VanillaItems::registerItems, &MainHooks::RegisterItemsHook, &MainHooks::RegisterItemsTrampoline);
	Zenova_Hook(VanillaItems::initCreativeItemsCallback, &MainHooks::InitializeCreativeItemsHook, &MainHooks::InitializeCreativeItemsTrampoline);
	Zenova_Hook(VanillaItems::initClientData, &MainHooks::InitializeClientHook, &MainHooks::InitializeClientTrampoline);
	Zenova_Info("Created Hooks Successfully.");
}

void EquivalentExchange::Update() {

}


void EquivalentExchange::Tick() {

}


void EquivalentExchange::Stop() {

}

EquivalentExchange::~EquivalentExchange() {};

MOD_FUNCTION Zenova::Mod* CreateMod() {
	return new EquivalentExchange;
}
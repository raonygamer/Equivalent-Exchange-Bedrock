#include "EquivalentExchange.h"

void EquivalentExchange::Start() {
	if (Zenova::Minecraft::version() == Zenova::Version("1.14.60.5"))
	{
		Zenova_Info("Equivalent Exchange loaded successfully, creating hooks and instantiating content.");
		CreateHooks();
		CreateInputs();
		BlockManager::Initialize();
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
	Zenova_Hook(VanillaItems::unregisterItems, &MainHooks::UnregisterItemsHook, &MainHooks::UnregisterItemsTrampoline);
	Zenova_Hook(BlockGraphics::registerLooseBlockGraphics, &MainHooks::RegisterLooseBlockGraphicsHook, &MainHooks::RegisterLooseBlockGraphicsTrampoline);
	Zenova_Hook(BlockDefinitionGroup::registerBlocks, &MainHooks::RegisterBlocksHook, &MainHooks::RegisterBlocksTrampoline);
	Zenova_Hook(BlockTessellator::tessellateInWorld, &MainHooks::TessellateInWorldHook, &MainHooks::TessellateInWorldTrampoline);
	Zenova_Hook(BlockTessellator::canRender, &MainHooks::CanRenderBlockInGuiHook, &MainHooks::CanRenderBlockInGuiTrampoline);
	{
		Zenova_Hook(ItemStack::init, &MainHooks::ItemStackReinitHook, &MainHooks::ItemStackReinitTrampoline);
	}
	//Zenova_Hook(BlockActorFactory::createBlockEntity, &MainHooks::CreateBlockEntityHook, &MainHooks::CreateBlockEntityTrampoline);
	Zenova_Hook(BlockActor::initBlockEntities, &MainHooks::InitializeBlockEntitiesHook, &MainHooks::InitializeBlockEntitiesTrampoline);
	Zenova_Hook(BlockActorRenderDispatcher::initializeBlockEntityRenderers, &MainHooks::InitializeBlockActorRenderersHook, &MainHooks::InitializeBlockActorRenderersTrampoline);
	Zenova_Info("Created Hooks Successfully.");
}

void EquivalentExchange::CreateInputs() {
	Zenova::InputManager::addInput("charge_item", &MainInputs::ChargeKeyEvent).addKeyboardBind<char>('C').setKeyboardMapping('C');
	Zenova::InputManager::addInput("uncharge_item_helper", &HelperInputs::HelperChargeKeyEvent).addKeyboardBind(KeyboardBinding::Control).setKeyboardMapping(KeyboardBinding::Control);
	Zenova_Info("Created Inputs Successfully.");
}

void EquivalentExchange::Update() {
	TickRuntime::Update();
}


void EquivalentExchange::Tick() {
	TickRuntime::Tick();
}


void EquivalentExchange::Stop() {

}

EquivalentExchange::~EquivalentExchange() {};

MOD_FUNCTION Zenova::Mod* CreateMod() {
	return new EquivalentExchange;
}
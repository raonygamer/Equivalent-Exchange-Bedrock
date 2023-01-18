#include "Zenova.h"
#include "Zenova/Minecraft/Inputs.h"

#include "generated/initcpp.h"

#include "MainHooks.h"
#include "MainInputs.h"
#include "minecraft/item/VanillaItems.h"
#include "fmt/color.h"
#include "moddata/Managers/TickRuntime.h"
#include "moddata/Blocks/BlockManager.h"
#include "minecraft/item/Item.h"

class EquivalentExchange : public Zenova::Mod {
public:
	virtual void Start();
	virtual void Update();
	virtual void Tick();
	virtual void Stop();
	void CreateHooks();
	void CreateInputs();
	virtual ~EquivalentExchange();
};
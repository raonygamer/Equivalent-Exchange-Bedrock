#include "Zenova.h"

#include "generated/initcpp.h"

#include "MainHooks.h"
#include "minecraft/item/VanillaItems.h"

class EquivalentExchange : public Zenova::Mod {
public:
	virtual void Start();
	virtual void Update();
	virtual void Tick();
	virtual void Stop();
	void CreateHooks();
	virtual ~EquivalentExchange();
};
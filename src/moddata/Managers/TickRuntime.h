#pragma once

#include "moddata/Items/ItemManager.h"

class TickRuntime {
public:
	inline static long Ticks;
	inline static long Updates;

	static void Tick() {
		Ticks++;
	}

	static void Update() {
		Updates++;
	}
};
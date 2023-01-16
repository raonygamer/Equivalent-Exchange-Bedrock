#pragma once

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
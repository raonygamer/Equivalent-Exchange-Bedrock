#pragma once
#include "minecraft/client/IClientInstance.h"
#include "minecraft/item/ItemStack.h"

class PitchCalculator {
public:
	static float calcPitch(int chargeAmount) {
		if (chargeAmount >= 750)
			return 0.7f;
		if (chargeAmount >= 500)
			return 0.8f;
		if (chargeAmount >= 250)
			return 0.9f;
		return 1;
	}
};

class HelperInputs {
public:
	inline static bool HelperChargePressed;
	static void HelperChargeKeyEvent(bool pressed, IClientInstance& client) {
		HelperChargePressed = pressed;
	}
};

class MainInputs {
public:
	static void ChargeKeyEvent(bool pressed, IClientInstance& client) {
		if (!pressed) return;

		LocalPlayer& localPlayer = client.getLocalPlayer();
		ItemStack& itemStack = (ItemStack&)localPlayer.getSelectedItem();

		if (itemStack.isItem() && itemStack.getItem()->getCommandName() == "equivalentexchange:philosophers_stone") {
			int currentChargeValue = itemStack.getDamageValue();
			if (currentChargeValue <= 5 && !HelperInputs::HelperChargePressed) return;
			if (currentChargeValue >= 1000 && HelperInputs::HelperChargePressed) return;
			currentChargeValue += (HelperInputs::HelperChargePressed ? 250 : -250);
			itemStack.setDamageValue(currentChargeValue);
			localPlayer.getLevel().playSound((HelperInputs::HelperChargePressed ? "ee.uncharge" : "ee.charge"), localPlayer.getPos(), 1, PitchCalculator::calcPitch(currentChargeValue));
		}
	}
};
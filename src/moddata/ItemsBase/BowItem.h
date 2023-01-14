#pragma once
#include "minecraft/item/Item.h"

class RangedWeaponItem : public Item {};
class BowItem : public RangedWeaponItem {
public:
    BowItem(const std::string&, int);
};
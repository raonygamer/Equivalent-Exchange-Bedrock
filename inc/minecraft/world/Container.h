#pragma once

#include <deque>
#include <functional>
#include <string>
#include <unordered_set>

#include "minecraft/CommonTypes.h"

#define stringify(name) #name

class BlockSource;
class CompoundTag;
class ItemDescriptor;
class ItemInstance;
class ItemStack;
class Player;
class Vec3;

enum class ContainerType : signed char {
    NONE = -9,
    INVENTORY = -1,
    CONTAINER,
    WORKBENCH,
    FURNACE,
    ENCHANTMENT,
    BREWING_STAND,
    ANVIL,
    DISPENSER,
    DROPPER,
    HOPPER,
    CAULDRON,
    MINECART_CHEST,
    MINECART_HOPPER,
    HORSE,
    BEACON,
    STRUCTURE_EDITOR,
    TRADE,
    COMMAND_BLOCK,
    JUKEBOX,
    ARMOR,
    HAND,
    COMPOUND_CREATOR,
    ELEMENT_CONSTRUCTOR,
    MATERIAL_REDUCER,
    LAB_TABLE,
    LOOM,
    LECTERN,
    GRINDSTONE,
    BLAST_FURNACE,
    SMOKER,
    STONECUTTER,
    CARTOGRAPHY
};

unsigned char ENUM_HASH(ContainerType);

enum class ContainerID : signed char {
    CONTAINER_ID_NONE = -1,
    CONTAINER_ID_INVENTORY,
    CONTAINER_ID_FIRST,
    CONTAINER_ID_LAST = 100,
    CONTAINER_ID_OFFHAND = 119,
    CONTAINER_ID_ARMOR,
    CONTAINER_ID_CREATIVE,
    CONTAINER_ID_SELECTION_SLOTS,
    CONTAINER_ID_PLAYER_ONLY_UI = 124
};

class ContainerSizeChangeListener {
public:
    virtual void containerSizeChanged(int);
    virtual ~ContainerSizeChangeListener();
};

class ContainerContentChangeListener {
public:
    virtual void containerContentChanged(int);
    virtual ~ContainerContentChangeListener();
};

class Container {
public:
    static const int LARGE_MAX_STACK_SIZE = 64;
    static const int DEFAULT_CONTAINER_SIZE = 27;
    static const int INVALID_SLOT = -1;
protected:
    ContainerType mContainerType;
    std::unordered_set<ContainerContentChangeListener*> mContentChangeListeners;
    std::unordered_set<ContainerSizeChangeListener*> mSizeChangeListeners;
    std::deque<std::function<void(Container&, int, const ItemStack&, const ItemStack&)>> mTransactionContextStack;
    std::string mName;
    bool mCustomName;

public:
    Container(ContainerType);
    Container(ContainerType, const std::string&, bool);
    virtual ~Container();
    virtual void init();
    void addSizeChangeListener(ContainerSizeChangeListener* listener);
    void removeSizeChangeListener(ContainerSizeChangeListener* listener);
    virtual void addContentChangeListener(ContainerContentChangeListener* listener);
    virtual void removeContentChangeListener(ContainerContentChangeListener* listener);
    virtual const ItemStack& getItem(int slot) const;
    virtual bool hasRoomForItem(const ItemStack& item);
    virtual void addItem(ItemStack& item);
    virtual bool addItemToFirstEmptySlot(ItemStack& item);
    virtual void setItem(int slot, const ItemStack& item);
    virtual void removeItem(int slot, int count);
    virtual void removeAllItems();
    virtual void dropContents(BlockSource& region, const Vec3& pos, bool randomizeDrop);
    virtual int getContainerSize() const;
    virtual int getMaxStackSize() const;
    virtual void startOpen(Player& player);
    virtual void stopOpen(Player& player);
    virtual std::vector<ItemStack> getSlotCopies() const;
    virtual const std::vector<ItemStack const*> getSlots() const;
    virtual int getItemCount(const ItemDescriptor& descriptor);
    virtual int getItemCount(const ItemStack& compare);
    virtual int findFirstSlotForItem(const ItemStack& item) const;
    virtual bool canPushInItem(BlockSource& region, int slot, int face, const ItemInstance& item) const;
    virtual bool canPullOutItem(BlockSource& region, int slot, int face, const ItemInstance& item) const;
    ContainerType getContainerType();
    int getRedstoneSignalFromContainer();
    void setSizeChanged(int);
    virtual void setContainerChanged(int);
    virtual void setContainerMoved();
    virtual void setCustomName(const std::string&);
    virtual bool hasCustomName() const;
    virtual void readAdditionalSaveData(const CompoundTag& tag);
    virtual void addAdditionalSaveData(CompoundTag& tag);
    virtual void createTransactionContext(std::function<void(Container&, int, const ItemStack&, const ItemStack&)> callback, std::function<void()> execute);
    virtual void triggerTransactionChange(int slot, const ItemStack& oldItem, const ItemStack& newItem);
    static const std::string& getContainerTypeName(ContainerType type) {
        return stringify(type);
    }
    static ContainerType getContainerTypeId(const std::string&);
};
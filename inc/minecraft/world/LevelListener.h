#pragma once

#include "BlockSourceListener.h"

class LevelListener : public BlockSourceListener {
public:
    virtual ~LevelListener();
    virtual void filler0();
    virtual void filler1();
    virtual void filler2();
    virtual void filler3();
    virtual void filler4();
    virtual void filler5();
    virtual void filler6();
    virtual void filler7();
    virtual void filler8();
    virtual void filler9();
    virtual void filler10();
    virtual void filler11();
    virtual void filler12();
    virtual void filler13();
    virtual void filler14();
    virtual void filler15();
    virtual void filler16();
    virtual void filler17();
    virtual void filler18();
    virtual void levelSoundEvent(LevelSoundEvent, const Vec3&, int, const ActorDefinitionIdentifier&, bool, bool);
    virtual void levelSoundEvent(const std::string& name, const Vec3& pos, float volume, float pitch);
};
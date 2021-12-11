#pragma once

#ifndef _LevelUpInstance_CLASS_
#define _LevelUpInstance_CLASS_

class LevelUpInstance {
public:
    LevelUpInstance();
    void GainXP(float amount);
    void LevelUp();

    int GetLevel() { return level; }
    float GetHPModifier();

private:
    int level;
    float xp;
    float xpNeededForLevelUp;
};

#endif
#include "LevelUpInstance.hpp"

LevelUpInstance::LevelUpInstance()
{
    level = 1;
    xp = 0.0f;
    xpNeededForLevelUp = 20.0f;
}

void LevelUpInstance::GainXP(float amount)
{
    xp += amount;
    if (xp >= xpNeededForLevelUp) {
        xp -= xpNeededForLevelUp;
        level += 1;
    }
}

void LevelUpInstance::LevelUp()
{
    level += 1;
    xp = 0.0f;
}

float LevelUpInstance::GetHPModifier()
{
    return (1.0f + (level * 0.1f));
}
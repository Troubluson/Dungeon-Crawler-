#pragma once

#include "Actors/character.hpp"
#include "LevelUpInstance.hpp"

#ifndef _LevelUpSystem_CLASS_
#define _LevelUpSystem_CLASS_

class LevelUpSystem {
public:
    static void AddCharacter(Character* character);
    static void GainXP(Character* character, float amount);
    static void LevelUp(Character* character);

    static int GetLevel(Character* character);
    static float GetHPModifier(Character* character);

    static std::unordered_map<Character*, LevelUpInstance> characterLevelMap;
};

#endif
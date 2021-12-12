#pragma once

#include "Actors/character.hpp"
#include "LevelUpInstance.hpp"

#ifndef _LevelUpSystem_CLASS_
#define _LevelUpSystem_CLASS_

class LevelUpSystem {
public:
    /**
     * @brief Function for adding a character to the LevelUpSystem.
     *
     * @param character Character to add to the LevelUpSystem
     */
    static void AddCharacter(Character* character);

    /**
     * @brief Function to add XP to a character that is in the LevelUpSystem.
     *
     * @param character Character to add XP to
     * @param amount Amount of XP to add to the character
     */
    static void GainXP(Character* character, float amount);

    /**
     * @brief Function to directly level up a character. Sets character XP to 0
     *
     * @param character Character to level up
     */
    static void LevelUp(Character* character);

    /**
     * @brief Function to get the level of a character in the LevelUpSystem
     *
     * @param character Character to get level of
     * @return int The level of the character
     */
    static int GetLevel(Character* character);

    /**
     * @brief Function to get a HP modifier that is calculated from the level of the character. Used to buff character when leveling up.
     *
     * @param character Character to get HP modifier of
     * @return float The HP modifierr of the character
     */
    static float GetHPModifier(Character* character);

    static std::unordered_map<Character*, LevelUpInstance> characterLevelMap;
};

#endif
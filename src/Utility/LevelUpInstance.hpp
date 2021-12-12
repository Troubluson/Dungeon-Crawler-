#pragma once

#ifndef _LevelUpInstance_CLASS_
#define _LevelUpInstance_CLASS_

class LevelUpInstance {
public:
    /**
     * @brief Construct a new Level Up Instance object, designed to only be used from the LevelUpSystem. Initializes level as 1, xp as 0 and xpNeededForLevelUp as 20.
     *
     */
    LevelUpInstance();

    /**
     * @brief Function to Add xp to this LevelUpInstace
     *
     * @param amount Ammount to of XP add
     */
    void GainXP(float amount);

    /**
     * @brief Functio to Directly level up this LevelUpInstance
     *
     */
    void LevelUp();

    /**
     * @brief Function to get the level of this LevelUpInstance
     *
     * @return int The level of this LevelUpInstance
     */
    int GetLevel() { return level; }

    /**
     * @brief Function to get HP modifier of this LevelUpInstance
     *
     * @return float HP modifier of this LevelUpInstance
     */
    float GetHPModifier();

private:
    int level;
    float xp;
    float xpNeededForLevelUp;
};

#endif
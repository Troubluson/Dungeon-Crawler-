#include "LevelUpSystem.hpp"

std::unordered_map<Character*, LevelUpInstance> LevelUpSystem::characterLevelMap;

void LevelUpSystem::AddCharacter(Character* character)
{
    if (characterLevelMap.find(character) != characterLevelMap.end()) {
        return;
    }

    LevelUpInstance levelUpInstance = LevelUpInstance();
    characterLevelMap[character] = levelUpInstance;
}

void LevelUpSystem::GainXP(Character* character, float amount)
{
    if (characterLevelMap.find(character) == characterLevelMap.end()) {
        return;
    }

    characterLevelMap[character].GainXP(amount);
}

void LevelUpSystem::LevelUp(Character* character)
{
    characterLevelMap[character].LevelUp();
}

int LevelUpSystem::GetLevel(Character* character)
{
    if (characterLevelMap.find(character) == characterLevelMap.end()) {
        return -1;
    }

    return characterLevelMap[character].GetLevel();
}

float LevelUpSystem::GetHPModifier(Character* character)
{
    if (characterLevelMap.find(character) == characterLevelMap.end()) {
        return 1.0f;
    }

    return characterLevelMap[character].GetHPModifier();
}
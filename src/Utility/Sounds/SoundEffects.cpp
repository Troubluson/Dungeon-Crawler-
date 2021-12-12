#include "SoundEffects.hpp"

SoundEffect::SoundEffect(const std::string& SoundEffectFilename)
{
    if (!buffer.loadFromFile(SoundEffectFilename)) {
        ;
    } else {
        effect.setBuffer(buffer);
    }
}

void SoundEffect::PlaySound()
{
    effect.play();
}

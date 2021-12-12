#ifndef _SOUND_EFFECT_
#define _SOUND_EFFECT_

class SoundEffect {
public:
    SoundEffect(const std::string& SoundEffectFilename);
    ~SoundEffect() { }
    void PlaySound();

private:
    sf::SoundBuffer buffer;
    sf::Sound effect;
};

#endif
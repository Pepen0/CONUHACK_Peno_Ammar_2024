#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include <string>

class AudioManager
{
public:
    void playSound(const std::string &soundId);
    void playMusic(const std::string &musicId);
    // Add functions to load and manage sounds if necessary
};

#endif // AUDIO_MANAGER_H

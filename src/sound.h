#ifndef SOUND_H
#define SOUND_H

#include "SDL.h"
#include "SDL2/SDL_mixer.h"

class Sound{
    public:
        Sound();
        bool loadSound();    
    
    private:
        //The music that will be played
        Mix_Music *gMusic = nullptr;

        //The sound effects that will be used
        Mix_Chunk *burp;
        Mix_Chunk *scream;
        Mix_Chunk *eat;
};

#endif
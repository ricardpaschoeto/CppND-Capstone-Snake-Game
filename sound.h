#ifndef SOUND_H
#define SOUND_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

class Sound{
    public:
        Sound();
        ~Sound();
        bool loadSound();    

        //The music that will be played
        Mix_Music *gMusic = nullptr;

        //The sound effects that will be used
        Mix_Chunk *burp;
        Mix_Chunk *scream;
        Mix_Chunk *eat;   

};

#endif
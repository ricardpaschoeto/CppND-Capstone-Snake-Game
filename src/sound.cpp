#include "sound.h"
#include <stdio.h>
#include <string>
#include <iostream>

Sound::Sound(){

    //Initialize SDL
    if(SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0){
        std::cerr << "SDL Audio could not initialize.\n";
        std::cerr << "SDL_Audio Error: " << SDL_GetError() << "\n";
    }

     //Initialize SDL_mixer
     if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 1, 1024) < 0){
        std::cerr << "SDL Mixer could not initialize.\n";
        std::cerr << "SDL_Mixer Error: " << SDL_GetError() << "\n";         
    }
}

Sound::~Sound(){
    //Free the sound effects
    Mix_FreeChunk( burp );
    Mix_FreeChunk( scream );
    Mix_FreeChunk( eat );

    burp = nullptr;
    scream = nullptr;
    eat = nullptr;
    
    //Free the music
    Mix_FreeMusic( gMusic );
    gMusic = nullptr;

    Mix_Quit();
}

bool Sound::loadSound(){

    bool success = true;

    gMusic = Mix_LoadMUS("../build/music.wav");
    if( gMusic == nullptr )
    {
        std::cout << "Failed to load scratch sound effect! SDL_mixer Error: " << Mix_GetError() << std::endl;
        success = false;
    }
    
    burp = Mix_LoadWAV( "../build/burp.wav" );
    if( burp == nullptr )
    {
        std::cout << "Failed to load scratch sound effect! SDL_mixer Error: " << Mix_GetError() << std::endl;
        success = false;
    }

    scream = Mix_LoadWAV( "../build/scream.wav" );
    if( scream == NULL )
    {
        std::cout << "Failed to load scratch sound effect! SDL_mixer Error: " << Mix_GetError() << std::endl;
        success = false;
    }

    eat = Mix_LoadWAV( "../build/bite.wav" );
    if( eat == NULL )
    {
        std::cout << "Failed to load scratch sound effect! SDL_mixer Error: " << Mix_GetError() << std::endl;
        success = false;
    }

    return success;
}
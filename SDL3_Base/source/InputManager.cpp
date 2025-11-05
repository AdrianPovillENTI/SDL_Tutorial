#include "InputManager.h"

bool InputManager::Listen()
{
    for (std::unordered_map<Sint32, KeyState>::iterator it = _keyReference.begin();
        it != _keyReference.end();
        it++)
    {
        if (it->second == DOWN)
        {
            it->second = HOLD;
        }
        else if (it->second == UP)
        {
            it-> second = RELEASED;
        }
    }

    SDL_GetMouseState(&_mouseX, &_mouseY);

    SDL_Event event;

    while(SDL_PollEvent (&event))
    {
         // Retornar true per acabar l'execució del programa
        if (event.type == SDL_EVENT_QUIT)
        return true;
        
        // Si s'ha fet clic
        else if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
        {
        // Si el botó és l'esquerre
            if (event.button.button == SDL_BUTTON_LEFT)
            _leftClick = true;
        }
        
        // Si s'ha deixat de fer clic
        else if (event.type == SDL_EVENT_MOUSE_BUTTON_UP)
        {
        if (event.button.button == SDL_BUTTON_LEFT)
            _leftClick = false;
        }
        
        // Si s'ha començat a prémer una tecla ...
        else if (event.type == SDL_EVENT_KEY_DOWN)
        {
        // ... i no s'està aguantant ja la tecla
            if (_keyReference[event.key.key] != HOLD)
            _keyReference[event.key.key] = DOWN;
        }
        // Si s'ha deixat de prémer una tecla ...
        else if (event.type == SDL_EVENT_KEY_UP)
        {
            _keyReference[event.key.key] = UP;
        }        
    }    
        // Retornar false per seguir amb l'execució del programa
         return false;
}

bool InputManager::GetEvent(Sint32 input, KeyState inputValue)
{
    return _keyReference[input] == inputValue;
}
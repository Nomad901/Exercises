#include <iostream>
#include <unordered_map>

#include "SDL3_gfxPrimitives.h"
#include "SDL3/SDL.h"
#include "glm/glm.hpp"

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

//
// actually player pos - this is our mouse for now; 
//
bool isInsideOfCircle(glm::vec2 pPosCircle, glm::vec2 pPlayerPos, float pRadiusCircle)
{
    float distanceToPlayer = glm::length(pPlayerPos - pPosCircle);
    return distanceToPlayer <= pRadiusCircle;

    /*
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        if(isInsideOfCircle(glm::vec2(WIN_WIDTH / 2, WIN_HEIGHT / 2), mousePos, radiusCircle))
            circleRGBA(renderer, WIN_WIDTH / 2, WIN_HEIGHT / 2, radiusCircle, 0, 255, 100, 255);
        else 
            circleRGBA(renderer, WIN_WIDTH / 2, WIN_HEIGHT / 2, radiusCircle, 255, 0, 100, 255);
    */

}

void bouncingLaser()
{

}

void collideSystem(const SDL_FRect& pWall, )
{

}

int main(int argc, char* argv[])
{
    SDL_Window* window = SDL_CreateWindow("Window", WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    SDL_FRect rayCastZoneUP{     (float)WIN_WIDTH / 2.0f - 300.0f,  500.0f, 600.0f, 600.0f };
    SDL_FRect rayCastZoneBOTTOM{ (float)WIN_WIDTH / 2.0f - 300.0f, -500.0f, 600.0f, 600.0f };
    SDL_FRect rayCastZoneRIGHT{  (float)WIN_WIDTH / 2.0f + 400.0f, (float)WIN_HEIGHT / 2.0f - 360.0f, 600.0f, WIN_HEIGHT };
    SDL_FRect rayCastZoneLEFT{   (float)WIN_WIDTH / 2.0f - 1000.0f, (float)WIN_HEIGHT / 2.0f - 360.0f, 600.0f, WIN_HEIGHT };

    glm::vec2 mousePos;
    glm::vec2 circlePos = glm::vec2(WIN_WIDTH / 2, WIN_HEIGHT / 2);

    std::unordered_map<SDL_Keycode, bool> keyCodes;
    bool active{ true };
    while (active)
    {
        SDL_GetMouseState(&mousePos.x, &mousePos.y);
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT ||
                event.key.key == SDLK_ESCAPE)
            {
                active = false;
                break;
            }
            if (event.type == SDL_EVENT_KEY_DOWN)
                keyCodes[event.key.key] = true;
            if (event.type == SDL_EVENT_KEY_UP)
                keyCodes[event.key.key] = false;
        }

        float speed = 0.1f;
        if (keyCodes[SDLK_W])
            circlePos.y -= speed;
        if (keyCodes[SDLK_S])
            circlePos.y += speed;
        if (keyCodes[SDLK_A])
            circlePos.x -= speed;
        if (keyCodes[SDLK_D])
            circlePos.x += speed;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        SDL_RenderRect(renderer, &rayCastZoneUP);
        SDL_RenderRect(renderer, &rayCastZoneBOTTOM);
        SDL_RenderRect(renderer, &rayCastZoneRIGHT);
        SDL_RenderRect(renderer, &rayCastZoneLEFT);

        circleRGBA(renderer, circlePos.x, circlePos.y, 10, 255, 255, 255, 255);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}

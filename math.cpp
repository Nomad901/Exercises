/*
    MATH ASSIGNMENTS FROM TUTORIALS: https://www.youtube.com/live/fjOdtSu4Lm4?si=qPGbn51_b2DFheQF / Freya Holmér
*/
#include <iostream>
#include <format>
#include <unordered_map>
#include <random>
#include <expected>
#include <algorithm>

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/glm.hpp"
#include "glm/gtx/rotate_vector.hpp"

#include "SDL3_gfxPrimitives.h"
#include "SDL3/SDL.h"
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"

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

class Walls
{
public:
    Walls(uint32_t pNumberWalls)
    {
        std::random_device radomDevice;
        std::mt19937 mt{ radomDevice() };
        std::uniform_int_distribution<uint32_t> genX{ 0, WIN_WIDTH  };
        std::uniform_int_distribution<uint32_t> genY{ 0, WIN_HEIGHT };

        mWallsPos.reserve(pNumberWalls);
        for (size_t i = 0; i < pNumberWalls; ++i)
        {
            uint32_t xValue1 = genX(mt);
            uint32_t yValue1 = genY(mt);
            uint32_t xValue2 = genX(mt);
            uint32_t yValue2 = genY(mt);
        
            std::pair<glm::vec2, glm::vec2> pair;
            pair = std::make_pair(glm::vec2(xValue1, yValue1), glm::vec2(xValue2, yValue2));
            mWallsPos.push_back(pair);
        }
    }

    auto render(SDL_Renderer* pRenderer) -> void
    {
        for (auto& [beginPos, endPos] : mWallsPos)
        {
            SDL_RenderLine(pRenderer, beginPos.x, beginPos.y, endPos.x, endPos.y);
        }
    }
    auto getWallsStorage() noexcept -> std::vector<std::pair<glm::vec2, glm::vec2>>&
    {
        return mWallsPos;
    }

private:
    std::vector<std::pair<glm::vec2, glm::vec2>> mWallsPos;
};

class BounceLasers
{
public:
    BounceLasers(uint32_t pNumber)
        : mNumberLasers(pNumber),
          mCharPos{ 0.0f,0.0f },
          mRayEndPos{ 0.0f, 0.0f }
    {}
    
    inline void setNumberLasers(uint32_t pNumber) { mNumberLasers = pNumber; }

    inline void update(const std::vector<std::pair<glm::vec2, glm::vec2>>& pWalls,
                       const glm::vec2& pCharPos, const glm::vec2& pEndRayPos)  
    {
        mCharPos = pCharPos;
        mRayEndPos = pEndRayPos;
        mWalls = pWalls;
    }
    inline void render(SDL_Renderer* pRenderer)
    {

    }
    inline void renderCursorLaser(SDL_Renderer* pRenderer)
    {
        auto points = rayIsCollided();
        if (points.has_value())
        {
            glm::vec2 posPoint = points.value().first;
            auto wallPos = points.value().second;

            SDL_RenderLine(pRenderer, mCharPos.x, mCharPos.y, posPoint.x, posPoint.y);
            auto normals = calculateNormals(wallPos.first, wallPos.second);
            SDL_RenderLine(pRenderer, posPoint.x, posPoint.y, posPoint.x + normals.second.x * 50.0f, posPoint.y + normals.second.y * 50.0f);

            glm::vec2 normDirection = glm::normalize(posPoint - mCharPos);

            float dotProduct = glm::dot(normDirection, normals.second);
            glm::vec2 reflectedVector = normDirection - 2.0f * dotProduct * normals.second;
            
            glm::vec2 reflectedEnd = posPoint + reflectedVector * glm::length(posPoint - mCharPos);
            SDL_RenderLine(pRenderer, posPoint.x, posPoint.y, reflectedEnd.x, reflectedEnd.y);
            
        }
    }
    
private:
    auto rayIsCollided() -> std::expected<std::pair<glm::vec2, std::pair<glm::vec2, glm::vec2>>, bool>
    {
        float minDistance = std::numeric_limits<float>::max();
        std::pair<glm::vec2, std::pair<glm::vec2, glm::vec2>> closestPoint;
        bool foundCollision = false;

        for (auto& i : mWalls)
        {
            const float x1 = i.first.x;
            const float y1 = i.first.y;
            const float x2 = i.second.x;
            const float y2 = i.second.y;

            const float x3 = mCharPos.x;
            const float y3 = mCharPos.y;
            const float x4 = mRayEndPos.x;
            const float y4 = mRayEndPos.y;

            float den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
            if (den == 0)
                continue;

            float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
            float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;
            if (t > 0 && t < 1 && u > 0)
            {
                glm::vec2 pointVctr = glm::vec2(x1 + t * (x2 - x1),
                                                y1 + t * (y2 - y1));
                float distance = glm::length(pointVctr - mCharPos);
                if (distance < minDistance)
                {
                    minDistance = distance;
                    closestPoint = std::make_pair(pointVctr, std::make_pair(i.first, i.second));
                    foundCollision = true;
                }
            } 
        }
        if (!foundCollision)
            return std::unexpected(false);

        return closestPoint;
    }

    std::pair<glm::vec2, glm::vec2> calculateNormals(glm::vec2 pBeginning, glm::vec2 pEnd)
    {
        glm::vec2 direction = pEnd - pBeginning;
        glm::vec2 normal1 = glm::normalize(glm::vec2(-direction.y, direction.x));
        glm::vec2 normal2 = glm::normalize(glm::vec2(direction.y, -direction.x));

        return std::make_pair(normal1, normal2);
    }

private:
    uint32_t mNumberLasers;
    glm::vec2 mCharPos;
    glm::vec2 mRayEndPos;
    std::vector<std::pair<glm::vec2, glm::vec2>> mWalls;
};


int main(int argc, char* argv[])
{
    SDL_Window* window = SDL_CreateWindow("Window", WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    glm::vec2 mousePos;
    glm::vec2 circlePos = glm::vec2(WIN_WIDTH / 2, WIN_HEIGHT / 2);
    BounceLasers lasers(2);
    Walls walls(5);

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

        walls.render(renderer);

        lasers.update(walls.getWallsStorage(), circlePos, mousePos);
        lasers.renderCursorLaser(renderer);

        circleRGBA(renderer, circlePos.x, circlePos.y, 10, 255, 255, 255, 255);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}

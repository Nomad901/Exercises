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

class Walls
{
public:
    Walls(uint32_t pNumberWalls)
    {
        std::random_device radomDevice;
        std::mt19937 mt{ radomDevice() };
        std::uniform_int_distribution<uint32_t> genX{ 0, WIN_WIDTH };
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
    {
    }

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
        renderBounce(pRenderer, mCharPos, mRayEndPos, mNumberLasers);
    }

private:
    void renderBounce(SDL_Renderer* pRenderer, glm::vec2 pBegin, glm::vec2 pEnd, int32_t pNumberBounces)
    {
        if (pNumberBounces <= 0)
            return;

        auto points = rayIsCollided(pBegin, pEnd);
        if (points.has_value())
        {
            glm::vec2 posPoint = points.value().first;
            auto wallPos = points.value().second;

            SDL_RenderLine(pRenderer, pBegin.x, pBegin.y, posPoint.x, posPoint.y);
            auto normals = calculateNormals(wallPos.first, wallPos.second);

            glm::vec2 normDirection = glm::normalize(posPoint - pBegin);

            float dotProduct = glm::dot(normDirection, normals.second);
            glm::vec2 reflectedVector = normDirection - 2.0f * dotProduct * normals.second;

            glm::vec2 reflectedEnd = posPoint + reflectedVector * 1000.0f;
            renderBounce(pRenderer, posPoint, reflectedEnd, pNumberBounces - 1);
        }
    }

    auto rayIsCollided(glm::vec2 pBegin, glm::vec2 pEnd) -> std::expected<std::pair<glm::vec2, std::pair<glm::vec2, glm::vec2>>, bool>
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
            
            const float x3 = pBegin.x;
            const float y3 = pBegin.y;
            const float x4 = pEnd.x;
            const float y4 = pEnd.y;

            float den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
            if (den == 0)
                continue;

            float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
            float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;
            if (t > 0 && t < 1 && u > 0)
            {
                glm::vec2 pointVctr = glm::vec2(x1 + t * (x2 - x1),
                    y1 + t * (y2 - y1));
                float distance = glm::length(pointVctr - pBegin);
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

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();

    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.IniFilename = NULL;

    ImGui::StyleColorsDark();
    ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer3_Init(renderer);

    glm::vec2 mousePos;
    glm::vec2 circlePos = glm::vec2(WIN_WIDTH / 2, WIN_HEIGHT / 2);
    BounceLasers lasers(5);
    Walls walls(5);

    std::unordered_map<SDL_Keycode, bool> keyCodes;
    bool active{ true };
    while (active)
    {
        SDL_GetMouseState(&mousePos.x, &mousePos.y);
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL3_ProcessEvent(&event);

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
        ImGui_ImplSDL3_NewFrame();
        ImGui_ImplSDLRenderer3_NewFrame();
        ImGui::NewFrame();

        static bool firstTime = true;
        if (firstTime)
        {
            ImGui::SetNextWindowPos({ 0,0 });
            ImGui::SetNextWindowSize({ 250,60 });
            firstTime = false;
        }
        ImGui::Begin("Control rays", &active);

        static int32_t numberRays = 1;
        if (ImGui::SliderInt("NumberRays", &numberRays, 1, 50))
            lasers.setNumberLasers(numberRays);

        ImGui::End();

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
        lasers.render(renderer);

        circleRGBA(renderer, circlePos.x, circlePos.y, 10, 255, 255, 255, 255);

        ImGui::Render();
        ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);

        SDL_RenderPresent(renderer);
    }

    ImGui_ImplSDL3_Shutdown();
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui::DestroyContext();
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}

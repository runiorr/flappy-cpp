#pragma once

#include "raylib.h"
#include "renderer.hpp"

class RaylibRenderer : public Renderer {
public:
  void Init(int width, int height) override {
    InitWindow(width, height, "Game");
    InitAudioDevice();
  }

  void Clear() override {
    BeginDrawing();
    ClearBackground(RAYWHITE);
  }

  void Draw() override {
    // Your drawing logic
    EndDrawing();
  }

  void Close() override {
    CloseAudioDevice();
    CloseWindow();
  }
};
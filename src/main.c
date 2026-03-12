#include "board.h"
#include "raylib.h"
#include <stdio.h>

int main(void) {
  // Initiliazing
  const int screenWidth = 800;
  const int screenHeight = 800;

  InitWindow(screenHeight, screenHeight, "Othello");

  float rotation = 0.0f;
  SetTargetFPS(60);
  setup_board_logic();

  while (!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(RAYWHITE);
      setup_board_graphics();
      handle_mouse_click();
    EndDrawing();
  }

  CloseWindow();

  return 0;
}

#include "board.h"
#include <stdio.h>
#include "raylib.h"

int playerTurn = 0;

void setup_board_logic(void) {
    for(int row=0; row<8; row++) {
        for(int col=0; col<8; col++) {
            board[row][col] = E;
        }
    }
    board[3][3] = B;
    board[3][4] = W;
    board[4][3] = W;
    board[4][4] = B;
}

void setup_board_graphics(void) {
    for(int row=0; row<8; row++) {
        for(int col=0; col<8; col++) {
            Rectangle rect = {row*100, col*100, 100, 100, GREEN};
            DrawRectangleRec(rect, DARKGREEN);
            DrawRectangleLinesEx(rect, 5, WHITE);
            if(board[row][col] == B) {
                DrawCircle(row*100+50, col*100+50, 35, BLACK);
            } else if(board[row][col] == W) {
               DrawCircle(row*100+50, col*100+50, 35, WHITE);
            }
        }
     }
}

void handle_mouse_click(void) {
     if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePosition = GetMousePosition();
        int row = mousePosition.x/100;
        int col = mousePosition.y/100;

        if(playerTurn == 0) {
            board[row][col] = W;
            playerTurn =1 ;
        } else {
            board[row][col] = B;
            playerTurn = 0;
        }
     }
}
#include "board.h"
#include <stdio.h>
#include "raylib.h"

void setup_board_logic() {
    for(int row=0; row<8; row++) {
        for(int col=0; col<8; col++) {
            board[row][col] = E;
        }
    }
    // board[4][4] = B;
}

void setup_board_graphics() {
    for(int row=0; row<8; row++) {
        for(int col=0; col<8; col++) {
            Rectangle rect = {row*100, col*100, 100, 100, GREEN};
            DrawRectangleRec(rect, DARKGREEN);
            DrawRectangleLinesEx(rect, 5, WHITE);

            // if(board[row][col]!=E) {
            //     printf("not empty");
            //     DrawCircle(row*100+50, col*100+50, 30, BLACK);
            // }
        }
     }
}
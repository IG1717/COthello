#include "board.h"
#include <stdio.h>
#include "raylib.h"
#include <inttypes.h>

int playerTurn = 0;
void print_board(uint64_t board);
int convert_row_col_to_pos(int row, int col);
void convert_pos_to_row_col(int x, int* pos);


void setup_board_logic() {
    black_squares = 0;
    white_squares = 0;

    int position = convert_row_col_to_pos(2,2);

    white_squares |= (1 << position);

    //print_board(white_squares);
    //print_board(black_squares);
}




void setup_board_graphics(void) {

    for(int i=0; i<64; i++) {
        uint64_t curr_white = (white_squares >> i) & 1;
        uint64_t curr_black = (black_squares >> i) & 1;

        int pos[2];
        convert_pos_to_row_col(i, pos);
        int row = pos[0];
        int col = pos[1];

        Rectangle rect = {row*100, col*100, 100, 100, GREEN};
        DrawRectangleRec(rect, DARKGREEN);
        DrawRectangleLinesEx(rect, 5, WHITE);

        if(curr_white == 1) {
            DrawCircle(row*100+50, col*100+50, 35, WHITE);
        } else if(curr_black == 1) {
            DrawCircle(row*100+50, col*100+50, 35, BLACK);
        }

        if((i+1)%8 ==0) {
            printf("\n");
        }
    }
}

void handle_mouse_click(void) {
     if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePosition = GetMousePosition();
        int row = mousePosition.x/100;
        int col = mousePosition.y/100;
         int position = convert_row_col_to_pos(row, col);
        if(playerTurn == 0) {
            white_squares |= (1ULL << position);
            playerTurn =1 ;
        } else {
            black_squares |= (1ULL << position);
            playerTurn = 0;
        }
     }
}

void print_board(uint64_t board) {
    for(int i=0; i<64; i++) {
        uint64_t curr_bit = (board >> i) & 1;
        if(curr_bit == 1) {
            printf(" 1 ");
        } else {
            printf(" 0 ");
        }

        if((i+1)%8 ==0) {
            printf("\n");
        }
    }
}

int convert_row_col_to_pos(int r, int c) {
    return c + (8*r);
}

void convert_pos_to_row_col(int x, int* pos) {
    int row = x/8;
    int col = x%8;
    pos[0] = row;
    pos[1] = col;
}
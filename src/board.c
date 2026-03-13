#include "board.h"
#include <stdio.h>
#include "raylib.h"
#include <inttypes.h>

int playerTurn = 0;
void print_board(uint64_t board);
int convert_row_col_to_pos(int row, int col);
void convert_pos_to_row_col(int x, int* pos);
bool check_square_valid(int row, int col, int player);
bool is_square_filled(int pos);


void setup_board_logic() {
    black_squares = 0;
    white_squares = 0;

    int b1 = convert_row_col_to_pos(3,3);
    int w1 = convert_row_col_to_pos(3,4);
    int w2 = convert_row_col_to_pos(4,3);
    int b2 = convert_row_col_to_pos(4,4);

    uint64_t black_mask = (1ULL << b1) | (1ULL << b2);
    black_squares |= black_mask;
    uint64_t white_mask = (1ULL << w1) | (1ULL << w2);
    white_squares |= white_mask;
    //white_squares |= (1 << w2);
    //black_squares |= (1 << b2);

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

        Rectangle rect = {row*SQUARE_SIZE, col*SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, GREEN};
        DrawRectangleRec(rect, DARKGREEN);
        DrawRectangleLinesEx(rect, 5, WHITE);

        if(curr_white == 1) {
            DrawCircle(row*SQUARE_SIZE+SQUARE_SIZE/2, col*SQUARE_SIZE+SQUARE_SIZE/2, 35, WHITE);
        } else if(curr_black == 1) {
            DrawCircle(row*SQUARE_SIZE+50, col*SQUARE_SIZE+50, 35, BLACK);
        }

        if((i+1)%8 ==0) {
            printf("\n");
        }
    }
}

void handle_mouse_click(void) {
     if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePosition = GetMousePosition();
        int row = mousePosition.x/SQUARE_SIZE;
        int col = mousePosition.y/SQUARE_SIZE;
        int position = convert_row_col_to_pos(row, col);
        if(!is_square_filled(position)) {
            if(playerTurn == 0) {
                white_squares |= (1ULL << position);
                playerTurn =1 ;
            } else {
                black_squares |= (1ULL << position);
                playerTurn = 0;
            }
        }
    }
}


bool check_square_valid(int row, int col, int color) {
    if(color == 1) {
        int neigbor = (white_squares >> 1) & black_squares;
         

    } else {

    }
}

bool check_neighbor() {
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

bool is_square_filled(int pos) {
    uint64_t total_board = white_squares^black_squares;
    if((total_board >> pos) & 1) {
        return true;
    }
    return false;
}
#include <stdint.h>

uint64_t black_squares;
uint64_t white_squares;

// Function that sets up the board logically
void setup_board_logic();

// Function that sets up the board graphically
void setup_board_graphics();

// Method to handle mouse click
void handle_mouse_click();

// 0 represents white, 1 represents black 
// TODO - delete if not used
extern int playerTurn;
// Enum that repesents the state of every square - E(EMPTY), W(WHITE), B(BLACK)
typedef enum square_status {
    E,
    W, 
    B
} square_status;

// 2-D Array which holds the entire board
square_status board[8][8];

// Function that sets up the board logically
void setup_board_logic();

// Function that sets up the board graphically
void setup_board_graphics();
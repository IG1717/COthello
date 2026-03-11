// Enum that repesents the state of every square - E(EMPTY), W(WHITE), B(BLACK)
typedef enum square_status {
    E,
    W, 
    B
} square_status;

// 2-D Array which holds the entire board
square_status board[8][8];

// Function that sets up the board 
void setup_board();
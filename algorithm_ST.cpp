#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../include/algorithm.h"

using namespace std;

/******************************************************
 * In your algorithm, you can just use the the funcitons
 * listed by TA to get the board information.(functions 
 * 1. ~ 4. are listed in next block)
 * 
 * The STL library functions is not allowed to use.
******************************************************/

/*************************************************************************
 * 1. int board.get_orbs_num(int row_index, int col_index)
 * 2. int board.get_capacity(int row_index, int col_index)
 * 3. char board.get_cell_color(int row_index, int col_index)
 * 4. void board.print_current_board(int row_index, int col_index, int round)
 * 
 * 1. The function that return the number of orbs in cell(row, col)
 * 2. The function that return the orb capacity of the cell(row, col)
 * 3. The function that return the color fo the cell(row, col)
 * 4. The function that print out the current board statement
*************************************************************************/

int explosion_orbs_lack(Board board, int i, int j)
{
    return board.get_capacity(i, j) - board.get_orbs_num(i, j);
}


void algorithm_A(Board board, Player player, int index[]){

    //////your algorithm design///////////

    int row = -1, col;
    int color = player.get_color();
    int surround_r[8] = {-1, -1, -1, 0, 0, 1, 1, 1};  
    int surround_c[8] = {-1, 0, 1, -1, 1, -1, 0 ,1};
    int s_row, s_col;
    int opponent_nearby;
    int max_opp_near = 0;
    int capacity, min_capacity;

    for (int i = 0; i < 5; i++) {                                                                   // whole board
        for (int j = 0; j < 6; j++) {
            if (board.get_cell_color(i, j) == color || board.get_cell_color(i, j) == 'w') {         // legal place
                opponent_nearby = 0;
                for (int k = 0; k < 8; k++) {                                                       // check surrounding
                    s_row = i + surround_r[k];
                    s_col = j + surround_c[k];
                    if (s_row >= 0 && s_row <= 4 && s_col >= 0 && s_col <= 5) {                     // inside the board
                        if (board.get_cell_color(s_row, s_col) != color && board.get_cell_color(s_row, s_col) != 'w') {     // opponent
                            if (explosion_orbs_lack(board, i, j) <= explosion_orbs_lack(board, s_row, s_col)) {             // explode earlier than opponent
                                opponent_nearby++;
                            }
                        }
                    }
                }
                if (opponent_nearby > max_opp_near) {                                                // choose best position
                    max_opp_near = opponent_nearby;
                    row = i;
                    col = j;
                } else if (opponent_nearby == max_opp_near && opponent_nearby != 0) {
                    if (explosion_orbs_lack(board, i, j) < explosion_orbs_lack(board, row, col)) {
                        row = i;
                        col = j;
                    }
                }
            }
        }
    }
    // no such position, find the position that needs fewest orbs to explode
    if (row == -1) {
        min_capacity = 9;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 5; j++) {
                if (board.get_cell_color(i, j) == color || board.get_cell_color(i, j) == 'w') {
                    capacity = board.get_capacity(i, j);
                    if (capacity < min_capacity) {
                        min_capacity = capacity;
                        row = i;
                        col = j;
                    }
                }
            }
        }
    }

    index[0] = row;
    index[1] = col;

    return;
}
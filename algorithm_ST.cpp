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


void algorithm_A(Board board, Player player, int index[]){

    //////your algorithm design///////////

    int row, col;
    int color = player.get_color();
    int surround_r[8] = {-1, -1, -1, 0, 0, 1, 1, 1};  
    int surround_c[8] = {-1, 0, 1, -1, 1, -1, 0 ,1};
    int s_row, s_col;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            if (board.get_cell_color(i, j) == color || board.get_cell_color(i, j) == 'w') {
                for (int k = 0; k < 8; k++) {
                    s_row = i + surround_r[k];
                    s_col = j + surround_c[k];
                    if (s_row >= 0 && s_row <= 4 && s_col >= 0 && s_col <= 5) {
                        // explode earlier than opponent
                        //find the best position (there are opponent's orbs at the surrounding)
                    }
                }
                
            }
        }
    }
    
    // no such position, find the position that needs fewest orbs to explode

    index[0] = row;
    index[1] = col;

    return;
}
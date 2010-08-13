/*
 * Tictactoe: or noughts and crosses, human vs. computer game.
 *
 * Copyright (C) 2010 Dani Soufi <danisoufi@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.

 * This runs the game's mechanism
 */
#include <stdio.h>
#include "include/libttt.h"

int main(void)
{

     /* X & Y cell positions */
     int x, y;

     /* Syntax correctness */
     int valid_input = TRUE;

     /* Rounds played sofar */
     int round = 0;

     /* Game is played */
     char game_over = FALSE;

     /* Winner is not decided at the game start */
     char winner = NONE;

     /* Player 1 always starts the game */
     char currnt_player = PLAYER1;

     /* Game board */
     char board[NUM_ROWS][NUM_COLS];

     /* Initialize the game field */
     for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
           board[i][j] = ' ';
        }
     }

     while (!game_over) {

        simulate(board);
        /* The human player should choose his best move */
        if (currnt_player == PLAYER1) {
           printf("Enter moves as \"<row> <col>\" (no quotes)\n");
           do {
                 valid_input = TRUE;
                 printf("%c\'s move: ", PLAYER1);
                 fflush(stdout);
                 scanf("%d %d", &x, &y);
                 if ((x > 0 && x < NUM_ROWS + 1) && (y > 0 && y < NUM_COLS + 1)) {
                    if (!set_stone(board, currnt_player, (x - 1), (y - 1))) {
                       printf("Illegal move (already taken), try again\n");
                       valid_input = FALSE;
                    }
                 } else {
                    printf("Illegal move (off board), try again\n");
                    valid_input = FALSE;
                 }
           } while (valid_input == TRUE);
           currnt_player = player_next(currnt_player);
           game_over = game_ended(game_winner(board, currnt_player), round);
           ++round;
        } else {
           /* Compute computer's best move */
           computer_player2(board, currnt_player, round);
           game_over = game_ended(game_winner(board, currnt_player), round);
           ++round;
        }
     }

     winner = game_winner(board, currnt_player);
     /* Show the end game results in a nice way */
     if (winner == PLAYER1) {
        printf("TicTacToe! %c wins!\n", PLAYER1);
     } else if (winner == PLAYER2) {
        printf("TicTacToe! %c wins!\n", PLAYER2);
     } else {
        printf("Stalemate... nobody winned :(\n");
     }

     return 0;
}

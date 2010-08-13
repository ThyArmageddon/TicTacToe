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
#include "include/libttt.h"

void main(void)
{

     int c;
     int x, y;
     int valid_input = TRUE;
     int round = 0;                              // Played rounds
     char player1 = 'X';                         // 1st player's symbol
     char player2 = 'O';                         // 2nd player's symbol
     char currnt_player = player1;              // 1st player starts always
     char game_field[NUM_ROWS][NUM_COLS];        // Play field

     /**
      * Initialize the game field
      */
     for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
           game_field[i][j] = ' ';
        }
     }

     //while (!game_ended(game_winner(game_field, player1, player2), round)) {
     while () {

        simulate(game_field);

        /**
         * Read the human player's move
         */
        printf("Enter moves as \"<row> <col>\" (no quotes)\n");

        do {
              valid_input = TRUE;

              printf("%c\'s move: ", player1);
              fflush(stdout);
              scanf("%d %d", &x, &y);
              if ((x < 0 && x > NUM_ROWS) || (y < 0 && y > NUM_COLS)) {
                 printf("Illegal move (off board), try again\n");
                 valid_input = FALSE;
              } else if (!set_stone(game_field, player1, round, x, y)) {
                 printf("Illegal move (already taken), try again\n");
                 valid_input = FALSE;
              }
        } while (valid_input == TRUE);

        /**
         * Compute the computer's best move
         */
        computer_player2(game_field, player1, player2, round);
     }

     if (game_winner(game_field, player1, player2) == player1) {
        printf("TicTacToe! %c wins!\n", player1);
     } else if (game_winner(game_field, player1, player2) == player2) {
        printf("TicTacToe! %c wins!\n", player2);
     } else {
        printf("Stalemate... nobody winned :(\n");
     }

     return 0;
}

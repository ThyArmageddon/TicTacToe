/*
 * Tictactoe: or noughts and crosses, human vs. computer game.
 * main.c: Stub main program
 *
 * Copyright (C) 2010 Dani Soufi <danisoufi@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdio.h>
#include <stdbool.h>
#include "include/libttt.h"

int main(void)
{

     /* Rounds played sofar */
     int round = 0;

     /* Winner is not decided at the game start */
     char winner = NONE;

     /* Player 1 always starts the game */
     char currnt_player = PLAYER1;

     /* Game board */
     char board[NUM_ROWS][NUM_COLS];

     /* Initialize the game */
     for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
           board[i][j] = ' ';
        }
     }

     simulate(board);
     while (!game_ended(game_winner(board), round)) {

        /* The human player should choose his best move */
        if (currnt_player == PLAYER1) {
           human_turn(board, currnt_player, ++round);
           currnt_player = player_next(currnt_player);
        } else {
           /* Compute computer's best move */
           computer_turn(board, currnt_player, ++round);
           currnt_player = player_next(currnt_player);
        }
        simulate(board);
     }

     winner = game_winner(board);
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

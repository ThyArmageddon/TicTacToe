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
#include "include/stats.h"

int nrounds;

int main(void)
{
     /* Winner is not decided at the game start */
     char winner = NONE;

     /* Player 1 always starts the game */
     char currnt_player = PLAYER1;

     /* Game board */
     char board[NUM_ROWS][NUM_COLS];

     /* Game is played */
     bool ended = false;


     /* Initialize the game */
     for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
           board[i][j] = ' ';
        }
     }

     nrounds = 0;
     simulate(board);
     while (!ended) {
        /* The human player should choose his best move */
        if (currnt_player == PLAYER1) {
           human_turn(board, currnt_player);
        } else {
           /* Compute computer's best move */
           computer_turn(board, currnt_player);
        }
        currnt_player = player_next(currnt_player);
        simulate(board);
        winner = game_winner(board);
        ended = game_ended(winner);
        if (ended) {
           ++nreplays;
           if (winner == PLAYER1) {
              ++wplayer1;
           } else if (winner == PLAYER2) {
              ++wplayer2;
           } else {
              ++nstalemates;
           }
           rover_stats(winner);
           if (restart()) {
              main();
           } else {
              gover_stats();
           }
        }
     }
     return 0;
}

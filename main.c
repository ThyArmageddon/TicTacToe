/*
 * Tictactoe: or noughts and crosses
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
#include "include/level.h"

int nrounds;
char player1, player2;

int main(void)
{
     player1 = CROSS;
     player2 = NOUGHT;
     char winner;
     char currnt_player = player1;
     char board[NUM_ROWS][NUM_COLS];
     bool ended = false;
     int mode;


     nrounds = 0;
     mode = gmode();
     if (mode == 1) {
        set_diff();
     }
     while (!ended) {

        if (nrounds == 0) {
           for (int i = 0; i < NUM_ROWS; ++i) {
              for (int j = 0; j < NUM_COLS; ++j) {
                 board[i][j] = ' ';
              }
           }
           simulate(board);
        }
        if (mode == 1) {
           if (currnt_player == player1) {
              human_turn(board, currnt_player);
           } else {
              computer_turn(board, currnt_player);
           }
        } else {
           if (currnt_player == player1) {
              human_turn(board, currnt_player);
           } else {
              human_turn(board, currnt_player);
           }
        }

        currnt_player = player_next(currnt_player);
        simulate(board);
        winner = game_winner(board);
        ended = game_ended(winner);

        if (ended) {
           ++nreplays;
           if (winner == player1) {
              ++wplayer1;
           } else if (winner == player2) {
              ++wplayer2;
           } else {
              ++nstalemates;
           }
           rover_stats(winner);
           if (restart()) {
              if (winner == CROSS) {
                 if (player1 == CROSS) {
                    currnt_player = player1;
                 } else {
                    currnt_player = player2;
                 }
              } else if (winner == NOUGHT) {
                 if (player1 == NOUGHT) {
                    player1 = CROSS;
                    player2 = NOUGHT;
                    currnt_player = player1;
                 } else {
                    player1 = NOUGHT;
                    player2 = CROSS;
                    currnt_player = player2;
                 }
              } else {
                 if (player1 == CROSS) {
                    currnt_player = player1;
                 } else {
                    currnt_player = player2;
                 }
              }
              nrounds = 0;
              winner = NO_MATCH;
              ended = false;
           } else {
              gover_stats();
           }
        }
     }
     return 0;
}

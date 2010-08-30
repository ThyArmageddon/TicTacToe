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
#include "libttt.h"
#include "stats.h"
#include "difficulty.h"


int main(void)
{
     char player1 = CROSS;
     char player2 = NOUGHT;

     char winner;
     char currnt_player = player1;
     char board[NUM_ALL];
     char *br;
     bool ended = false;
     int nrounds = 0;
     int mode;

     int wplayer1 = 0;
     int wplayer2 = 0;
     int nreplays = 0;
     int nstalemates = 0;


     mode = select_mode();
     if (mode == 1) {
        set_diff();
     }
     while (!ended) {

        if (nrounds == 0) {
           for (int i = 0; i < NUM_ALL; ++i) {
              board[i] = ' ';
            }
            br = &board[0];
            simulate(br);
        }
        if (mode == 1) {
           if (currnt_player == player1) {
              human_turn(br, currnt_player, &nrounds);
           } else {
              computer_turn(br, player1, currnt_player, &nrounds);
           }
        } else {
           if (currnt_player == player1) {
              human_turn(br, currnt_player, &nrounds);
           } else {
              human_turn(br, currnt_player, &nrounds);
           }
        }

        currnt_player = player_next(currnt_player, player1, player2);
        simulate(br);
        winner = game_winner(br, player1, player2);
        ended = game_ended(winner, nrounds);

        if (ended) {
           ++nreplays;
           if (winner == player1) {
              ++wplayer1;
           } else if (winner == player2) {
              ++wplayer2;
           } else {
              ++nstalemates;
           }
           rover_stats(winner, player1, player2, wplayer1,
                       wplayer2, nreplays, nstalemates, mode);
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
              gover_stats(wplayer1, wplayer2, nreplays, nstalemates, mode);
           }
        }
     }
     return 0;
}

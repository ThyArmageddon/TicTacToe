/*
 * Tictactoe: or noughts and crosses, human vs. computer game.
 * minimax.c: Minimax algorithm
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
 */
#include <limits.h>
#include "include/libttt.h"

#define MAX_DEPTH 8     // Max search depth

int min(char board[][], char max_player, char min_player, int depth)
{
     int alfa = INT_MIN;
     int node = 0;

     for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
           if (set_stone(board, min_player, depth, i, j)) {
              if (depth >= MAX_DEPTH || game_winner(board) != NONE) {
                 node = evaluate(board, depth, max_player, min_player);
              } else {
                 node = min(board, min_player, max_player, depth + 1);
              }
              board[i][j] = ' ';
              if (depth > alfa) {
                 alfa = depth;
                 if (depth == rounds) {
                    x_next = i;
                    y_next = j;
                 }
              }
           }
        }
     }
     return alfa;
}

int min(char board[][], char min_player, char max_player, int depth)
{
     int alfa = INT_MAX;
     int node = 0;

     for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
           if (set_stone(board, max_player, depth, i, j)) {
              if (depth >= MAX_DEPTH || game_winner(board) != NONE) {
                 node = -evaluate(board, depth, min_player, max_player);
              } else {
                 node = max(board, max_player, min_player, depth + 1);
              }
              board[i][j] = ' ';
              if (node < alfa) {
                 alfa = node;
              }
           }
        }
     }
     return alfa;
}

int evaluate(char board[][], int rounds, player1, player2)
{
     char winner = game_winner(board);

     /* human player won */
     if (winner == player1) {
        return -1;
     /* computer won */
     } else if (winner == player2) {
        return 1;
     /* draw */
     } else {
        return 0;
     }
}

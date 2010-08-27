/*
 * Tictactoe: or noughts and crosses
 * minimax.c: The minimax algorithm
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
#include <limits.h>
#include "libttt.h"
#include "minimax.h"
#include "difficulty.h"

int mini(char *, char, char, int, int);
int evaluate(char *, char, char);

int position;

int max(char *br, char max_player, char min_player, int depth, int nrounds)
{
     int alfa = INT_MIN;
     int node = 0;

     for (int i = 0; i < NUM_ALL; ++i) {
        if (set_stone(br, min_player, i)) {
           if (depth >= max_depth || game_winner(br, max_player, min_player) != NO_MATCH) {
              node = evaluate(br, max_player, min_player);
           } else {
              node = mini(br, min_player, max_player, depth + 1, nrounds);
           }
           *(br + i) = ' ';
           if (node > alfa) {
              alfa = node;
              if (depth == nrounds) {
                 position = i;
              }
           }
        }
     }
     return alfa;
}

int mini(char *br, char min_player, char max_player, int depth, int nrounds)
{
     int alfa = INT_MAX;
     int node = 0;

     for (int i = 0; i < NUM_ALL; ++i) {
        if (set_stone(br, max_player, i)) {
           if (depth >= max_depth || game_winner(br, min_player, max_player) != NO_MATCH) {
              node = -evaluate(br, min_player, max_player);
           } else {
              node = max(br, max_player, min_player, depth + 1, nrounds);
           }
           *(br + i) = ' ';
           if (node < alfa) {
              alfa = node;
           }
        }
     }
     return alfa;
}

int evaluate(char *br, char player1, char player2)
{
     char winner = game_winner(br, player1, player2);

     if (winner == player1) {
        return -1;
     } else if (winner == player2) {
        return 1;
     } else {
        return 0;
     }
}

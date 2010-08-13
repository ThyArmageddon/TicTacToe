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
 */
#include <stdio.h>
#include "include/libttt.h"
#include "include/minimax.h"

/* Set the stone for the player if the choosen field is empty */
int set_stone(char board[][], char stone, int x, int y)
{
     if (field[x][y] == ' ') {
        field[x][y] = stone;
        return TRUE;
     } else {
        return FALSE;
     }
}

/* Switch players after each successfull round */
char player_next(char currnt_player)
{
     char next;

     if (current_player == PLAYER1) {
        next = PLAYER2;
     } else {
        next = PLAYER1;
     }
     return next;
}

/* Computer player */
void computer_player2(char board[][], char current, int round)
{
     max(board, PLAYER1, PLAYER2, round);
     set_stone(board, current, x_next, y_next);
}

/* Search for a winner */
char game_winner(char board[][], char currnt_player)
{
        /* Row */
        for (int x = 0; x < 3; ++x) {
           for (int i = 0; i < 3; ++i) {
              if (field[x][i] != currnt_player) {
                 break;
              } else if (i == 2) {
           	      return currnt_player;
              }
           }
        }

        /* Collumn */
        for (int y = 0; y < 3; ++y) {
           for (int i = 0; i < 3; ++i){
              if (field[i][y] != currnt_player) {
                 break;
              } else if (i == 2) {
                 return currnt_player;
              }
           }
        }

        /* Diagonal */
        for (int i = 0; i < 3; ++i) {
           if (field[i][i] != currnt_player) {
              break;
           } else if (i == 2) {
              return currnt_player;
           }
        }

        /* Anti-Diagonal */
        for (int i = 0; i < 3; ++i) {
           if (field[i][2 - i] != currnt_player) {
              break;
           } else if (i == 2) {
              return currnt_player;
           }
        }
     }
     return NONE;
}

/* Return the game status */
int game_ended(char winner, int round)
{
     if (winner == NONE && round < 9) {
        return FALSE;
     } else {
        return TRUE;
     }
}

/* Draw the game board */
void simulate(char board[][])
{
     for (int i = 0; i < NUM_ROWS; ++i) {
        if (i > 0) {
           printf(" |");
           for (int k = 0; k < 3; ++k) {
              if (k > 0) {
                 printf("+");
              }
              for (int l = 0; l < 3; ++l) {
                 printf("-");
              }
           }
           printf("|\n");
        } else {
           printf(" _ %d _ %d _ %d _\n", (i + 1), (i + 2), (i + 3));
        }
        printf("%d|", (i + 1));
        for (int j = 0; j < NUM_COLS; ++j) {
           if (j > 0) {
              printf("|");
           }
           printf(" %c ", board[i][j]);
        }
        printf("|\n");
     }
     printf(" -------------\n\n");
}

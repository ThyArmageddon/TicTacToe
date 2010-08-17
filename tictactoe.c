/*
 * Tictactoe: or noughts and crosses, human vs. computer game.
 * tictactoe.c: Game related functions
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
#include "include/minimax.h"

int tolower(int c);

bool set_stone(char board[NUM_ROWS][NUM_COLS], char stone, int x, int y)
{
     if (board[x][y] == ' ') {
        board[x][y] = stone;
        return true;
     } else {
        return false;
     }
}

char player_next(char currnt_player)
{
     char next;

     if (currnt_player == PLAYER1) {
        next = PLAYER2;
     } else {
        next = PLAYER1;
     }
     return next;
}

void human_turn(char board[NUM_ROWS][NUM_COLS], char current)
{
     int x, y;
     bool valid_input = true;

     printf("Enter moves as \"<row> <col>\" (no quotes)\n");
     do {
           valid_input = true;
           printf("%c\'s move: ", PLAYER1);
           fflush(stdout);
           if (scanf("%d %d", &x, &y) == 2) {
              if ((x > 0 && x < NUM_ROWS + 1) && (y > 0 && y < NUM_COLS + 1)) {
                 if (!set_stone(board, current, (x - 1), (y - 1))) {
                    printf("Illegal move (already taken), try again\n");
                    valid_input = false;
                 }
              } else {
                 printf("Illegal move (off board), try again\n");
                 valid_input = false;
              }
           }
     } while (valid_input != true);
     ++nrounds;
}

void computer_turn(char board[NUM_ROWS][NUM_COLS], char current)
{
     max(board, PLAYER1, current, nrounds);
     set_stone(board, current, xnext, ynext);
     ++nrounds;
}

char game_winner(char board[NUM_ROWS][NUM_COLS])
{
     char p[] = {PLAYER1, PLAYER2};

     for (int j = 0; j < 2; ++j) {

        /* Row */
        for (int x = 0; x < 3; ++x) {
           for (int i = 0; i < 3; ++i) {
              if (board[x][i] != p[j]) {
                 break;
              } else if (i == 2) {
      	         return p[j];
              }
           }
        }

        /* Collumn */
        for (int y = 0; y < 3; ++y) {
           for (int i = 0; i < 3; ++i){
              if (board[i][y] != p[j]) {
                 break;
              } else if (i == 2) {
                 return p[j];
              }
           }
        }

        /* Diagonal */
        for (int i = 0; i < 3; ++i) {
           if (board[i][i] != p[j]) {
              break;
           } else if (i == 2) {
              return p[j];
           }
        }

        /* Anti-Diagonal */
        for (int i = 0; i < 3; ++i) {
           if (board[i][2 - i] != p[j]) {
              break;
           } else if (i == 2) {
              return p[j];
           }
        }
     }
     return NONE;
}

bool game_ended(char winner)
{
     if (winner == NONE && nrounds <= 9) {
        return false;
     } else {
        return true;
     }
}

void simulate(char board[NUM_ROWS][NUM_COLS])
{
     printf("\n");
     for (int i = 0; i < NUM_ROWS; ++i) {
        if (i > 0) {
           for (int k = 0; k < NUM_COLS; ++k) {
              if (k > 0) {
                 printf("+");
              }
              for (int l = 0; l < NUM_ROWS + 2; ++l) {
                 printf("-");
              }
           }
           printf("\n");
        }
        for (int j = 0; j < NUM_COLS; ++j) {
           if (j > 0) {
              printf("|");
           }
           printf("  %c  ", board[i][j]);
        }
        printf("\n");
     }
     printf("\n");
}

bool restart(void)
{
     char c;

     printf("\nDo you want to play again? [Y\\N] ");
     fflush(stdout);
     if (scanf(" %c", &c) ==  1) {
        printf("\n");
        c = tolower(c);
        if (c == 'y') {
           return true;
        } else {
           return false;
        }
     } else {
        return false;
     }
    
}

int tolower(int c)
{
   if (c == 'N' || c == 'Y')
      return c + 'a' - 'A';
   else
      return c;
}

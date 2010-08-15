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

int xnext, ynext;

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

void human_turn(char board[NUM_ROWS][NUM_COLS], char current, int round)
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
}

void computer_turn(char board[NUM_ROWS][NUM_COLS], char current, int round)
{
     max(board, PLAYER1, current, round);
     set_stone(board, current, xnext, ynext);
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

bool game_ended(char winner, int round)
{
     if (winner == NONE && round < 9) {
        return false;
     } else {
        return true;
     }
}

void simulate(char board[NUM_ROWS][NUM_COLS])
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
